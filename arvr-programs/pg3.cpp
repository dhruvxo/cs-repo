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

	glPointSize(2);

	//Use GL_POINTS to mark the specified pixels
	glBegin(GL_POINTS);
	for (int i = 0; i < MAX; i++)
	{
		//change the color every iteration
		glColor3f((float)(rand() % 255) / 255.0, 
			(float)(rand() % 255) / 255.0, 
			(float)(rand() % 255) / 255.0);

		//draw all the points in the serpenski
		glVertex2dv(array[i]);
	}
	glEnd();

	glFlush();
}


//function: Initilize the triangle and the first random point. 
//			In this case the first random point is centroid
//Return Type: void
//Parameters: double array[MAX][2] inside which the points 
//				are to be declared
void initializeArray(double array[MAX][2]) {
	array[0][0] = 0;
	array[0][1] = 0.8;
	array[1][0] = -0.8;
	array[1][1] = -0.8;
	array[2][0] = 0.8;
	array[2][1] = -0.8;
	array[3][0] = 0;
	array[3][1] = 0;
}

//Function: Find the mid point between the two points
// return type: void
// parameters: double p1[2], double p2[2], double mid[2]
//			   store the midpoint in double mid[2]
void findMidPoint(double p1[2], double p2[2], double mid[2]) {
	mid[0] = (p1[0] + p2[0]) / 2;
	mid[1] = (p1[1] + p2[1]) / 2;
}

//Function: generate points in serpensiki gasket
// return type: void
// parameters: void
void generatePoints()
{
	initializeArray(array);
	double selectedPoint[2];
	double lastPoint[2];
	double midPoint[2];
	for (int i = 0; i < MAX + 4; i++) {
		int randomIndex = rand() % 3;


		selectedPoint[0] = array[randomIndex][0];
		selectedPoint[1] = array[randomIndex][1];
		lastPoint[0] = array[3 + i][0];
		lastPoint[1] = array[3 + i][1];

		findMidPoint(selectedPoint, lastPoint, midPoint);

		array[4 + i][0] = midPoint[0];
		array[4 + i][1] = midPoint[1];
	}
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

	//Initialize random numbers with a seed value as the current timestamp
	srand(clock());

	//generate serpenski gasket points
	generatePoints();

	//register the callback for displaying
	glutDisplayFunc(display);

	//star the opengl loop 
	glutMainLoop();
}