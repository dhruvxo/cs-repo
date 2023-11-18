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
float skeletonPosY = 0.0f;
float skeletonPosZ = 0.0f;

// Leg rotation angles
    float leftLegAngle = 0.0f;
    float rightLegAngle = 0.0f;

// Leg animation parameters
float legRotationSpeed = 2.0f; // Adjust the rotation speed as needed
bool legDirectionForward = true;

// Lower leg rotation angles
float leftLowerLegAngle = 0.0f;
float rightLowerLegAngle = 0.0f;

// Lower leg animation parameters
float lowerLegRotationSpeed = 2.0f; // Adjust the rotation speed as needed
bool lowerLegDirectionForward = true;

// Arm rotation angles
float leftUpperArmAngle = 0.0f;
float rightUpperArmAngle = 0.0f;
float leftLowerArmAngle = 0.0f;
float rightLowerArmAngle = 0.0f;

// Arm animation parameters
float armRotationSpeed = 2.0f; // Adjust the rotation speed as needed
bool armDirectionForward = true;

int prevMouseX;
int prevMouseY;
bool mouseRotate = false;

// Ground size variable
float groundSize = 10.0f;

// Skeleton movement speed
float movementSpeed = 0.1f;

// Skeleton variables (modify this function to draw your 3D skeleton)
void drawSkeleton() {
    // Upper Body (above the waist)
    glPushMatrix();
    glTranslatef(0.0f, 0.3f, 0.0f); // Position the upper body
    glScalef(0.4f, 0.6f, 0.2f); // Adjust the dimensions of the upper body
    // Set material properties for the upper body
    GLfloat ambient[] = { 0.8f, 0.6f, 0.4f, 1.0f };
    GLfloat diffuse[] = { 0.8f, 0.6f, 0.4f, 1.0f };
    GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat shininess = 128.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
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
    glRotatef(leftUpperArmAngle, 1.0f, 0.0f, 0.0f); // Rotate the left upper arm
    glScalef(0.15f, 0.4f, 0.15f); // Adjust the dimensions of the left upper arm
    glColor3f(0.8f, 0.6f, 0.4f); // Light brown color for the left upper arm
    glutSolidCube(1.0f);

    // Left Arm (Lower Arm)
    glPushMatrix();
    glTranslatef(0.0f, -0.5f, 0.0f); // Adjust position to connect with upper arm
    glRotatef(leftUpperArmAngle + leftLowerArmAngle, 1.0f, 0.0f, 0.0f); // Rotate the left lower arm relative to upper arm
    glScalef(1.0f, 1.5f, 1.0f); // Adjust the dimensions of the left lower arm
    glutSolidCube(1.0f);
    glPopMatrix();

    glPopMatrix();

    // Right Arm (Upper Arm)
    glPushMatrix();
    glTranslatef(0.4f, 0.4f, 0.0f); // Position the right upper arm with a gap and make it longer
    glRotatef(rightUpperArmAngle, 1.0f, 0.0f, 0.0f); // Rotate the right upper arm
    glScalef(0.15f, 0.4f, 0.15f); // Adjust the dimensions of the right upper arm
    glColor3f(0.8f, 0.6f, 0.4f); // Light brown color for the right upper arm
    glutSolidCube(1.0f);

    // Right Arm (Lower Arm)
    glPushMatrix();
    glTranslatef(0.0f, -0.5f, 0.0f); // Adjust position to connect with upper arm
    glRotatef(rightUpperArmAngle + rightLowerArmAngle, 1.0f, 0.0f, 0.0f); // Rotate the right lower arm relative to upper arm
    glScalef(1.0f, 1.5f, 1.0f); // Adjust the dimensions of the right lower arm
    glutSolidCube(1.0f);
    glPopMatrix();

    glPopMatrix();

}


void drawGround() {
    glColor3f(0.4f, 0.2f, 0.0f);
    // Set material properties for the ground
    GLfloat ambient[] = { 0.4f, 0.2f, 0.0f, 1.0f };
    GLfloat diffuse[] = { 0.4f, 0.2f, 0.0f, 1.0f };
    GLfloat specular[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // No specular reflection
    GLfloat shininess = 0.0f; // No shininess
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    glBegin(GL_QUADS);
    glVertex3f(-groundSize, 0.0f, -groundSize);
    glVertex3f(-groundSize, 0.0f, groundSize);
    glVertex3f(groundSize, 0.0f, groundSize);
    glVertex3f(groundSize, 0.0f, -groundSize);
    glEnd();
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

    // Update leg rotation angles for animation
    if (legDirectionForward) {
        leftLegAngle += legRotationSpeed;
        rightLegAngle -= legRotationSpeed;
        leftLowerLegAngle += legRotationSpeed;
        rightLowerLegAngle -= legRotationSpeed;
    }
    else {
        leftLegAngle -= legRotationSpeed;
        rightLegAngle += legRotationSpeed;
        leftLowerLegAngle -= legRotationSpeed;
        rightLowerLegAngle += legRotationSpeed;
    }

    // Check leg rotation direction
    if (leftLegAngle >= 45.0f) {
        legDirectionForward = false;
    }
    else if (leftLegAngle <= -45.0f) {
        legDirectionForward = true;
    }

    // Update lower leg rotation angles for animation
    if (lowerLegDirectionForward) {
        leftLowerLegAngle += lowerLegRotationSpeed;
        rightLowerLegAngle -= lowerLegRotationSpeed;
    }
    else {
        leftLowerLegAngle -= lowerLegRotationSpeed;
        rightLowerLegAngle += lowerLegRotationSpeed;
    }

    // Check lower leg rotation direction
    if (leftLowerLegAngle >= 45.0f) {
        lowerLegDirectionForward = false;
    }
    else if (leftLowerLegAngle <= -45.0f) {
        lowerLegDirectionForward = true;
    }

    // Update arm rotation angles for animation
    if (armDirectionForward) {
        leftUpperArmAngle += armRotationSpeed;
        rightUpperArmAngle -= armRotationSpeed;
        leftLowerArmAngle += armRotationSpeed;
        rightLowerArmAngle -= armRotationSpeed;
    }
    else {
        leftUpperArmAngle -= armRotationSpeed;
        rightUpperArmAngle += armRotationSpeed;
        leftLowerArmAngle -= armRotationSpeed;
        rightLowerArmAngle += armRotationSpeed;
    }

    // Check arm rotation direction
    if (leftUpperArmAngle >= 45.0f || leftUpperArmAngle <= -45.0f) {
        armDirectionForward = !armDirectionForward; // Reverse direction for both arms
    }


    // Draw the skeleton
    glPushMatrix();
    glTranslatef(skeletonPosX, skeletonPosY, skeletonPosZ);

    // Left Leg (Upper Leg)
    glPushMatrix();
    glTranslatef(-0.15f, -0.45f, 0.0f);
    glRotatef(leftLegAngle, 1.0f, 0.0f, 0.0f); // Rotate the left upper leg
    glScalef(0.15f, 0.35f, 0.15f);
    glColor3f(0.8f, 0.6f, 0.4f);
    glutSolidCube(1.0f);

    // Left Leg (Lower Leg)
    glPushMatrix();
    glTranslatef(0.0f, -0.5f, 0.0f); // Adjust position to connect with upper leg
    glRotatef(leftLowerLegAngle, 1.0f, 0.0f, 0.0f); // Rotate the left lower leg
    glScalef(1.0f, 1.5f, 1.0f); // Adjust the dimensions of the left lower leg
    glutSolidCube(1.0f);
    glPopMatrix();

    glPopMatrix();

    // Right Leg (Upper Leg)
    glPushMatrix();
    glTranslatef(0.15f, -0.45f, 0.0f);
    glRotatef(rightLegAngle, 1.0f, 0.0f, 0.0f); // Rotate the right upper leg
    glScalef(0.15f, 0.35f, 0.15f);
    glColor3f(0.8f, 0.6f, 0.4f);
    glutSolidCube(1.0f);

    // Right Leg (Lower Leg)
    glPushMatrix();
    glTranslatef(0.0f, -0.5f, 0.0f); // Adjust position to connect with upper leg
    glRotatef(rightLowerLegAngle, 1.0f, 0.0f, 0.0f); // Rotate the right lower leg
    glScalef(1.0f, 1.5f, 1.0f); // Adjust the dimensions of the right lower leg
    glutSolidCube(1.0f);
    glPopMatrix();

    glPopMatrix();

    drawSkeleton();
    glPopMatrix();

    // Calculate the lowest point of the skeleton (adjust this value if needed)
    float skeletonLowestPoint = skeletonPosY - 0.95f;

    // Draw the ground just below the skeleton
    glPushMatrix();
    glTranslatef(0.0f, skeletonLowestPoint - 0.3f, 0.0f); // Adjust the offset as needed
    drawGround();
    glPopMatrix();

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

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            prevMouseX = x;
            prevMouseY = y;
            mouseRotate = true;
        }
        else if (state == GLUT_UP) {
            mouseRotate = false;
        }
    }
}

void motion(int x, int y) {
    if (mouseRotate) {
        int deltaX = x - prevMouseX;
        int deltaY = y - prevMouseY;

        cameraAngleY += deltaX * 0.5f;
        cameraAngleX += deltaY * 0.5f;

        prevMouseX = x;
        prevMouseY = y;

        glutPostRedisplay();
    }
}

void initLighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Set up light position (directional light from above)
    GLfloat light_position[] = { 0.0f, 1.0f, 0.0f, 0.0f }; // Directional light from above
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // Set up light properties
    GLfloat ambient_light[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse_light[] = { 0.6f, 0.6f, 0.6f, 1.0f }; // Reduced intensity
    GLfloat specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // No specular reflection

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);

    // Enable lighting for the objects
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Reduce shininess
    glMaterialf(GL_FRONT, GL_SHININESS, 32.0f);
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
    glutCreateWindow("3D Skeleton");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse); // Add mouse callback for button press/release
    glutMotionFunc(motion); // Add mouse motion callback

    glEnable(GL_DEPTH_TEST);

    initLighting(); // Initialize lighting

    glutMainLoop();

    return 0;
}