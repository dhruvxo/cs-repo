#include <GL/glut.h>
#include <cstdlib> // for the exit function

// Camera variables
float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;
float cameraDistance = 5.0f;

// Skeleton position
float skeletonX = 0.0f;
float skeletonZ = 0.0f;

// Skeleton variables (modify this function to draw your 3D skeleton)
void drawSkeleton() {
    // Example: Draw a simple skeleton at the updated position
    glPushMatrix();
    glTranslatef(skeletonX, 0.0f, skeletonZ);

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

    glPopMatrix(); // Restore the original matrix
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

void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        skeletonZ -= 0.1f; // Move skeleton forward
        break;
    case GLUT_KEY_DOWN:
        skeletonZ += 0.1f; // Move skeleton backward
        break;
    case GLUT_KEY_LEFT:
        skeletonX -= 0.1f; // Move skeleton left
        break;
    case GLUT_KEY_RIGHT:
        skeletonX += 0.1f; // Move skeleton right
        break;
    }
    glutPostRedisplay();
}

void reshape(int width, int height) {
    // Set the viewport to cover the new window size
    glViewport(0, 0, width, height);

    // Set up the projection matrix (you can adjust this as needed)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);

    // Switch back to the modelview matrix
    glMatrixMode(GL_MODELVIEW);
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
