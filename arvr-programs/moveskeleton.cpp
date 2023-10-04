#include <GL/glut.h>
#include <cstdlib> // for the exit function
#include <cmath>

// Camera variables
float cameraAngleX = 30.0f;
float cameraAngleY = 0.0f;
float cameraDistance = 5.0f;

// Camera target (point the camera is looking at)
float targetX = 0.0f;
float targetY = 0.0f;
float targetZ = 0.0f;

// Skeleton position variables
float skeletonPosX = 0.0f;
float skeletonPosY = 1.2f;
float skeletonPosZ = 0.0f;

// Skeleton movement speed
float movementSpeed = 0.1f;

// Animation variables
float armAngle = 0.0f;
float legAngle = 0.0f;
bool isWalking = false;

// Ground variables
float groundSize = 10.0f;

// Skeleton variables (modify this function to draw your 3D skeleton)
void drawSkeleton() {
    // Example: Draw a simple skeleton
    glPushMatrix();
    glTranslatef(skeletonPosX, skeletonPosY, skeletonPosZ);
    // Example: Draw a simple skeleton
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    // Head
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glutSolidSphere(0.2f, 20, 20);
    glPopMatrix();

    // Body
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(0.4f, 1.0f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Left Arm
    glPushMatrix();
    glTranslatef(-0.4f, 0.5f, 0.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.2f, 0.8f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Right Arm
    glPushMatrix();
    glTranslatef(0.4f, 0.5f, 0.0f);
    glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.2f, 0.8f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Left Leg (3D oval approximation)
    glPushMatrix();
    glTranslatef(-0.2f, -0.8f, 0.0f);
    glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
    glScalef(0.2f, 0.8f, 0.5f);
    glutSolidSphere(0.5f, 20, 20);
    glPopMatrix();

    // Right Leg (3D oval approximation)
    glPushMatrix();
    glTranslatef(0.2f, -0.8f, 0.0f);
    glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
    glScalef(0.2f, 0.8f, 0.5f);
    glutSolidSphere(0.5f, 20, 20);
    glPopMatrix();
    glPopMatrix();
}

void drawGround() {
    glColor3f(0.0f, 1.0f, 0.0f); // Green color

    glBegin(GL_QUADS);
    glVertex3f(-groundSize, 0.0f, -groundSize);
    glVertex3f(-groundSize, 0.0f, groundSize);
    glVertex3f(groundSize, 0.0f, groundSize);
    glVertex3f(groundSize, 0.0f, -groundSize);
    glEnd();
}

void updateAnimation(int value) {
    // Toggle walking animation
    isWalking = !isWalking;

    // Update arm and leg angles
    if (isWalking) {
        armAngle = 20.0f * sin(legAngle * 3.141592653589793 / 180);
        legAngle += 5.0f;
    }
    else {
        armAngle = 0.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(100, updateAnimation, 0); // 100 milliseconds update interval
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set camera position and orientation
    glTranslatef(0.0f, -1.0f, -cameraDistance); // Adjust the camera distance
    glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f);

    // Look at the target
    gluLookAt(
        0.0f, 0.0f, cameraDistance, // Camera position
        targetX, targetY, targetZ, // Target position
        0.0f, 1.0f, 0.0f           // Up direction
    );

    // Draw the ground
    drawGround();

    // Draw the skeleton
    drawSkeleton();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        skeletonPosZ -= movementSpeed * cos(cameraAngleY * 3.141592653589793 / 180);
        skeletonPosX += movementSpeed * sin(cameraAngleY * 3.141592653589793 / 180);
        break;
    case 's':
        skeletonPosZ += movementSpeed * cos(cameraAngleY * 3.141592653589793 / 180);
        skeletonPosX -= movementSpeed * sin(cameraAngleY * 3.141592653589793 / 180);
        break;
    case 'd':
        skeletonPosZ += movementSpeed * sin(cameraAngleY * 3.141592653589793 / 180);
        skeletonPosX += movementSpeed * cos(cameraAngleY * 3.141592653589793 / 180);
        break;
    case 'a':
        skeletonPosZ -= movementSpeed * sin(cameraAngleY * 3.141592653589793 / 180);
        skeletonPosX -= movementSpeed * cos(cameraAngleY * 3.141592653589793 / 180);
        break;
    case 'i': // Zoom in
        cameraDistance -= 0.1f;
        break;
    case 'o': // Zoom out
        cameraDistance += 0.1f;
        break;
    case 27: // Escape key
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        cameraAngleX += 5.0f;
        break;
    case GLUT_KEY_DOWN:
        cameraAngleX -= 5.0f;
        break;
    case GLUT_KEY_LEFT:
        cameraAngleY -= 5.0f;
        break;
    case GLUT_KEY_RIGHT:
        cameraAngleY += 5.0f;
        break;
    }
    glutPostRedisplay();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Skeleton with Animation, Zoom, and Green Ground");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glEnable(GL_DEPTH_TEST);

    glutTimerFunc(100, updateAnimation, 0); // Start the animation timer

    glutMainLoop();

    return 0;
}
