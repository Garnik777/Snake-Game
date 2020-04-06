#include <GL/gl.h>
#include <GL/glut.h>
#include "draw.hpp" 
#include <iostream>

#define COLUMNS 40
#define ROWS    40
#define FPS     10

extern short sDirection;
extern bool gameOver;
int score = 0;

void timer_calback(int);
void display_calback();
void reshape_calback(int,int);
void keyboard_calback(int, int, int);

void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	initGrid(COLUMNS,ROWS);
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500,500);
	glutCreateWindow("SNAKE");
	glutDisplayFunc(display_calback);
	glutReshapeFunc(reshape_calback);
	glutTimerFunc(0,timer_calback,0);
	glutSpecialFunc(keyboard_calback);
	init();
	glutMainLoop();
	return 0;
}

int index = 0;

void display_calback()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawSnake();
	drawFood();	
	glutSwapBuffers();
	if (gameOver) {
		std::cout << "Your Score : " << score  <<  "\n GAME OVER\n";
		exit(0);
	}
}

void reshape_calback(int w, int h)
{
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
}

void timer_calback(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/FPS, timer_calback,0);
}

void keyboard_calback(int key, int, int)
{
	switch (key)
	{
		case GLUT_KEY_UP:
			if(sDirection != DOWN) {
				sDirection = UP;
				
			}
			break;
		case GLUT_KEY_DOWN:
			if( sDirection != UP) {
				sDirection = DOWN;
			}
			break;
		case GLUT_KEY_RIGHT:
			if(sDirection != LEFT) {
				sDirection = RIGHT;
			}
			break;
		case GLUT_KEY_LEFT:
			if(sDirection != RIGHT) {
				sDirection = LEFT;
			}
			break;		
	}
}
