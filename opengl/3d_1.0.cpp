#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cstring>
#include <math.h>
#include <cstdio>
float col_l[3],col_p[3];
void draw(int x1,int y1,int z1,int x2,int y2,int z2){
	glColor3f(col_p[0],col_p[1],col_p[2]);
	glPolygonMode(GL_FRONT,GL_FILL);
    glPolygonMode(GL_BACK,GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(x1,y1,z1);
    glVertex3f(x1,y2,z1);
    glVertex3f(x2,y2,z1);
    glVertex3f(x2,y1,z1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x1,y1,z2);
    glVertex3f(x2,y1,z2);
    glVertex3f(x2,y2,z2);
    glVertex3f(x1,y2,z2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x1,y1,z1);
    glVertex3f(x2,y1,z1);
    glVertex3f(x2,y1,z2);
    glVertex3f(x1,y1,z2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x1,y2,z1);
    glVertex3f(x1,y2,z2);
    glVertex3f(x2,y2,z2);
    glVertex3f(x2,y2,z1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x1,y1,z2);
    glVertex3f(x1,y2,z2);
    glVertex3f(x1,y2,z1);
    glVertex3f(x1,y1,z1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x2,y1,z1);
    glVertex3f(x2,y2,z1);
    glVertex3f(x2,y2,z2);
    glVertex3f(x2,y1,z2);
    glEnd();
	glColor3f(col_l[0],col_l[1],col_l[2]);
	glPolygonMode(GL_FRONT,GL_LINE);
	glPolygonMode(GL_BACK,GL_LINE);
    glBegin(GL_POLYGON);
    glVertex3f(x1,y1,z1);
    glVertex3f(x1,y2,z1);
    glVertex3f(x2,y2,z1);
    glVertex3f(x2,y1,z1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x1,y1,z2);
    glVertex3f(x2,y1,z2);
    glVertex3f(x2,y2,z2);
    glVertex3f(x1,y2,z2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x1,y1,z1);
    glVertex3f(x2,y1,z1);
    glVertex3f(x2,y1,z2);
    glVertex3f(x1,y1,z2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x1,y2,z1);
    glVertex3f(x1,y2,z2);
    glVertex3f(x2,y2,z2);
    glVertex3f(x2,y2,z1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x1,y1,z2);
    glVertex3f(x1,y2,z2);
    glVertex3f(x1,y2,z1);
    glVertex3f(x1,y1,z1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x2,y1,z1);
    glVertex3f(x2,y2,z1);
    glVertex3f(x2,y2,z2);
    glVertex3f(x2,y1,z2);
    glEnd();
}
float now_x=1.0,now_y=1.0,now_z=2.0,see_ping=M_PI/2,see_h=0.0f,head=0.0f;
struct Cft{
	float x1,x2,y1,y2,z1,z2;
}cft[10000];

struct point
{
	bool ifshow;
	float x,y,z;
	float r,g,b;
	point()
	{
		x=y=z=0.0f;
		r=g=b=0.0f;
		ifshow=true;
	}
	void color(float rr,float gg,float bb)
	{
		r=rr;
		g=gg;
		b=bb;
	}
	void position(float xx,float yy,float zz)
	{
		x=xx;
		y=yy;
		z=zz;
	}
	void show()
	{
		glColor3f(r,g,b);
		glBegin(GL_POINTS);
		glVertex3f(x,y,z);
		glEnd();
	}
};
struct flat
{
	#define type_x 1
	#define type_y 2
	#define type_z 3
	bool ifshow;
	int type;
	float x,y,z,x1,x2,y1,y2,z1,z2;
	float r,g,b;
	flat()
	{
		x=y=z=0.0f;
		x1=x2=y1=y2=z1=z2=0.0f;
		r=g=b=0.0f;
		ifshow=true;
	}
	void show()
	{
		if(type==type_x)
		{
			glColor3f(r,g,b);
			glBegin(GL_POLYGON);
		    glVertex3f(x2,y1,z1);
		    glVertex3f(x2,y2,z1);
		    glVertex3f(x2,y2,z2);
		    glVertex3f(x2,y1,z2);
		    glEnd();
		}
	}
	void color(float rr,float gg,float bb)
	{
		r=rr;
		g=gg;
		b=bb;
	}
	void position(float xx,float yy,float zz)
	{
		x=xx;
		y=yy;
		z=zz;
	}
	void position(float xx1,float xx2,float yy1,float yy2,float zz1,float zz2)
	{
		x1=xx1;
		y1=yy1;
		z1=zz1;
		x2=xx2;
		y2=yy2;
		z2=zz2;
	}
	#undef type_x
	#undef type_y
	#undef type_z
};
struct object
{
	#define type_point 1
	#define type_flat 4
	#define type_cube 6
	int type;
	void *obj;
	void show(int ttype,void *tshow)
	{
		flat *ss_flat;
		point *ss_point;
		switch(ttype)
		{
			case type_point:ss_flat=(flat *)tshow;ss_flat->show();break;
			case type_flat:ss_point=(point *)tshow;ss_point->show();break;
		}
	}
	void show()
	{
		show(type,obj);
	}
	#undef type_cube
	#undef type_flat
	#undef type_point
};


int cnt=0;
float glut_width,glut_height;
float nowx_,nowy_,nowz_,sh,ch;
void updata_now()
{
	glMatrixMode(GL_PROJECTION);//¾ØÕóÄ£Ê½ 
	glEnable(GL_DEPTH_TEST);//ÕÚµ² 
	glut_width=glutGet(GLUT_WINDOW_HEIGHT);
	glut_height=glutGet(GLUT_WINDOW_WIDTH);
	
	nowx_=now_x+cos(see_ping);
	nowy_=now_y+sin(see_h);
	nowz_=now_z-sin(see_ping);
	sh=sin(head);
	ch=cos(head);
}
void display()
{
	glLoadIdentity ();
	gluPerspective(60.0,glut_width/glut_height,0.1, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(now_x,now_y,now_z,nowx_,nowy_,nowz_,sh,ch,0.0f);
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	point aaa;
	aaa.color(1.0,0.0,0.0);
	aaa.position(1.0,1.5,1.0);
	object sss;
	sss.obj=(void *)&aaa;
	sss.show();
	for(int i=1;i<cnt;i++)
	{
    	draw(cft[i].x1,cft[i].y1,cft[i].z1,cft[i].x2,cft[i].y2,cft[i].z2);
	}
	glFlush();
}
int xx,yy;
void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN)
	{
        xx=x;
        yy=y;
    }
	else
	{
        see_h+=(y-yy)*2.0/glut_width;
        see_ping+=(x-xx)*1.1/glut_height;
        nowx_=now_x+cos(see_ping);
		nowy_=now_y+sin(see_h);
		nowz_=now_z-sin(see_ping);
        display();
    }
}
void motion(int x,int y)
{
	glut_width=glutGet(GLUT_WINDOW_HEIGHT);
	glut_height=glutGet(GLUT_WINDOW_WIDTH);
    see_h+=(y-yy)*1.5/glut_width;
    see_ping+=(x-xx)*2.1/glut_height;
    nowx_=now_x+cos(see_ping);
	nowy_=now_y+sin(see_h);
	nowz_=now_z-sin(see_ping);
    xx=x;
    yy=y;
    display();
}
float lmd=0.1f;
const float
to_w=M_PI*0.0,
to_a=M_PI*0.5,
to_s=M_PI*1.0,
to_d=M_PI*1.5;
#define go(darta) \
{\
now_x+=lmd*cos(see_ping+darta);\
nowx_=now_x+cos(see_ping);\
now_z-=lmd*sin(see_ping+darta);\
nowz_=now_z-sin(see_ping);\
}
void keyBoard(unsigned char k,int x,int y)
{
    switch(k)
    {
    	case 'w':go(to_w);break;
    	case 'a':go(to_a);break;
    	case 's':go(to_s);break;
    	case 'd':go(to_d);break;
    	case 'c':head-=0.1f;sh=sin(head);ch=cos(head);break;
    	case 'v':head+=0.1f;sh=sin(head);ch=cos(head);break;
    	default :return;
    }
    
    display();
}
void special(int key, int x, int y)
{
	if(key==GLUT_KEY_PAGE_UP)
	{
		now_y+=lmd;
		nowy_=now_y+sin(see_h);
	}else if(key==GLUT_KEY_PAGE_DOWN)
	{
		now_y-=lmd;
		nowy_=now_y+sin(see_h);
	}
	else
	{
		return;
	}
	display();
}

DWORD WINAPI read(LPVOID lpParamter)
{
	std::string opt;
	while(1)
	{
		/*
		std::cin>>opt;
		if(opt=="tp")
		{
			scanf("%f%f%f",&now_x,&now_y,&now_z);
		}else
		if(opt=="add")
		{
			scanf("%f%f%f%f%f%f",&cft[cnt].x1,&cft[cnt].y1,&cft[cnt].z1,&cft[cnt].x2,&cft[cnt].y2,&cft[cnt].z2);
			cnt++;
		}else
		if(opt=="del")
		{
			int del;
			scanf("%d",&del);
			std::swap(cft[del],cft[cnt--]);
		}
		*/
		scanf("%f%f%f%f%f%f",&cft[cnt].x1,&cft[cnt].y1,&cft[cnt].z1,&cft[cnt].x2,&cft[cnt].y2,&cft[cnt].z2);
		cnt++;
	}
	return 0LL;
}

signed main(int argc, char *argv[])
{
	CreateThread(NULL,0,read,NULL,0,NULL);
	scanf("%f%f%f%f%f%f",&col_l[0],&col_l[1],&col_l[2],&col_p[0],&col_p[1],&col_p[2]);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(150, 150);
	glutCreateWindow("test");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyBoard);
	glutSpecialFunc(special);
	updata_now();
	glutMainLoop();
}
/*
1 1 1 0 0 0
1 3 5 2 5 7
-10 2 7 5 3 8


0 0 0 1 2 2

*/
