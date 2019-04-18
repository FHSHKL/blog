#include<winsock2.h>
#include<windows.h>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<conio.h>
using namespace std;

WSADATA wsaData;
SOCKET sockServer;
SOCKADDR_IN addrServer;
SOCKET sockClient;
SOCKADDR_IN addrClient;

void init()
{
	WSAStartup(MAKEWORD(2,2),&wsaData);
    sockClient=socket(AF_INET,SOCK_STREAM,0);
    sockServer=socket(AF_INET,SOCK_STREAM,0);
}
void outit()
{
    WSACleanup();
}

void say(const char *ip,unsigned short dk,char *mes,int len)
{
	init();
	addrServer.sin_addr.S_un.S_addr=inet_addr(ip);
    addrServer.sin_family=AF_INET;
    addrServer.sin_port=htons(dk);
    connect(sockClient,(SOCKADDR*)&addrServer,sizeof(SOCKADDR));
    send(sockClient,mes,len+1,0);
    closesocket(sockClient);
    outit();
}
string message;
void recive(int dk)
{
	init();
	addrServer.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
    addrServer.sin_family=AF_INET;
    addrServer.sin_port=htons(dk);
    bind(sockServer,(SOCKADDR*)&addrServer,sizeof(SOCKADDR));
    listen(sockServer,5);
    int len=sizeof(SOCKADDR);
    char recvBuf[100];
    sockClient=accept(sockServer,(SOCKADDR*)&addrClient,&len);
    recv(sockClient,recvBuf,100,0);
    int sen=message.length();
    for(int i=1;i<=sen;i++)
    {
    	putchar(8);
    }
    for(int i=1;i<=sen;i++)
    {
    	putchar(' ');
    }
    for(int i=1;i<=sen;i++)
    {
    	putchar(8);
    }
    printf("%s\n",recvBuf);
    cout<<message;
    closesocket(sockClient);
    outit();
}
DWORD WINAPI head(LPVOID lpParamter)
{
	while(1)
	{
		recive(6819);
	}
	return 0L;
}
string ip,name;int dk;
string get(string &message)
{
	message="";
	char k=_getche();
	while(k!=13)
	{
		if(k<0)
		{
			message+=k;
			k=_getche();
		}
		if(k==8)
		{
			message.erase(message.end()-1,message.end()); 
			putchar(' ');
			putchar(8);
		}
		else
		{
			message+=k;
		}
		k=_getche();
	}
	return message;
}
void mian()
{
	getline(cin,message);
	if(message=="")return;
	string ts=name;
	ts+="->";
	ts+=message;
	int len=ts.length();
	char mes[len+1];
	for(int i=0;i<len;i++)
	{
		mes[i]=ts[i];
	}
	mes[len]='\0';
	say(ip.c_str(),dk,mes,strlen(mes));
}

signed main()
{
    printf("input server`s dk:");
    cin>>dk;
    printf("input server`s ipv4:");
    cin>>ip;
    printf("input your name:");
    cin>>name;
    char hello[]="join";
    say(ip.c_str(),dk,hello,strlen(hello));
    Sleep(1000);
    CreateThread(NULL,0,head,NULL,0,NULL);
    while(1)
    {
    	mian();
    }
}
