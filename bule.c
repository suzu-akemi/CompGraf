
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "esfera.h"
#include "cubo.h"
#include "cone.h"

GLfloat AspectRatio;
GLfloat AngY;
int fazCalculoPonto;

GLfloat AnguloDeVisao;
GLfloat Obs[3];
GLfloat Alvo[3];

float esfera_rotacao_X=0;
float esfera_rotacao_Y=0;
float esfera_rotacao_Z=0;

float cone_rotacao_X=0;
float cone_rotacao_Y=0;
float cone_rotacao_Z=0;

float cubo_rotacao_X=0;
float cubo_rotacao_Y=0;
float cubo_rotacao_Z=0;

void init(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Fundo preto

	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	Obs[0] = 0;
	Obs[1] = 3;
	Obs[2] = 3;
	Alvo[0] = 0;
	Alvo[1] = 0;
	Alvo[2] = -1;
	AnguloDeVisao = 70;
	AngY = 0;
	fazCalculoPonto = 0;
}

void PosicUser() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(AnguloDeVisao, AspectRatio, 0.01, 200);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(Obs[0], Obs[1], Obs[2], Alvo[0], Alvo[1], Alvo[2], 0.0f, 1.0f, 0.0f);
}

void reshape(int w, int h) {
	if (h == 0) h = 1;

	AspectRatio = 1.0f * w / h;

	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, 700, 500);
	PosicUser();
}

void DesenhaCenario() {
	glPopMatrix();
	glColor3f(1.0,0.0,1.0);
	glutSolidTeapot(1.0);
	glColor3f(0.0,0.0,1.0);
	glutWireTeapot(1.0);


	glPushMatrix();

}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glRotatef(AngY, 0.0f, 0.0f, 1.0f);


	PosicUser();
	DesenhaCenario(1);
	esfera_rotacao_X+=8;
	esfera_rotacao_Y+=8;
	esfera_rotacao_Z+=8;

	cone_rotacao_X+=8;
	cone_rotacao_Y+=8;
	cone_rotacao_Z+=8;

	cubo_rotacao_X+=8;
	cubo_rotacao_Y+=8;
	cubo_rotacao_Z+=8;

	glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: // ESC
		exit(0);
		break;
	case ' ':
		fazCalculoPonto = 1;
		break;
	case 'a':
	case 'A':
		AngY += 5;
		break;
	default:
		break;
	}
}


void arrow_keys(int a_keys, int x, int y) {
	switch (a_keys) {
	case GLUT_KEY_UP:
		glutFullScreen();
		break;
	case GLUT_KEY_DOWN:
		glutInitWindowSize(700, 500);
		break;
	default:
		break;
	}
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(700, 500);
	glutCreateWindow("Computação Gráfica - Transformações Hierárquicas 3D");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(arrow_keys);
	glutIdleFunc(display);

	glutMainLoop();
	return 0;
}
