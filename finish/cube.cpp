#include<windows.h>
#include<cstdio>

using namespace std;

HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);

void gbzb(short x,short y)
{
	x*=2;
	COORD pos={x,y};
	SetConsoleCursorPosition(hout,pos);
}
const int color_list[7]={0,1,4,14,5,15,2};
void color(int col)
{
	SetConsoleTextAttribute(hout,color_list[col]);
}
void of()
{
	printf("¡ö");
}


struct mf
{
	int a[6][9];
	int work[6][9];
	void init()
	{
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<9;j++)
			{
				a[i][j]=i+1;
			}
		}
	}
	void pb()
	{
		for(int i=0;i<6;i++)
		for(int j=0;j<9;j++)
		a[i][j]=work[i][j];
	}
	void pi()
	{
		for(int i=0;i<6;i++)
		for(int j=0;j<9;j++)
		work[i][j]=a[i][j];
	}
	void face(int fac,int s)
	{
		if(s)
		{
			work[fac][0]=a[fac][6];
			work[fac][1]=a[fac][3];
			work[fac][2]=a[fac][0];
			work[fac][3]=a[fac][7];
			work[fac][5]=a[fac][1];
			work[fac][6]=a[fac][8];
			work[fac][7]=a[fac][5];
			work[fac][8]=a[fac][2];
		}
		else
		{
			work[fac][0]=a[fac][2];
			work[fac][1]=a[fac][5];
			work[fac][2]=a[fac][8];
			work[fac][3]=a[fac][1];
			work[fac][5]=a[fac][7];
			work[fac][6]=a[fac][0];
			work[fac][7]=a[fac][3];
			work[fac][8]=a[fac][6];
		}
	}
	void u()
	{
		pi();
		face(0,1);
		for(int i=1;i<=4;i++)
		for(int j=0;j<3;j++)
		{
			work[i][j]=a[(i%4)+1][j];
		}
		pb();
	}
	void uf()
	{
		pi();
		face(0,0);
		for(int i=1;i<=4;i++)
		for(int j=0;j<3;j++)
		{
			work[(i%4)+1][j]=a[i][j];
		}
		pb();
	}
	void df()
	{
		pi();
		face(5,1);
		for(int i=1;i<=4;i++)
		for(int j=6;j<9;j++)
		{
			work[i][j]=a[(i%4)+1][j];
		}
		pb();
	}
	void d()
	{
		pi();
		face(5,0);
		for(int i=1;i<=4;i++)
		for(int j=6;j<9;j++)
		{
			work[(i%4)+1][j]=a[i][j];
		}
		pb();
	}
	
	void rz()
	{
		pi();
		face(0,0);
		face(5,1);
		for(int i=0;i<9;i++)work[1][i]=a[4][i];
		for(int i=0;i<9;i++)work[2][i]=a[1][i];
		for(int i=0;i<9;i++)work[3][i]=a[2][i];
		for(int i=0;i<9;i++)work[4][i]=a[3][i];
		pb();
	}
	void lz()
	{
		pi();
		face(0,1);
		face(5,0);
		for(int i=0;i<9;i++)work[1][i]=a[2][i];
		for(int i=0;i<9;i++)work[2][i]=a[3][i];
		for(int i=0;i<9;i++)work[3][i]=a[4][i];
		for(int i=0;i<9;i++)work[4][i]=a[1][i];
		pb();
	}
	void uz()
	{
		pi();
		face(1,0);
		face(3,1);
		for(int i=0;i<9;i++)work[0][i]=a[2][i];
		for(int i=0;i<9;i++)work[2][i]=a[5][i];
		for(int i=0;i<9;i++)work[4][i]=a[0][i];
		for(int i=0;i<9;i++)work[5][i]=a[4][i];
		pb();
	}
	void dz()
	{
		pi();
		face(1,1);
		face(3,0);
		for(int i=0;i<9;i++)work[0][i]=a[4][i];
		for(int i=0;i<9;i++)work[2][i]=a[0][i];
		for(int i=0;i<9;i++)work[4][i]=a[5][i];
		for(int i=0;i<9;i++)work[5][i]=a[2][i];
		pb();
	}
	void l()
	{
		pi();
		face(1,1);
		for(int i=0;i<3;i++)
		{
			work[0][i*3]=a[4][i*3];
			work[4][i*3]=a[5][i*3];
			work[5][i*3]=a[2][i*3];
			work[2][i*3]=a[0][i*3];
		}
		pb();
	}
	void lf()
	{
		pi();
		face(1,0);
		for(int i=0;i<3;i++)
		{
			work[0][i*3]=a[2][i*3];
			work[4][i*3]=a[0][i*3];
			work[5][i*3]=a[4][i*3];
			work[2][i*3]=a[5][i*3];
		}
		pb();
	}
	void rf()
	{
		pi();
		face(3,1);
		for(int i=0;i<3;i++)
		{
			work[0][i*3+2]=a[4][i*3+2];
			work[4][i*3+2]=a[5][i*3+2];
			work[5][i*3+2]=a[2][i*3+2];
			work[2][i*3+2]=a[0][i*3+2];
		}
		pb();
	}
	void r()
	{
		pi();
		face(3,0);
		for(int i=0;i<3;i++)
		{
			work[0][i*3+2]=a[2][i*3+2];
			work[4][i*3+2]=a[0][i*3+2];
			work[5][i*3+2]=a[4][i*3+2];
			work[2][i*3+2]=a[5][i*3+2];
		}
		pb();
	}
	void f()
	{
		pi();
		face(2,1);
		work[0][6]=a[1][8];
		work[0][7]=a[1][5];
		work[0][8]=a[1][2];
		work[1][2]=a[5][0];
		work[1][5]=a[5][1];
		work[1][8]=a[5][2];
		work[5][0]=a[3][6];
		work[5][1]=a[3][3];
		work[5][2]=a[3][0];
		work[3][0]=a[0][6];
		work[3][3]=a[0][7];
		work[3][6]=a[0][8];
		pb();
	}
	void ff()
	{
		pi();
		face(2,0);
		work[1][8]=a[0][6];
		work[1][5]=a[0][7];
		work[1][2]=a[0][8];
		work[5][0]=a[1][2];
		work[5][1]=a[1][5];
		work[5][2]=a[1][8];
		work[3][6]=a[5][0];
		work[3][3]=a[5][1];
		work[3][0]=a[5][2];
		work[0][6]=a[3][0];
		work[0][7]=a[3][3];
		work[0][8]=a[3][6];
		pb();
	}
	void b()
	{
		pi();
		face(4,0);
		work[3][8]=a[0][2];
		work[3][5]=a[0][1];
		work[3][2]=a[0][0];
		work[5][8]=a[3][2];
		work[5][7]=a[3][5];
		work[5][6]=a[3][8];
		work[1][6]=a[5][8];
		work[1][3]=a[5][7];
		work[1][0]=a[5][6];
		work[0][2]=a[1][0];
		work[0][1]=a[1][3];
		work[0][0]=a[1][6];
		pb();
	}
	void bf()
	{
		pi();
		face(4,1);
		work[0][2]=a[3][8];
		work[0][1]=a[3][5];
		work[0][0]=a[3][2];
		work[3][2]=a[5][8];
		work[3][5]=a[5][7];
		work[3][8]=a[5][6];
		work[5][8]=a[1][6];
		work[5][7]=a[1][3];
		work[5][6]=a[1][0];
		work[1][0]=a[0][2];
		work[1][3]=a[0][1];
		work[1][6]=a[0][0];
		pb();
	}
	void um()
	{
		pi();
		work[0][1]=a[2][1];
		work[0][4]=a[2][4];
		work[0][7]=a[2][7];
		work[2][1]=a[5][1];
		work[2][4]=a[5][4];
		work[2][7]=a[5][7];
		work[5][1]=a[4][1];
		work[5][4]=a[4][4];
		work[5][7]=a[4][7];
		work[4][1]=a[0][1];
		work[4][4]=a[0][4];
		work[4][7]=a[0][7];
		pb();
	}
	void dm()
	{
		pi();
		work[0][1]=a[4][1];
		work[0][4]=a[4][4];
		work[0][7]=a[4][7];
		work[2][1]=a[0][1];
		work[2][4]=a[0][4];
		work[2][7]=a[0][7];
		work[5][1]=a[2][1];
		work[5][4]=a[2][4];
		work[5][7]=a[2][7];
		work[4][1]=a[5][1];
		work[4][4]=a[5][4];
		work[4][7]=a[5][7];
		pb();
	}
	void lm()
	{
		pi();
		work[1][3]=a[2][3];
		work[1][4]=a[2][4];
		work[1][5]=a[2][5];
		work[2][3]=a[3][3];
		work[2][4]=a[3][4];
		work[2][5]=a[3][5];
		work[3][3]=a[4][3];
		work[3][4]=a[4][4];
		work[3][5]=a[4][5];
		work[4][3]=a[1][3];
		work[4][4]=a[1][4];
		work[4][5]=a[1][5];
		pb();
	}
	void rm()
	{
		pi();
		work[1][3]=a[4][3];
		work[1][4]=a[4][4];
		work[1][5]=a[4][5];
		work[2][3]=a[1][3];
		work[2][4]=a[1][4];
		work[2][5]=a[1][5];
		work[3][3]=a[2][3];
		work[3][4]=a[2][4];
		work[3][5]=a[2][5];
		work[4][3]=a[3][3];
		work[4][4]=a[3][4];
		work[4][5]=a[3][5];
		pb();
	}
	void turn(char opt)
	{
		switch(opt)
		{
			case 'U':uf();break;
			case 'u':u();break;
			case 'D':df();break;
			case 'd':d();break;
			case 'L':lf();break;
			case 'l':l();break;
			case 'R':rf();break;
			case 'r':r();break;
			case 'F':ff();break;
			case 'f':f();break;
			case 'B':bf();break;
			case 'b':b();break;
			case '8':uz();break;
			case '2':dz();break;
			case '4':lz();break;
			case '6':rz();break;
			case '1':dm();break;
			case '3':rm();break;
			case '7':lm();break;
			case '9':um();break;
		}
	}
	void pr()
	{
		gbzb(4,1);
		color(a[0][0]);of();
		color(a[0][1]);of();
		color(a[0][2]);of();
		gbzb(4,2);
		color(a[0][3]);of();
		color(a[0][4]);of();
		color(a[0][5]);of();
		gbzb(4,3);
		color(a[0][6]);of();
		color(a[0][7]);of();
		color(a[0][8]);of();
		
		gbzb(1,4);
		for(int i=1;i<=4;i++)
		{
			color(a[i][0]);of();
			color(a[i][1]);of();
			color(a[i][2]);of();
		}
		gbzb(1,5);
		for(int i=1;i<=4;i++)
		{
			color(a[i][3]);of();
			color(a[i][4]);of();
			color(a[i][5]);of();
		}
		gbzb(1,6);
		for(int i=1;i<=4;i++)
		{
			color(a[i][6]);of();
			color(a[i][7]);of();
			color(a[i][8]);of();
		}
		
		gbzb(4,7);
		color(a[5][0]);of();
		color(a[5][1]);of();
		color(a[5][2]);of();
		gbzb(4,8);
		color(a[5][3]);of();
		color(a[5][4]);of();
		color(a[5][5]);of();
		gbzb(4,9);
		color(a[5][6]);of();
		color(a[5][7]);of();
		color(a[5][8]);of();
	}
};

char tran[1000];

void tran_init()
{
	tran[78]='U';
	tran[79]='U';
	tran[89]='U';
	tran[87]='u';
	tran[98]='u';
	tran[97]='u';
	tran[12]='d';
	tran[23]='d';
	tran[13]='d';
	tran[32]='D';
	tran[21]='D';
	tran[31]='D';
	tran[28]='9';
	tran[82]='1';
	tran[46]='3';
	tran[64]='7';
	tran[65]='4';
	tran[45]='6';
	tran[25]='8';
	tran[85]='2';
	tran[54]='4';
	tran[58]='8';
	tran[56]='6';
	tran[52]='2';
	tran[14]='L';
	tran[17]='L';
	tran[47]='L';
	tran[41]='l';
	tran[74]='l';
	tran[71]='l';
	tran[36]='r';
	tran[39]='r';
	tran[69]='r';
	tran[63]='R';
	tran[96]='R';
	tran[93]='R';
	tran[86]='f';
	tran[62]='f';
	tran[24]='f';
	tran[48]='f';
	tran[68]='F';
	tran[84]='F';
	tran[42]='F';
	tran[26]='F';
	tran[586]='b';
	tran[562]='b';
	tran[524]='b';
	tran[548]='b';
	tran[568]='B';
	tran[584]='B';
	tran[542]='B';
	tran[526]='B';
	/*
	tran[]='';
	tran[]='';
	tran[]='';
	tran[]='';
	tran[]='';
	tran[]='';
	*/
}

int z[1000],top; 
mf xyt;

int bck(int opt)
{
	switch(opt)
	{
		case 'u':return 'U';
		case 'U':return 'u';
		case 'd':return 'D';
		case 'D':return 'd';
		case 'l':return 'L';
		case 'L':return 'l';
		case 'r':return 'R';
		case 'R':return 'r';
		case 'f':return 'F';
		case 'F':return 'f';
		case 'b':return 'B';
		case 'B':return 'b';
		case '2':return '8';
		case '8':return '2';
		case '4':return '6';
		case '6':return '4';
		case '9':return '1';
		case '1':return '9';
		case '3':return '7';
		case '7':return '3';
		//case '':return '';
	}
	return 0;
}

void back()
{
	while(top)
	{
		int too=z[top--];
		int oot=bck(too);
		xyt.turn(oot);
		xyt.pr();
		//Sleep(10);
	}
}

signed main()
{
	system("cls");
	xyt.init();
	xyt.pr();
	int opt;
	tran_init();
	while(1)
	{
		gbzb(1,13);
		scanf("%d",&opt);
		if(opt==6819)
		{
			back();
			continue;
		}
		xyt.turn(tran[opt]);
		z[++top]=tran[opt];
		xyt.pr();
	}
	system("color");
}
/*
41
23
63
56
41
69

*/
