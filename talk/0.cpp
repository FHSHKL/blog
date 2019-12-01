#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<ctime>

#include<windows.h>
#include<direct.h>
#include<conio.h>
#include<io.h>

#include"md5.h"

using namespace std;
HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
struct tim
{
	int hou,min,sec;
	void init()
	{
		hou=0;
		min=0;
		sec=0;
	}
	void get_tim()
	{
		time_t now = time(0);
		tm *ltm = localtime(&now);
		hou=ltm->tm_hour;
		min=ltm->tm_min;
		sec=ltm->tm_sec;
	}
};
struct message
{
	int opt;
	int time[3];
	int usser;
	char mes[500];
	int sha[16];
	void init()
	{
		opt=0;
		for(int i=0;i<4;i++)
		{
			time[i]=0;
		}
		usser=0;
		memset(mes,0,sizeof(mes));
		memset(sha,0,sizeof(sha));
	}
	bool check_sha()
	{
		int len=strlen(mes);
		char gs[len+1+3+1];memset(gs,0,sizeof(gs));
		gs[0]=opt;
		gs[1]=time[0];
		gs[2]=time[1];
		gs[3]=time[2];
		gs[4]=usser;
		for(int i=5;i<len+5;i++)
		{
			gs[i]=mes[i-5];
		}
		unsigned char decrypt[16];
		memset(decrypt,0,sizeof(decrypt));
	    MD5_CTX md5;
	    MD5Init(&md5);
	    MD5Update(&md5,(unsigned char*)gs,len+5);
	    MD5Final(&md5,decrypt);
	    for(int i=0;i<16;i++)
	    {
	    	if(sha[i]!=decrypt[i])
	    	{
	    		return 0;
	    	}
	    }
	    return 1;
	}
	void get_sha()
	{
		int len=strlen(mes);
		char gs[len+1+3+1];memset(gs,0,sizeof(gs));
		gs[0]=opt;
		gs[1]=time[0];
		gs[2]=time[1];
		gs[3]=time[2];
		gs[4]=usser;
		for(int i=5;i<len+5;i++)
		{
			gs[i]=mes[i-5];
		}
		unsigned char decrypt[16];
		memset(decrypt,0,sizeof(decrypt));
	    MD5_CTX md5;
	    MD5Init(&md5);
	    MD5Update(&md5,(unsigned char*)gs,len+5);
	    MD5Final(&md5,decrypt);
	    for(int i=0;i<16;i++)
	    {
	    	sha[i]=decrypt[i];
	    }
	}
};

struct client
{
	char in[500];
	char out[500];
	char del[500];
	void init()
	{
		memset(del,0,sizeof(del));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
	}
	void get_path(string path,int usser)
	{
		path+=usser;
		string tin=path;
		tin+=".client";
		string tout=path;
		tout+=".server";
		string tdel="del ";
		tdel+=tin;
		get_in(tin);
		get_out(tout);
		get_del(tdel);
	}
	void get_in(string tin)
	{
		memset(in,0,sizeof(in));
		int len=tin.length();
		for(int i=0;i<len;i++)
		{
			in[i]=tin[i];
		}
	}
	void get_out(string tout)
	{
		memset(out,0,sizeof(out));
		int len=tout.length();
		for(int i=0;i<len;i++)
		{
			out[i]=tout[i];
		}
	}
	void get_del(string tdel)
	{
		memset(del,0,sizeof(del));
		int len=tdel.length();
		for(int i=0;i<len;i++)
		{
			del[i]=tdel[i];
		}
	}
	void send(message mes)
	{
		ofstream fout(out);
		fout<<mes.opt<<endl;
		for(int i=0;i<4;i++)
		{
			fout<<mes.time[i]<<endl;
		}
		fout<<mes.usser<<endl;
		int len=strlen(mes.mes);
		for(int i=0;i<len;i++)
		{
			fout<<(int)(mes.mes[i])<<endl;
		}
		for(int i=0;i<16;i++)
		{
			fout<<mes.sha[i]<<endl;
		}
		fout.close();
		fout.clear();
	}
	message get_mes(int opt,string mes)
	{
		message ans;
		ans.opt=opt;
		tim ntim;
		ntim.get_tim();
		ans.time[0]=ntim.hou;
		ans.time[1]=ntim.min;
		ans.time[2]=ntim.sec;
		memset(ans.mes,0,sizeof(ans.mes));
		int len=mes.length();
		for(int i=0;i<len;i++)
		{
			ans.mes[i]=mes[i];
		}
		ans.get_sha();
		return ans;
	}
};

struct server
{
	
};

string path;

void go_client()
{
	client me;
}

void go_server()
{
	server me;
}

void path_init()
{
	cout<<"input talk_path\n";
	cin>>path;
	int len=path.length();
	if(path[len-1]!='/'&&path[len-1]!='\\')
	{
		path+='\\';
		len++;
	}
	for(int i=0;i<len;i++)
	{
		if(path[i]=='/')
		{
			path[i]='\\';
		}
	}
}

void type_init()
{
	string lor;
	while(1)
	{
		system("cls");
		cout<<"choose one:client or server\n";
		cin>>lor;
		if(lor=="client"||lor=="server")
		{
			break;
		}
		else
		{
			cout<<"input client or server\n";
			system("pause");
		}
	}
	path_init();
	if(lor=="client")
	{
		go_client();
	}
	if(lor=="server")
	{
		go_server();
	}
}

signed main()
{
	type_init();
}
/*
abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz
qwertyuiopasdfghjklzxcvbnm`1234567890~!@#$%^&*()_+-=/-+
awertyuiopasdfghjklzxcvbnm`1234567890~!@#$%^&*()_+-=/-+
qwertyuiopasdfghjklzxcvbnm`1234567890~!@#$%^&*()_+-=/-0
qwertyuiopasdfghjklzxcvbnm`1235467890~!@#$%^&*()_+-=/-0
5999f03bcde8ae2000000
5999f02bcde8ae2000000
5999f03ba1e8ae2000000
9999f03ba1e8ae2000000
*/
