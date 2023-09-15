#include <GL/glut.h>
#include <cstdlib> // for the exit function

// Camera variables
float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;
float cameraDistance = 5.0f;

// Arm segment function
void drawArmSegment() {
    glPushMatrix();
    glScalef(0.2f, 0.8f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

// Variables to control arm movement
float leftArmAngleX = 0.0f; // Rotation around X-axis (up and down)
float rightArmAngleX = 0.0f;
float armRotationSpeed = 0.0f;

// Skeleton variables (modify this function to draw your 3D skeleton)
void drawSkeleton() {

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    // Head
    glPushMatrix();
    glTranslatef(0.0f, 0.750f, 0.0f);
    glutSolidSphere(0.2f, 20, 20);
    glPopMatrix();

    // Body
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(0.4f, 1.0f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Left Arm (upper segment)
    glPushMatrix();
    glTranslatef(-0.4f, 0.5f, 0.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f); // Fixed angle (no up and down movement)
    glRotatef(leftArmAngleX, 1.0f, 0.0f, 0.0f); // Up and down movement
    drawArmSegment(); // Draw upper arm

    // Left Arm (lower segment)
    glPushMatrix();
    glTranslatef(0.0f, -0.3f, 0.0f); // Translate to lower arm position
    glRotatef(-45.0f, 0.0f, 0.0f, 0.5f);
    drawArmSegment(); // Draw lower arm
    glPopMatrix();

    glPopMatrix();

    // Right Arm (upper segment)
    glPushMatrix();
    glTranslatef(0.4f, 0.5f, 0.0f);
    glRotatef(-45.0f, 0.0f, 0.0f, 1.0f); // Fixed angle (no up and down movement)
    glRotatef(rightArmAngleX, 1.0f, 0.0f, 0.0f); // Up and down movement
    drawArmSegment(); // Draw upper arm

    // Right Arm (lower segment)
    glPushMatrix();
    glTranslatef(0.0f, -0.3f, 0.0f); // Translate to lower arm position
    glRotatef(45.0f, 0.0f, 0.0f, 0.5f);
    drawArmSegment(); // Draw lower arm
    glPopMatrix();

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
    case GLUT_KEY_LEFT:
        // Rotate the upper arms (left and right) around X-axis (up and down)
        if (leftArmAngleX < 90.0f)
            leftArmAngleX += armRotationSpeed;
        break;
    case GLUT_KEY_RIGHT:
        if (leftArmAngleX > -90.0f)
            leftArmAngleX -= armRotationSpeed;
        break;
    case GLUT_KEY_UP:
        if (rightArmAngleX < 90.0f)
            rightArmAngleX += armRotationSpeed;
        break;
    case GLUT_KEY_DOWN:
        if (rightArmAngleX > -90.0f)
            rightArmAngleX -= armRotationSpeed;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Skeleton with Camera Control");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}