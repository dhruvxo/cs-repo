#include <GL/glut.h>
#include <cstdlib> // for the exit function

// Camera variables
float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;
float cameraDistance = 5.0f;

// Skeleton variables (modify this function to draw your 3D skeleton)
void drawSkeleton() {
    //glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    // Upper Body (above the waist)
    glPushMatrix();
    glTranslatef(0.0f, 0.3f, 0.0f); // Position the upper body
    glScalef(0.4f, 0.6f, 0.2f); // Adjust the dimensions of the upper body
    glColor3f(0.8f, 0.6f, 0.4f); // Light brown color
    glutSolidCube(1.0f);
    glPopMatrix();

    // Lower Body (waist)
    glPushMatrix();
    glTranslatef(0.0f, -0.2f, 0.0f); // Position the waist/body to connect to the neck and legs
    glScalef(0.4f, 0.4f, 0.2f); // Adjust the dimensions of the waist/body
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glutSolidCube(1.0f);
    glPopMatrix();

    // Neck
    glPushMatrix();
    glTranslatef(0.0f, 0.75f, 0.0f); // Position the neck between the upper body and head
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    GLUquadricObj* neck = gluNewQuadric();
    gluQuadricDrawStyle(neck, GLU_FILL);

    // Set the color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    gluCylinder(neck, 0.08, 0.08, 0.4, 20, 20); // Thinner neck (adjust the radius here)
    glPopMatrix();


    // Head
    glPushMatrix();
    glTranslatef(0.0f, 0.95f, 0.0f); // Position the head on top of the neck
    glColor3f(0.8f, 0.6f, 0.4f); // Light brown color for the head
    glutSolidSphere(0.2f, 20, 20);
    glPopMatrix();

    // Shoulder Joints
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // White color for the shoulder joints
    glTranslatef(-0.25f, 0.55f, 0.0f); // Position the left shoulder joint
    glutSolidSphere(0.12f, 20, 20); // Create a spherical shoulder joint
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // White color for the shoulder joints
    glTranslatef(0.25f, 0.55f, 0.0f); // Position the right shoulder joint
    glutSolidSphere(0.12f, 20, 20); // Create a spherical shoulder joint
    glPopMatrix();

    // Left Arm (Upper Arm)
    glPushMatrix();
    glTranslatef(-0.4f, 0.4f, 0.0f); // Position the left upper arm with a gap and make it longer
    glScalef(0.15f, 0.4f, 0.15f); // Adjust the dimensions of the left upper arm
    glColor3f(0.8f, 0.6f, 0.4f); // Light brown color for the left upper arm
    glutSolidCube(1.0f);
    glPopMatrix();

    // Left Arm Joint (Elbow)
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // White color for the joints
    glTranslatef(-0.4f, 0.2f, 0.0f); // Position the left elbow joint
    glutSolidSphere(0.12f, 20, 20); // Create a spherical elbow joint
    glPopMatrix();

    // Left Arm (Lower Arm)
    glPushMatrix();
    glTranslatef(-0.4f, 0.0f, 0.0f); // Position the left lower arm
    glRotatef(15.0f, 0.0f, 0.0f, 1.0f); // Rotate the left lower arm slightly
    glScalef(0.15f, 0.5f, 0.15f); // Adjust the dimensions of the left lower arm
    glColor3f(0.8f, 0.6f, 0.4f); // Light brown color for the left lower arm
    glutSolidCube(1.0f);
    glPopMatrix();

    // Right Arm (Upper Arm)
    glPushMatrix();
    glTranslatef(0.4f, 0.4f, 0.0f); // Position the right upper arm with a gap and make it longer
    glScalef(0.15f, 0.4f, 0.15f); // Adjust the dimensions of the right upper arm
    glColor3f(0.8f, 0.6f, 0.4f); // Light brown color for the right upper arm
    glutSolidCube(1.0f);
    glPopMatrix();

    // Right Arm Joint (Elbow)
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // White color for the joints
    glTranslatef(0.4f, 0.2f, 0.0f); // Position the right elbow joint
    glutSolidSphere(0.12f, 20, 20); // Create a spherical elbow joint
    glPopMatrix();

    // Right Arm (Lower Arm)
    glPushMatrix();
    glTranslatef(0.4f, 0.0f, 0.0f); // Position the right lower arm
    glRotatef(-15.0f, 0.0f, 0.0f, 1.0f); // Rotate the right lower arm slightly
    glScalef(0.15f, 0.5f, 0.15f); // Adjust the dimensions of the right lower arm
    glColor3f(0.8f, 0.6f, 0.4f); // Light brown color for the right lower arm
    glutSolidCube(1.0f);
    glPopMatrix();

    // Legs (Upper Leg)
    glPushMatrix();
    glTranslatef(-0.15f, -0.45f, 0.0f); // Position the left upper leg
    // Make the left upper leg slightly shorter
    glScalef(0.15f, 0.35f, 0.15f); // Adjust the dimensions of the left upper leg
    glColor3f(0.8f, 0.6f, 0.4f); // Light brown color for the left upper leg
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15f, -0.45f, 0.0f); // Position the right upper leg
    // Make the right upper leg slightly shorter
    glScalef(0.15f, 0.35f, 0.15f); // Adjust the dimensions of the right upper leg
    glColor3f(0.8f, 0.6f, 0.4f); // Light brown color for the right upper leg
    glutSolidCube(1.0f);
    glPopMatrix();

    // Left Leg Joint (Knee)
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // White color for the joints
    glTranslatef(-0.15f, -0.7f, 0.0f); // Position the left knee joint
    glutSolidSphere(0.12f, 20, 20); // Create a spherical knee joint
    glPopMatrix();

    // Right Leg Joint (Knee)
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // White color for the joints
    glTranslatef(0.15f, -0.7f, 0.0f); // Position the right knee joint
    glutSolidSphere(0.12f, 20, 20); // Create a spherical knee joint
    glPopMatrix();

    // Legs (Lower Leg)
    glPushMatrix();
    glTranslatef(-0.15f, -0.95f, 0.0f); // Position the left lower leg
    // Make the left lower leg longer
    glScalef(0.15f, 0.6f, 0.15f); // Adjust the dimensions of the left lower leg
    glColor3f(0.8f, 0.6f, 0.4f); // Light brown color for the left lower leg
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15f, -0.95f, 0.0f); // Position the right lower leg
    // Make the right lower leg longer
    glScalef(0.15f, 0.6f, 0.15f); // Adjust the dimensions of the right lower leg
    glColor3f(0.8f, 0.6f, 0.4f); // Light brown color for the right lower leg
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