#include <GL/glut.h>
#include <GL/GL.h>

float angle = 0;
float camX = 0.0f;
float camY = 10.0f;
float camZ = 15.0f;
float tX = 0.0f;
float tY = 0.0f;
float tZ = 0.0f;
float cameraSpeed = 0.1f; // Speed of camera movement
float teapot1X = 2.0f;
float teapot2X = -2.0f;

void setMaterial(GLfloat ambientR, GLfloat ambientG, GLfloat ambientB,
    GLfloat diffuseR, GLfloat diffuseG, GLfloat diffuseB,
    GLfloat specularR, GLfloat specularG, GLfloat specularB,
    GLfloat shininess) {

    GLfloat ambient[] = { ambientR, ambientG, ambientB };
    GLfloat diffuse[] = { diffuseR, diffuseG, diffuseB };
    GLfloat specular[] = { specularR, specularG, specularB };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

void keyBoard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        camZ -= cameraSpeed;
        break;
    case 's':
        camZ += cameraSpeed;
        break;
    case 'a':
        camX -= cameraSpeed;
        break;
    case 'd':
        camX += cameraSpeed;
        break;
    }

    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        camY += cameraSpeed;
        break;
    case GLUT_KEY_DOWN:
        camY -= cameraSpeed;
        break;
    case GLUT_KEY_LEFT:
        teapot1X -= cameraSpeed;
        break;
    case GLUT_KEY_RIGHT:
        teapot1X += cameraSpeed;
        break;
    }

    glutPostRedisplay();
}

void display() {
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        camX, camY, camZ,
        tX, tY, tZ,
        0.0f, 1.0f, 0.0f
    );
    glTranslatef(tX, tY, tZ);

    glPushMatrix();
    glColor3f(0.957, 0.643, 0.376);
    setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
    glTranslatef(teapot1X, 0, 0);
    glRotatef(angle, 1, 0, 0);
    glutSolidTeapot(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.957, 0.643, 0.376);
    setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
    glTranslatef(teapot2X, 0, 0);
    glRotatef(angle, 1, 0, 0);
    glutSolidTeapot(1);
    glPopMatrix();

    /* flush drawing routines to the window */
    glFlush();
}

void reshape(int width, int height) {
    /* define the viewport transformation */
    glViewport(0, 0, width, height);
}

void initLight() {
    /* set up lights */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    GLfloat lightpos[] = { 0.0, 0.0, 15.0 };
    GLfloat lightcolor[] = { 0.5, 0.5, 0.5 };
    GLfloat ambcolor[] = { 0.2, 0.2, 0.2 };
    GLfloat specular[] = { 1.0, 1.0, 1.0 };

    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambcolor);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightcolor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    glEnable(GL_COLOR_MATERIAL); // tells OpenGL to maintain the original color of the object
}

void animate() {
    angle = angle + 0.1;
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    /* initialize GLUT, using any command-line parameters passed to the program */
    glutInit(&argc, argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

    /* create and set up a window */
    glutCreateWindow("Two Teapots");
    glutDisplayFunc(display);

    /* set up depth-buffering */
    glEnable(GL_DEPTH_TEST);

    initLight();

    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 4, 100);

    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

    // register the IdleFunction
    glutIdleFunc(animate);

    // Register keyboard and arrow key functions
    glutKeyboardFunc(keyBoard);
    glutSpecialFunc(specialKeys);

    /* tell GLUT to wait for events */
    glutMainLoop();
}