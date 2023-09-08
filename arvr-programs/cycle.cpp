#include <GL/glut.h>
#include <cmath>

const int sides = 100; // Number of sides of the wheel
float wheelAngle1 = 0.0f;
float wheelX = -1.0f;
float wheelAngle2 = 0.0f;
float wheelY = 0.0f;
float wheelVelX = 0.004f;
float wheelVelY = 0.004f;
float wheelRadialX = 1.0f;
float wheelRadialY = 1.0f;
float bodyX = -1.0f;
float bodyAngle = 0.0f;
float bodyVel = 0.004f;
float bodyRadial = 0.0f;
void drawWheel() {
    // Draw the outer circle of the wheel
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < sides; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(sides);
        float x = 0.125f * cosf(theta);
        float y = 0.125f * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw spokes
    glBegin(GL_LINES);
    for (int i = 0; i < 10; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(10);
        float x1 = 0.0f;
        float y1 = 0.0f;
        float x2 = 0.125f * cosf(theta);
        float y2 = 0.125f * sinf(theta);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
}
void drawBody(){
    glBegin(GL_LINES);

    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.3f);
    glVertex2f(0.0f,0.3f);
    glVertex2f(1.0f,0.3f);
    glVertex2f(1.0f,0.3f);
    glVertex2f(1.0f,0.0f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    glLoadIdentity();

    // Translate and rotate the wheel
    glTranslatef(wheelX, 0.0f, 0.0f);
    glRotatef(wheelAngle1, 0.0f, 0.0f, 1.0f);

    // Call the function to draw the wheel
    drawWheel();
    glLoadIdentity();

    glTranslatef(wheelY, 0.0f, 0.0f);;
    glRotatef(wheelAngle2, 0.0f, 0.0f, 1.0f);

    drawWheel();

    glLoadIdentity();
    glTranslatef(bodyX, 0.0f, 0.0f);
    glRotatef(bodyAngle, 0.0f, 1.0f, 0.0f);
    drawBody();
    glFlush();
}

void update(int value) {
    // Rotate the wheel
    wheelAngle1 -= wheelRadialX;
    if (wheelAngle1 >= 360.0f) {
        wheelAngle1 -= 360.0f;
    }
    wheelAngle2 -= wheelRadialY;
    if (wheelAngle2 >= 360.0f) {
        wheelAngle2 -= 360.0f;
    }

    // Move the wheel forward
    wheelX += wheelVelX;
    bodyX += bodyVel;
    bodyAngle += bodyRadial;

    if (wheelX < -1.0f) {
        wheelVelX *= -1.0f;
        wheelRadialX *=-1.0f;
        wheelVelY*=-1.0f;
        wheelRadialY *=-1.0f;
        bodyVel*=-1.0f;
    }

    wheelY += wheelVelY;
    if (wheelY >= 1.0f) {
        wheelVelX *= -1.0f;
        wheelRadialX *=-1.0f;
        wheelVelY*=-1.0f;
        wheelRadialY *=-1.0f;
        bodyVel*=-1.0f;
    }

    
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Moving wheel");

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glClearColor(0.0, 0.0, 0.0, 0.0); // Set clear color to black

    glutMainLoop();
    return 0;
}
