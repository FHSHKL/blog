#include<winsock2.h>
#include<windows.h>
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int lsa;
void say(string data,const char *ip)
{
	lsa=0;
	for(int i=0;i<(int)(data.length());i++)
	{
		lsa^=data[i];
	}
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET)
	{
        cout << "Socket error" << endl;
        return;
    }
    sockaddr_in sock_in;
    sock_in.sin_family = AF_INET;
    sock_in.sin_port = htons(8888);
    sock_in.sin_addr.S_un.S_addr = inet_addr(ip);
    if (connect(clientSocket, (sockaddr*)&sock_in, sizeof(sock_in) )== SOCKET_ERROR){
        cout << "Connect error" << endl;
        return;
    }
    send(clientSocket, data.c_str(), strlen(data.c_str()), 0);
    closesocket(clientSocket);
}
DWORD WINAPI head(LPVOID lpParamter)
{
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET)
    {
        cout << "Socket error" << endl;
        return 0L;
    }

    sockaddr_in sockAddr;
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(8880);
    sockAddr.sin_addr.S_un.S_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR)
	{
        cout << "Bind error" << endl;
        return 0L;
    }

    //开始监听
    if (listen(serverSocket, 10) == SOCKET_ERROR)
	{
        cout << "Listen error" << endl;
        return 0L;
    }
	SOCKET clientSocket;
    sockaddr_in client_sin;
    char msg[100];//存储传送的消息
    int len = sizeof(client_sin);
	while(1)
	{
		clientSocket = accept(serverSocket, (sockaddr*)&client_sin, &len);
	    if (clientSocket == INVALID_SOCKET)
		{
	        cout << "Accept error" << endl;
	        return 0L;
	    }
	    int num = recv(clientSocket, msg, 100, 0);
	    if (num > 0)
	    {
	        msg[num] = '\0';
	        int len=strlen(msg);
	        int ans=0;
	        for(int i=0;i<len;i++)
	        {
	        	ans^=msg[i];
	        }
	        if((ans^lsa)!=0)
	        cout <<inet_ntoa(client_sin.sin_addr) <<":"<< msg << endl;
	    }
	    closesocket(clientSocket);
	    //say("copy that->",inet_ntoa(client_sin.sin_addr));
	}
}

int main()
{
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA data;
    if (WSAStartup(sockVersion, &data) != 0)
    {
        return 1;
    }
    printf("input ipv4 of server:");
	string ipv4;
	cin>>ipv4;
	printf("input your name:");
	string name;
	cin>>name;
	name+="->";
	CreateThread(NULL,0,head,NULL,0,NULL);
	
    while (true)
	{
		string ss;
		getline(cin,ss);
		say(name+ss,ipv4.c_str());
    }

    WSACleanup();

    return 0;
}
