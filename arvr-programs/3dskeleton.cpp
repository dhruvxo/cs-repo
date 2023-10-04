#include <GL/glut.h>
#include <cstdlib> // for the exit function

// Camera variables
float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;
float cameraDistance = 5.0f;

// Skeleton variables (modify this function to draw your 3D skeleton)
void drawSkeleton() {
    // Example: Draw a simple skeleton
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    // Neck
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f); // Move neck up
    glScalef(0.15f, 0.2f, 0.15f); // Scale to create a neck shape
    glutSolidCube(1.0f);
    glPopMatrix();

    // Head
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f); // Move head up from the neck
    glutSolidSphere(0.2f, 20, 20);
    glPopMatrix();

    // Body
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f); // Body position
    glScalef(0.4f, 0.8f, 0.2f); // Scale to make it narrower and taller
    glutSolidCube(1.0f);
    glPopMatrix();

    // Left Arm
    glPushMatrix();
    glTranslatef(-0.4f, 0.4f, 0.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.15f, 0.6f, 0.15f); // Slimmer arm
    glutSolidCube(1.0f);
    glPopMatrix();

    // Right Arm
    glPushMatrix();
    glTranslatef(0.4f, 0.4f, 0.0f);
    glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.15f, 0.6f, 0.15f); // Slimmer arm
    glutSolidCube(1.0f);
    glPopMatrix();

    // Left Leg (Slim Rectangle)
    glPushMatrix();
    glTranslatef(-0.2f, -0.5f, 0.0f);
    glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
    glScalef(0.1f, 0.6f, 0.1f); // Slim rectangle shape
    glutSolidCube(1.0f);
    glPopMatrix();

    // Right Leg (Slim Rectangle)
    glPushMatrix();
    glTranslatef(0.2f, -0.5f, 0.0f);
    glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
    glScalef(0.1f, 0.6f, 0.1f); // Slim rectangle shape
    glutSolidCube(1.0f);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set camera position and orientation
    glTranslatef(0.0f, 0.0f, -cameraDistance);
    glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f);

    // Draw the skeleton
    drawSkeleton();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        cameraAngleX += 5.0f;
        break;
    case 's':
        cameraAngleX -= 5.0f;
        break;
    case 'a':
        cameraAngleY -= 5.0f;
        break;
    case 'd':
        cameraAngleY += 5.0f;
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

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Skeleton with Arrow Key Camera Control");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}