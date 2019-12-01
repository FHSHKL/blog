#include<windows.h>
#include<winsock2.h>
#include<iostream>
#include<string>
using namespace std;
void say(string data,const char *ip)
{
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET)
	{
        cout << "Socket error" << endl;
        return;
    }
    sockaddr_in sock_in;
    sock_in.sin_family = AF_INET;
    sock_in.sin_port = htons(8880);
    sock_in.sin_addr.S_un.S_addr = inet_addr(ip);
    if (connect(clientSocket, (sockaddr*)&sock_in, sizeof(sock_in) )== SOCKET_ERROR){
        cout << "Connect error" << endl;
        return;
    }
    send(clientSocket, data.c_str(), strlen(data.c_str()), 0);
    closesocket(clientSocket);
}
struct d
{
	const char *send_ip[50];
	int top;
	void in(const char *se)
	{
		for(int i=1;i<=top;i++)
		{
			if(*send_ip[i]==*se)
			{
				return;
			}
		}
		top++;
		send_ip[top]=se;
	}
	void out(int a)
	{
		swap(send_ip[a],send_ip[top]);
		top--;
	}
	void out(const char *a)
	{
		for(int i=1;i<=top;i++)
		{
			if(*send_ip[i]==*a)
			{
				out(i);
			}
		}
	}
	void send(string data)
	{
		for(int i=1;i<=top;i++)
		{
			say(data,send_ip[i]);
			return;
		}
	}
}see;
int main()
{

    //初始化DLL
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA wsdata;
    if (WSAStartup(sockVersion, &wsdata) != 0)
    {
        return 1;
    }

    //创建套接字
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET)
    {
        cout << "Socket error" << endl;
        return 1;
    }


    //绑定套接字
    sockaddr_in sockAddr;
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(8888);
    sockAddr.sin_addr.S_un.S_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR)
	{
        cout << "Bind error" << endl;
        return 1;
    }

    //开始监听
    if (listen(serverSocket, 10) == SOCKET_ERROR)
	{
        cout << "Listen error" << endl;
        return 1;
    }


    SOCKET clientSocket;
    sockaddr_in client_sin;
    char msg[100];//存储传送的消息
    int len = sizeof(client_sin);
    while (true)
	{
        clientSocket = accept(serverSocket, (sockaddr*)&client_sin, &len);
        if (clientSocket == INVALID_SOCKET)
		{
            cout << "Accept error" << endl;
            return 1;
        }
        int num = recv(clientSocket, msg, 100, 0);
        if (num > 0)
        {
            msg[num] = '\0';
            cout <<inet_ntoa(client_sin.sin_addr) <<":"<< msg << endl;
        }
        closesocket(clientSocket);
        see.in(inet_ntoa(client_sin.sin_addr));
        see.send(msg);
    }

    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
