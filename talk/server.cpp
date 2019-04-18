#include<iostream>
#include<cstdio>
using namespace std;

#include<winsock2.h>

WSADATA wsaData;
SOCKET sockServer;
SOCKADDR_IN addrServer;
SOCKET sockClient;
SOCKADDR_IN addrClient;

void init()
{
	WSAStartup(MAKEWORD(2,2),&wsaData);
    sockServer=socket(AF_INET,SOCK_STREAM,0);
    sockClient=socket(AF_INET,SOCK_STREAM,0);
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
    outit();
}

struct fhs_server
{
	char server[50][50];
	int check[50];
	int top,cop;
	void in(const char *t_in)
	{
		int len=strlen(t_in);
		int key=0;
		for(int i=0;i<len;i++)
		{
			if(t_in[i]!='.')
			{
				key*=10;
				key+=t_in[i];
			}
		}
		for(int i=1;i<=cop;i++)
		{
			if(check[i]==key)
			{
				return;
			}
		}
		cop++;
		check[cop]=key;
		top++;
		memset(server[top],0,sizeof(server[top]));
		for(int i=0;i<len;i++)
		{
			server[top][i]=t_in[i];
		}
	}
	void pr()
	{
		for(int i=1;i<=top;i++)
		{
			cout<<server[i]<<endl;
		}
	}
	void send(char* data)
	{
		int len=strlen(data);
		for(int i=1;i<=top;i++)
		{
			say(server[i],6819,data,len);
		}
	}
}serv;

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
    
    const char * from_ip=inet_ntoa(addrClient.sin_addr);
    serv.in(from_ip);
    serv.pr();
    
    printf("%s\n",recvBuf);
    serv.send(recvBuf);
    closesocket(sockClient);
    outit();
}

signed main()
{
	system("ipconfig");
	int dk;
	printf("input dk:");
	scanf("%d",&dk);
	serv.top=0;
	serv.cop=0;
	while(1)
	{
		recive(dk);
	}
    while(getchar());
}
