#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cstring>
#include <math.h>
#include <cstdio>
#include <map>
int min(int a,int b){return a<b?a:b;}
float col_l[3],col_p[3];
void draw(float x1,float y1,float z1,float x2,float y2,float z2){
	glColor3f(col_p[0],col_p[1],col_p[2]);
    glPolygonMode(GL_FRONT,GL_FILL);
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
float now_x=1.0,now_y=1.0,now_z=2.0,see_ping=M_PI/2,see_h=M_PI/2;
struct Cft{
	float x1,x2,y1,y2,z1,z2;
}cft[10000];
int cnt=2;
using namespace std;
map< double,double >__cos;
map< double,double >__sin;
double _cos(double ss)
{
	if(!__cos[ss])
	{
		__cos[ss]=cos(ss);
	}
	return __cos[ss];
}
double _sin(double ss)
{
	if(!__sin[ss])
	{
		__sin[ss]=sin(ss);
	}
	return __sin[ss];
}
#define sin _sin
#define cos _cos
void display()
{
    gluPerspective(60.0, 1.0, 0.01, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(now_x,now_y,now_z,
	now_x+cos(see_ping)*sin(see_h),now_y+cos(see_h),now_z+sin(see_ping)*sin(see_h),
	cos(see_ping)*sin(see_h-M_PI/2),cos(see_h-M_PI/2),sin(see_ping)*sin(see_h-M_PI/2));
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    for(int i=0;i<cnt;++i)
	{
    	draw(cft[i].x1,cft[i].y1,cft[i].z1,cft[i].x2,cft[i].y2,cft[i].z2);
	}
    glFlush();
}
int xx,yy;
void motion(int x,int y)
{
    see_h+=(yy-y)*1.1/glutGet(GLUT_WINDOW_HEIGHT);
    see_ping+=(xx-x)*1.1/glutGet(GLUT_WINDOW_WIDTH);
    xx=x;
    yy=y;
    display();
}
void mouse(int button,int state,int x,int y){
    if(state==GLUT_DOWN){
        xx=x;
        yy=y;
    }else{
        motion(x,y);
    }
}
float lmd=0.1f;
void keyBoard(unsigned char k,int x,int y){
    float darta;
    bool flag=false;
    if(k=='w'){
        flag=true;
        darta=0.0f;
    }else if(k=='d'){
        flag=true;
        darta=M_PI*0.5;
    }else if(k=='s'){
        flag=true;
        darta=M_PI;
    }else if(k=='a'){
        flag=true;
        darta=M_PI*1.5;
    }else{
    	return;
    }
    if(flag){
        now_x+=lmd*cos(see_ping+darta);
        now_z+=lmd*sin(see_ping+darta);
    }
    display();
}
void special(int key, int x, int y){
	if(key==GLUT_KEY_PAGE_UP){
		now_y+=lmd;
	}else if(key==GLUT_KEY_PAGE_DOWN){
		now_y-=lmd;
	}else{
		return;
	}
	display();
}
void reshape(int x,int y){
	glViewport (0,0,x,y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    display();
}
void loadConfig(){
	freopen("config.txt","r",stdin);
	scanf("%f%f%f%f%f%f",&col_l[0],&col_l[1],&col_l[2],&col_p[0],&col_p[1],&col_p[2]);
	scanf("%d",&cnt);
	for(int i=0;i<cnt;++i){
		scanf("%f%f%f%f%f%f",&cft[i].x1,&cft[i].y1,&cft[i].z1,&cft[i].x2,&cft[i].y2,&cft[i].z2);
	}
}
void init(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("test");
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyBoard);
	glutSpecialFunc(special);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
int main(int argc, char *argv[]){
	loadConfig();
	init(argc,argv);
}
