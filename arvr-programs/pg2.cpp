#include<gl/glut.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#define MAX 100000

double array[MAX][2];

//Function: Display Call back - used to draw the required visualization
//return type: void
//parameters: void
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glutWireTeapot(0.5);

	glFlush();
}

int main(int argc, char* argv[])
{
	//Initialize glut
	glutInit(&argc, argv);

	//configure opengl window
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB);

	//create the Opengl window with a specific name
	glutCreateWindow("My First OpenGL Window");

	//register the callback for displaying
	glutDisplayFunc(display);

	//star the opengl loop 
	glutMainLoop();
}