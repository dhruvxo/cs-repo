#include<gl/glut.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<stdio.h>
#define MAX 100000

double array[MAX][2];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glVertex2f(-1,-1);
    glVertex2f(0,1);
    glVertex2f(1,-1);
    glEnd;

glFlush();
}