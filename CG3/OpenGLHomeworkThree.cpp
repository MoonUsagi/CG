#include <math.h>
#include <stdio.h>
#include "glut.h" 


float x = 0.0;
float y = 0.0;

float angle = 1.0;
float gripper = 0.1;


float BaseLink_L = 0.4;
float BaseLink_W = 0.4;
float BaseLink_H = 0.4;

float LinkOne_L = 0.2;
float LinkOne_W = 0.2;
float LinkOne_H = 0.6;

float LinkTwo_L = 1.0;
float LinkTwo_W = 0.2;
float LinkTwo_H = 0.2;

float LinkThree_L = 0.2;
float LinkThree_W = 0.2;
float LinkThree_H = 0.2;

float LinkFour_L = 0.1;
float LinkFour_W = 0.1;
float LinkFour_H = 0.1;


float LinkFive_L = 0.6;
float LinkFive_W = 0.1;
float LinkFive_H = 0.1;

float LinkRightSide_L = 0.1;
float LinkRightSide_W = 0.1;
float LinkRightSide_H = 0.2;

float LinkLeftSide_L = 0.1;
float LinkLeftSide_W = 0.1;
float LinkLeftSide_H = 0.2;

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);         //清除所有像素
	glMatrixMode(GL_MODELVIEW);

	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_LINE_LOOP);
	glVertex3f( 2.0, 0.0, 2.0);
	glVertex3f( 2.0, 0.0,-2.0);
	glVertex3f(-2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, 2.0);
	glEnd();


	glPushMatrix();
	glPushMatrix();
	glTranslatef(0.0 +x , (BaseLink_H / 2.0) +y, 0.0);
	glScalef(BaseLink_L, BaseLink_H, BaseLink_W);
	glutWireCube(1.0);
	glPopMatrix();

	glRotatef(angle, 0.0, 0.1, 0.0);

	glPushMatrix();
	glTranslatef(0.0 + x, BaseLink_H + (LinkOne_H/2.0) +y, 0.0);
	glScalef(LinkOne_L, LinkOne_H, LinkOne_W);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0 + x, BaseLink_H + (LinkOne_H / 2.0) + y, 0.0);
	glScalef(LinkOne_L, LinkOne_H, LinkOne_W);
	glutWireCube(1.0);
	glPopMatrix();


	glPushMatrix();
	glTranslatef((LinkOne_L/2)+ (LinkTwo_L/2) +x, BaseLink_H + LinkOne_H - (LinkTwo_H/2) +y, 0);
	glScalef(LinkTwo_L, LinkTwo_H, LinkTwo_W);
	glutWireCube(1.0);
	glPopMatrix();


	glPushMatrix();
	glTranslatef((LinkOne_L / 2) + (LinkTwo_L / 2) +x, BaseLink_H + LinkOne_H - (LinkTwo_H / 2) +y, 0);
	glScalef(LinkTwo_L, LinkTwo_H, LinkTwo_W);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((LinkOne_L / 2) + LinkTwo_L - (LinkThree_L/2) +x, BaseLink_H + LinkOne_H - LinkTwo_H - (LinkThree_H/2) +y, 0);
	glScalef(LinkThree_L, LinkThree_H, LinkThree_W);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((LinkOne_L / 2) + LinkTwo_L - (LinkThree_L / 2) +x, BaseLink_H + LinkOne_H - LinkTwo_H - LinkThree_H - (LinkFour_H/2) +y, 0);
	glScalef(LinkFour_L, LinkFour_H, LinkFour_W);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((LinkOne_L / 2) + LinkTwo_L - (LinkThree_L / 2) +x, BaseLink_H + LinkOne_H - LinkTwo_H - LinkThree_H - (LinkFour_H / 2) +y, 0);
	glScalef(LinkFour_L, LinkFour_H, LinkFour_W);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((LinkOne_L / 2) + LinkTwo_L - (LinkThree_L / 2) +x, BaseLink_H + LinkOne_H - LinkTwo_H - LinkThree_H - LinkFour_H - (LinkFive_H / 2.0) +y, 0);
	glScalef(LinkFive_L, LinkFive_H, LinkFive_W);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((LinkOne_L / 2) + LinkTwo_L - (LinkThree_L / 2) + gripper + x, BaseLink_H + LinkOne_H - LinkTwo_H - LinkThree_H - LinkFour_H - LinkFive_H - (LinkLeftSide_H / 2) +y, 0);
	glScalef(LinkRightSide_L, LinkRightSide_H, LinkRightSide_W);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((LinkOne_L / 2) + LinkTwo_L - (LinkThree_L / 2) - gripper + x, BaseLink_H + LinkOne_H - LinkTwo_H - LinkThree_H - LinkFour_H - LinkFive_H - (LinkLeftSide_H / 2)+y, 0);
	glScalef(LinkRightSide_L, LinkRightSide_H, LinkRightSide_W);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();

}

void myMenu(int id)
{
	switch (id)
	{
	case 1:
		exit(0);
	case 2:
		x = y =0.0;
		angle = 1.0;
		gripper = 0.1;
		LinkFour_H = 0.1;
		glutPostRedisplay();
		break;
	}
	
}

void mySubMenu(int id)
{
	switch (id)
	{
	case 2:
		x += 0.1;
		break;
	case 3:
		x -= 0.1;
		break;
	case 4:
		y += 0.1;
		break;
	case 5:
		y -= 0.1;
		break;
	case 6:
		angle += 15;
		break;
	case 7:
		angle -= 15;
		break;
	case 8:
		if (LinkFour_H < 0.3)
		LinkFour_H += 0.1;
		break;
	case 9:
		if (LinkFour_H > 0.1)
		LinkFour_H -= 0.1;
		break;
	case 10:
		if (gripper < 0.3)
		gripper += 0.05;
		break;
	case 11:
		if (gripper > 0.1)
		gripper -= 0.05;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);

	int a_menu = glutCreateMenu(mySubMenu);
	glutAddMenuEntry("Increase", 2);
	glutAddMenuEntry("Decrease", 3);
	int b_menu = glutCreateMenu(mySubMenu);
	glutAddMenuEntry("Increase", 4);
	glutAddMenuEntry("Decrease", 5);
	int c_menu = glutCreateMenu(mySubMenu);
	glutAddMenuEntry("Clockwise", 6);
	glutAddMenuEntry("CounterClockwise", 7);
	int d_menu = glutCreateMenu(mySubMenu);
	glutAddMenuEntry("Up", 8);
	glutAddMenuEntry("Down", 9);
	int e_menu = glutCreateMenu(mySubMenu);
	glutAddMenuEntry("Open", 10);
	glutAddMenuEntry("Close", 11);


	glutCreateMenu(myMenu);
	glutAddSubMenu("X Direction", a_menu);
	glutAddSubMenu("Y Direction", b_menu);
	glutAddSubMenu("Arm-Rotation", c_menu);
	glutAddSubMenu("Gripper Height", d_menu);
	glutAddSubMenu("Gripper Control", e_menu);
	glutAddMenuEntry("Return", 2);
	glutAddMenuEntry("Exit", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(myDisplay);

	myInit();
	glutMainLoop();
	return 0;
}