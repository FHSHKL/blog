#include <bits/stdc++.h>   
#include <windows.h>   
#include <io.h>
using namespace std;

int yzb=-1;
int yanse;
string ced;
char bh;
bool sr;
string user;
bool alive=1;
int tiao=0;
char opp[]="\\\\A408-9\\Admin\\stu\\0";
//char opp[]="E:A408-9\\Admin\\stu\\0";//���� 

HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);

void gbzb(int);
void color(int);
void tim();
void gbh();

void gbh()
{
	string name="******";
	char path[20];
	int xh;
	ofstream bhh("bh.txt");
	for(int i=0;i<=19;i++)
	path[i]=opp[i];
	for(char i='0';i<='Z';i++)
	{
		path[19]=i;
		if(access(path,0)!=-1)
		{
			time_t now = time(0);
			tm *ltm = localtime(&now);
			xh=ltm->tm_hour;
			ifstream fbh(path);
			for(int k=0;k<=5;k++)
			{
				int nua;
				fbh>>nua;
				name[k]=nua^xh;
			}
			bhh<<name<<"---"<<i<<endl;
			fbh.close();
			fbh.clear();
		}
	}
	bhh.close();
	bhh.clear();
	system("start bh.txt");
}
void help()
{
	ofstream fout("help.txt");
	fout<<"ָ��ϼ�:"<<endl;
	fout<<"/a__ȡ������"<<endl;
	fout<<"/e__�˳�"<<endl;
	fout<<"/k__kill"<<endl;
	fout<<"/@__@ĳ��"<<endl;
	fout<<"/?__����"<<endl;
	fout.close();
	fout.clear();
	system("start help.txt"); 
//	fout<<""<<endl;
}

void gbzb(int y)
{
	COORD pos={0,y};
    SetConsoleCursorPosition(hout,pos);
}

void color(int coo)
{
    SetConsoleTextAttribute(hout,coo);
}

void tim()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	printf("%02d:%02d:%02d",ltm->tm_hour,ltm->tm_min,ltm->tm_sec);
}

DWORD WINAPI read(LPVOID lpParamter)
{
	bool f;
	bool tz;
    while(1)
    {
    	gbzb(0);
    	f=0;
    	Sleep(1);
    	getline(cin,ced);
		if(ced=="")
		continue;
    	if(ced[ced.length()-2]=='/')
    	{
    		switch(ced[ced.length()-1])
    		{
    			case 'a':f=1;break;
    			case 'b':f=1;gbh();break;
				case 'c':break;
				case 'e':alive=0;return 0L;
    			case 'k':break;
    			case 't':tz=1;break;
    			case '@':break;
    			case '?':f=1;help();break;
			}
			gbzb(0);
			for(int k=1;k<=78*2;k++)
			{
				putchar(' ');
			}
			gbzb(0);
			if(f)
			continue;
		}
		gbzb(0);
		for(int k=1;k<=78*2;k++)
		{
			putchar(' ');
		}
		gbzb(0);
		time_t now = time(0);
		tm *ltm = localtime(&now);
		int xh=ltm->tm_hour;
		if(tz)
		{
			ofstream fout(opp);
		    int mm;
		    char tzuser[]="*֪ͨ*";
		    for(int k=0;k<=5;k++)
		    {
		    	mm=tzuser[k]^xh;
		    	fout<<mm<<endl;
			}
		    fout<<"79"<<endl;
		    for(int i=0;i<ced.length()-2;i++)
			{
				int a=ced[i];
				fout<<(a^xh);
				fout<<endl;
			}
		    fout.close();
		    fout.clear();
		    tz=0;
		    continue;
		}
	    ofstream fout(opp);
	    int mm;
	    for(int k=0;k<=5;k++)
	    {
	    	mm=user[k]^xh;
	    	fout<<mm<<endl;
		}
	    fout<<yanse<<endl;
	    for(int i=0;i<ced.length();i++)
		{
			int a=ced[i];
			fout<<(a^xh);
			fout<<endl;
		}
	    fout.close();
	    fout.clear();
	}
    return 0L;
}
DWORD WINAPI output(LPVOID lpParamter)
{
	int k,xh,se,cha,name[6];
	string a;
	char last['Z'+1][2000][2];
	bool lor['Z'+1];
	memset(last,0,sizeof(last));
	memset(lor,0,sizeof(lor));
	char i='0';
	bool flag;
	char path[20];
	for(int i=0;i<=19;i++)
	path[i]=opp[i];
	while(1)
	{
		Sleep(1);
		flag=1;
		if(i>='Z'+1){i='0';}else{i++;}
		path[19]=i;
		if(_access(path,0)!=-1)
		{
			time_t now = time(0);
			tm *ltm = localtime(&now);
			xh=ltm->tm_hour;
			ifstream fin(path);
			int k;
			for(int ii=0;ii<=5;ii++)
			{
				fin>>name[ii];
			}
			fin>>se;
			last[i][0][lor[i]]=0;
			while(!fin.eof())
			{
				fin>>cha;
				last[i][   ++last[i][0][lor[i]]   ][lor[i]]=cha;
			}
			fin.close();
			fin.clear();
			for(k=0;k<=last[i][0][lor[i]];k++)
			{
				if(last[i][k][lor[i]]!=last[i][k][lor[i]^1])
				{
					break;
				}
			}
			if(last[i][0][lor[i]]!=last[i][0][lor[i]^1]   ||   k<last[i][0][lor[i]])
			{
				ced="";
				yzb++;
				if((last[i][1][lor[i]]^xh)=='/')
				{
					switch(last[i][2][lor[i]]^xh)
					{
						case 'k':alive=0;return 0L;
						case '@':break;
					}
				}
				if(yzb>=22)
				{
					yzb-=22;
					system("cls");
				}
				gbzb(yzb%22+2);
				tim();
				color(se);
				for(int ii=0;ii<=5;ii++)
				{
					putchar(name[ii]^xh);
				}
				cout<<"->";
				color(15);
				for(int wei=1;wei<last[i][0][lor[i]];wei++)
				putchar(last[i][wei][lor[i]]^xh);
				cout<<endl;
				lor[i]^=1;
				int la=a.length();
				la-=62;
				while(la>0)
				{
					la-=78;
					yzb++;
				}
				gbzb(0);
			}
		}
	}
}
int main()
{
	SetConsoleTitle("WeChat_19.0_by-Fire_Humans_Skeleton");
	if(access("\\\\A408-9\\Admin\\stu\\WeChat20.exe",0)!=-1)
	{
		system("copy \\\\A408-9\\Admin\\stu\\WeChat20.exe E:");
		system("start E:WeChat20.exe");
		return 0;
	}
	char path[20];
	for(int i=0;i<=19;i++)
	path[i]=opp[i];
	color(15);
	int ya=20,yb=20;
	while(1)
	{
		cout<<"������";
		cin>>bh;
		if(bh<'0'||bh>'z')
		{
			cout<<"��Ų��Ϸ�,������ascii��'0'��'Z'֮����ַ�"<<endl; 
		}
		else
		{
			path[19]=bh;
			if(_access(path,0)!=-1)
			{
				cout<<"����ѱ�ռ��,��������"<<endl; 
			}
			else
			{
				break;
			}
		}
	}
	while(1)
	{
		cout<<"��������";
		cin>>user;
		if(user=="������")break;
		if(user=="���ǲ�")break;
		if(user=="ף˶��")break;
		if(user=="���")break;
		if(user=="��˧ة")break;
		if(user=="١����")break;
		if(user=="�ܴ�")break;
		if(user=="������")break;
		/*
		if(user=="�봺��")break;
		if(user=="������")break;
		if(user=="������")break;
		if(user=="������")break;
		*/
		cout<<"�û����Ϸ�,��������ʵ����!"<<endl;
	}
	system("cls");
	if(user=="���")
	user="��__��";
	cout<<"���뱳���Լ�������ɫ"<<endl;
	for(int i=0;i<=15;i++)
	{
		color(i);
		printf("��ɫ���:");
		color(15);
		printf("%02d\n",i);
	}
	while(1)
	{
		COORD pos={0,17};
    	SetConsoleCursorPosition(hout,pos);
    	for(int i=1;i<=20;i++)
    	{
    		putchar(' ');
		}
		SetConsoleCursorPosition(hout,pos);
		cin>>ya>>yb;
		if(ya==yb||ya<0||yb<0||ya>15||yb>15||(ya-yb)*(ya-yb)==64)
		{
			cout<<"ʹ�õ���ɫ���Ϸ�,����������!"<<endl;
		}
		else
		{
			break;
		}
	}
	yanse=(ya<<4)|yb;
	char dell[]="del \\\\A408-9\\Admin\\stu\\0";
	opp[19]=bh;
	dell[23]=bh;
	dell[4]=opp[0];
	dell[5]=opp[1];
	system("cls");
    CreateThread(NULL,0,read,NULL,0,NULL);
    CreateThread(NULL,0,output,NULL,0,NULL);
    Sleep(500);
    gbzb((++yzb)%22+2);
    cout<<"--------------------����Ϊ��Ϣ��¼--------------------"<<endl;
    gbzb(0);
    while(alive)
    {
    	Sleep(1000);
    	if(access("\\\\A408-9\\Admin\\stu\\WeChat20.exe",0)!=-1)
		{
			system("copy \\\\A408-9\\Admin\\stu\\WeChat20.exe E:");
			system("start E:WeChat20.exe");
			alive=0;
		}
	}
	system(dell);
    return 0;
}
