#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL/glut.h>
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
int cnt=2;
void display()
{
    //glViewport (0, 0, (GLsizei) glutGet(GLUT_WINDOW_WIDTH), (GLsizei) glutGet(GLUT_WINDOW_HEIGHT));
    
	glMatrixMode (GL_PROJECTION);
    
	glLoadIdentity ();
    
	gluPerspective(60.0, (GLfloat) glutGet(GLUT_WINDOW_WIDTH)/(GLfloat) glutGet(GLUT_WINDOW_HEIGHT), 0.1, 20.0);
    
	glMatrixMode(GL_MODELVIEW);
    
	glLoadIdentity();
    
	gluLookAt(now_x,now_y,now_z,now_x+cos(see_ping),now_y+sin(see_h),now_z-sin(see_ping), sin(head),cos(head), 0.0f);
    
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	//«Âø’ª≠∞Â 
	glEnable(GL_DEPTH_TEST);
	//…Ó∂»≤‚ ‘ 
	//glDepthFunc(GL_LEQUAL);
	
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
    
	//glEnable(GL_CULL_FACE);
    
	for(int i=0;i<cnt;++i)
	{
    	draw(cft[i].x1,cft[i].y1,cft[i].z1,cft[i].x2,cft[i].y2,cft[i].z2);
	}
    
	//glCullFace(GL_BACK);
    
	glFlush();
}
int xx,yy;
void mouse(int button,int state,int x,int y){
    if(state==GLUT_DOWN){
        xx=x;
        yy=y;
    }else{
        see_h-=(yy-y)*2.0/glutGet(GLUT_WINDOW_WIDTH);
        see_ping+=(x-xx)*1.1/glutGet(GLUT_WINDOW_HEIGHT);
        display();
    }
}
void motion(int x,int y){
    see_h-=(yy-y)*1.5/glutGet(GLUT_WINDOW_HEIGHT);
    see_ping+=(x-xx)*2.1/glutGet(GLUT_WINDOW_WIDTH);
    xx=x;
    yy=y;
    display();
}
float lmd=0.1f;
void keyBoard(unsigned char k,int x,int y){
    float darta;
    bool flag=false;
    if(k=='w'){
        flag=true;
        darta=0.0f;
    }else if(k=='a'){
        flag=true;
        darta=M_PI*0.5;
    }else if(k=='s'){
        flag=true;
        darta=M_PI;
    }else if(k=='d'){
        flag=true;
        darta=M_PI*1.5;
    }else if(k=='c'){
        head-=0.1f;
    }else if(k=='v'){
        head+=0.1f;
    }else{
    	return;
    }
	/*else if(k==' '){
        now_y+=lmd;
    }else if(glutGetModifiers()==GLUT_ACTIVE_SHIFT){
        now_y-=lmd;
    }else{
        return;
    }*/
    if(flag){
        now_x+=lmd*cos(see_ping+darta);
        now_z-=lmd*sin(see_ping+darta);
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
int main(int argc, char *argv[]){
	freopen("config.txt","r",stdin);
	scanf("%f%f%f%f%f%f",&col_l[0],&col_l[1],&col_l[2],&col_p[0],&col_p[1],&col_p[2]);
	scanf("%d",&cnt);
	for(int i=0;i<cnt;++i){
		scanf("%f%f%f%f%f%f",&cft[i].x1,&cft[i].y1,&cft[i].z1,&cft[i].x2,&cft[i].y2,&cft[i].z2);
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("test");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyBoard);
	glutSpecialFunc(special);
	glutMainLoop();
}
