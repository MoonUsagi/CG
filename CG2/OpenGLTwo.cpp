#include <math.h>
#include <stdio.h>
#include "glut.h" 


#define PI 3.14159
float theta = 1.0;
bool ck = true;
float x = 0.0;
float y = 0.0;


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);         //清除所有像素
	glMatrixMode(GL_PROJECTION);

	float thetar = theta * PI / (180);
	float point[360][2];
	float angle = 0;
	for (int i = 0; i < 360; i++)
	{
		float a = 2 * cos(angle);
		float b = 1 * sin(angle);
		point[i][0] = a*cos(thetar) - b*sin(thetar) + x;
		point[i][1] = a*sin(thetar) + b*cos(thetar) + y;
		angle = angle + (PI / 180);
	}

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		glVertex3f(point[i][0], point[i][1], 0.0);
	}
	glEnd();
	glFlush();
	glutSwapBuffers();
	
}

void mySpin(void)
{
	/* increase the theta */

				/* increase 2 degree */
		if (ck)
		{
			theta += 1.0;
			if (theta >= 360.0) theta = 0.0;
		}
		else
		{
			theta -= 1.0;
			if (theta <= 0.0) theta = 360.0;
		}

		
	glutPostRedisplay();
}

void myMenu(int id)
{
	switch (id)
	{
	case 1:
		exit(0);
	}
}

void mySubMenu(int id)
{
	switch (id)
	{
	case 2:
			  glutIdleFunc(mySpin);
			  break;
	case 3:
			  glutIdleFunc(NULL);
			  break;
	case 4:
		ck = false;
		     break;
	case 5:
		ck = true;
		     break;
	case 6:
		x += 1.0;
		break;
	case 7:
		x -= 1.0;
		break;
	case 8:
		y += 1.0;
		break;
	case 9:
		y -= 1.0;
		break;
	}
}


void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glLoadIdentity();
	glOrtho(-2.5, 2.5, -2.5, 2.5, -1.0, 1.0);

	int a_menu = glutCreateMenu(mySubMenu);
	glutAddMenuEntry("Start", 2);
	glutAddMenuEntry("Abort", 3);
	int b_menu = glutCreateMenu(mySubMenu);
	glutAddMenuEntry("Clockwise", 4);
	glutAddMenuEntry("Counterlockwise", 5);
	int c_menu = glutCreateMenu(mySubMenu);
	glutAddMenuEntry("Increase x", 6);
	glutAddMenuEntry("Decrease x", 7);
	glutAddMenuEntry("Increase y", 8);
	glutAddMenuEntry("Decrease y", 9);


	glutCreateMenu(myMenu);
	glutAddSubMenu("Rotation", a_menu);
	glutAddSubMenu("Direction", b_menu);
	glutAddSubMenu("Translation", c_menu);
	glutAddMenuEntry("Quit", 1);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}



int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(myDisplay);

	myInit();
	glutMainLoop();
	return 0;
}