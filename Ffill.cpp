#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;
void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,640,0,480);
	
}
void Ffill(int x,int y,float*fillColor,float*oldColor)
{
	float color[3];
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
	if((color[0]==oldColor[0] && color[1]==oldColor[1] && color[2]==oldColor[2]))
	{
		glColor3f(fillColor[0],fillColor[1],fillColor[2]);
		
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		glFlush();
		Ffill(x+1,y,fillColor,oldColor);
		Ffill(x-2,y,fillColor,oldColor);
		Ffill(x,y+1,fillColor,oldColor);
		Ffill(x,y-2,fillColor,oldColor);
		
	}
}
void mouse(int btn,int state,int x,int y)
{
	y=480-y;
	if(btn==GLUT_LEFT_BUTTON)
	{
		if(state==GLUT_DOWN)
		{
			float intCol[]={1,0,0};
			float color[]={0,1,0};
			glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,intCol);
			Ffill(x,y,color,intCol);
			
		}
	}

}
void polygon()
{
	glLineWidth(3);
	glPointSize(2);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glBegin(GL_LINES);
	//glBegin(GL_LINE_LOOP);
	glVertex2i(150,100);
	glVertex2i(300,300);
	glColor3f(0,1,0);
	glBegin(GL_LINES);
	glVertex2i(300,300);
	glVertex2i(450,100);
	glColor3f(0,0,1);
	glBegin(GL_LINES);
	glVertex2i(150,100);
	glVertex2i(450,100);
	glEnd();
	glFlush();
	
}
int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(50,50);
	glutCreateWindow("F fill");
	init();
	glutDisplayFunc(polygon);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
	
}
