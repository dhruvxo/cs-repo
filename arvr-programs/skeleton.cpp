#include <gl/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw the head
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.5);
    glEnd();
    
    // Draw the body
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.5);
    glVertex2f(0.0, 0.2);
    glEnd();
    
    // Draw the arms
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.4);
    glVertex2f(-0.2, 0.2);
    glVertex2f(0.0, 0.4);
    glVertex2f(0.2, 0.2);
    glEnd();
    
    // Draw the legs
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.2);
    glVertex2f(-0.2, 0.0);
    glVertex2f(0.0, 0.2);
    glVertex2f(0.2, 0.0);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Skeleton");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}