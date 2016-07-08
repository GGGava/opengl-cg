#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Model.h"
GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
GLfloat ambient[] = {1.0, 1.0, 1.0, 0.1};
GLfloat position[] = {0.0, 2.0, 0.0, 0.0};

void repaint() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawModel();
	glutSwapBuffers();
}

void keyboard( unsigned char key, int x, int y) {
	switch(key)
	{
		case 'w': SCALE -= 0.025; break;
		case 's': SCALE += 0.025; break;
		case 'a': rotateAngle += 2; break;
		case 'd': rotateAngle -= 2; break;
	}
	glutPostRedisplay();
}

void init() {
	glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("OpenGL - Movimento");
	glClearColor (0.0,0.0,0.0,0.0);

	glViewport(0, 0, (GLsizei) 800, (GLsizei) 600);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective((GLdouble)40.0, (GLdouble) 1.0, (GLdouble)1.0, (GLdouble)100.0);

	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.0,0., -3.0);

	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    
	glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glutDisplayFunc(&repaint);
	glutIdleFunc(&repaint);
	glutKeyboardFunc(&keyboard);
	glutMainLoop () ;
}

int main (int argc, char** argv) {
	glutInit(&argc, argv);
	init();
	return 0;
}