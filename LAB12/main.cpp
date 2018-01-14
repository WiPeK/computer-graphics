#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define znear -5.0
#define zfar 5.0
#define left -4.0
#define right 4.0
#define bottom -3.0
#define top 4.5

GLdouble rx=0;
GLdouble rz=0;
GLdouble tx=0;
GLdouble ty=0;

int a=0;
int sx=0;
int sy=0;

void displaySzescian()
{
glBegin (GL_QUADS);

glColor3f (1,0,0);
glVertex3f (-1.0, -1.0, 1.0);
glVertex3f (-1.0, 1.0, 1.0);
glVertex3f (1.0, 1.0, 1.0);
glVertex3f (1.0, -1.0, 1.0);

glColor3f (0.5,1,0);
glVertex3f (1.0, 1.0, -1.0);
glVertex3f (-1.0, 1.0, -1.0);
glVertex3f (-1.0, -1.0, -1.0);
glVertex3f (1.0, -1.0, -1.0);

glColor3f (0.5,0,1);
glVertex3f (1.0, 1.0, -1.0);
glVertex3f (1.0, 1.0, 1.0);
glVertex3f (-1.0, 1.0, 1.0);
glVertex3f (-1.0, 1.0, -1.0);

glColor3f (0.5,0.1,0.5);
glVertex3f (-1.0, -1.0, -1.0);
glVertex3f (-1.0, -1.0, 1.0);
glVertex3f (1.0, -1.0, 1.0);
glVertex3f (1.0, -1.0, -1.0);

glColor3f (0.1,0.5,0.5);
glVertex3f (1.0, 1.0, -1.0);
glVertex3f (1.0, -1.0, -1.0);
glVertex3f (1.0, -1.0, 1.0);
glVertex3f (1.0, 1.0, 1.0);

glColor3f (0.5,0.5,0.5);
glVertex3f (-1.0, -1.0, 1.0);
glVertex3f (-1.0, -1.0, -1.0);
glVertex3f (-1.0, 1.0, -1.0);
glVertex3f (-1.0, 1.0, 1.0);

glEnd ();
}

void idle()
{
a++;
glutPostRedisplay();
}

void rysuj()
{
//1 poziom
glPushMatrix();
glTranslated (0, 0, 0);
glRotated (0, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (2, 0, 0);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (-2, 0, 0);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (-4, 0, 0);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (4, 0, 0);
glRotated (270, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (6, 0, 0);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();

//

glPushMatrix();
glTranslated (0, 0, 2);
glRotated (0, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (2, 0, 2);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (-2, 0, 2);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (4, 0, 2);
glRotated (270, 1, 0, 0);
displaySzescian();
glPopMatrix();

//
glPushMatrix();
glTranslated (0, 0, -2);
glRotated (0, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (2, 0, -2);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (-2, 0, -2);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (4, 0, -2);
glRotated (270, 1, 0, 0);
displaySzescian();
glPopMatrix();

//
glPushMatrix();
glTranslated (0, 0, 4);
glRotated (0, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (2, 0, 4);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();



//
glPushMatrix();
glTranslated (0, 0, -4);
glRotated (0, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (2, 0, -4);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();

//
glPushMatrix();
glTranslated (1, 0, -6);
glRotated (0, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (1, 0, 6);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();



//2 poziom
glPushMatrix();
glTranslated (1, 2, 0);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (3, 2, 0);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (-1, 2, 0);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();

//
glPushMatrix();
glTranslated (0, 2, 2);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (2, 2, 2);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();

//
glPushMatrix();
glTranslated (0, 2, -2);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (2, 2, -2);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();


//3 poziom
glPushMatrix();
glTranslated (0, 4, 0);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (2, 4, 0);
glRotated (270, 1, 0, 0);
displaySzescian();
glPopMatrix();

//
glPushMatrix();
glTranslated (1, 4, 1);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();
//
glPushMatrix();
glTranslated (1, 4, -1);
glRotated (270, 1, 0, 0);
displaySzescian();
glPopMatrix();

//4 poziom
glPushMatrix();
glTranslated (1, 6, 0);
glRotated (270, 1, 0, 0);
displaySzescian();
glPopMatrix();




////////////////////////////////////////////////////////////////////////////////////////////////////////////

//2 poziom
glPushMatrix();
glTranslated (1, -2, 0);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (3, -2, 0);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (-1, -2, 0);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();

//
glPushMatrix();
glTranslated (0, -2, 2);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (2, -2, 2);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();

//
glPushMatrix();
glTranslated (0, -2, -2);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (2, -2, -2);
glRotated (90, 1, 0, 0);
displaySzescian();
glPopMatrix();


//3 poziom
glPushMatrix();
glTranslated (0, -4, 0);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();

glPushMatrix();
glTranslated (2, -4, 0);
glRotated (270, 1, 0, 0);
displaySzescian();
glPopMatrix();

//
glPushMatrix();
glTranslated (1, -4, 1);
glRotated (180, 1, 0, 0);
displaySzescian();
glPopMatrix();
//
glPushMatrix();
glTranslated (1, -4, -1);
glRotated (270, 1, 0, 0);
displaySzescian();
glPopMatrix();

//4 poziom
glPushMatrix();
glTranslated (1, -6, 0);
glRotated (270, 1, 0, 0);
displaySzescian();
glPopMatrix();


}

void mouseButton(int button, int state, int x, int y)
{
if (button == GLUT_LEFT_BUTTON)
{
if (state == GLUT_DOWN)
{
sx=x;
sy=y;
}
if (state == GLUT_UP)
{
tx=((right-left)/(glutGet (GLUT_WINDOW_WIDTH)))*(x-sx)+tx;
ty=((top-bottom)/(glutGet (GLUT_WINDOW_HEIGHT)))*(sy-y)+ty;
}
}
}

void display ()
{
glClearColor (0.0,0.0,0.0,0.0);
glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode (GL_MODELVIEW);
glLoadIdentity ();
glEnable(GL_CULL_FACE);
glFrontFace(GL_CW);
glCullFace(GL_BACK);
glEnable(GL_DEPTH_TEST);
glTranslated (tx, ty, -3);
glScaled(0.5,0.5,0.5);
glRotated(a,rx,1,rz);
rysuj();
glFlush ();
glutSwapBuffers();
}

void reshape (int w,int h)
{
glViewport (0,0,w,h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
glOrtho (left, right, bottom, top, znear, zfar);
display ();
}

void keyboard (unsigned char key, int x, int y)
{
switch(key){
case 27: exit(0);
}
}

void specialKeys (int key, int x, int y)
{
switch (key)
{
case
    GLUT_KEY_LEFT:
        rx-=0.1;
        break;
case
    GLUT_KEY_UP:
        rz-=0.1;
        break;
case
    GLUT_KEY_RIGHT:
        rx+=0.1;
        break;
case
    GLUT_KEY_DOWN:
        rz+=0.1;
        break;
}
}

int main(int argc, char *argv[])
{
glutInit (&argc,argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize (600,600);
glutCreateWindow ("Lab_12");
glutDisplayFunc (display);
glutIdleFunc(idle);
glutReshapeFunc (reshape);
glutKeyboardFunc (keyboard);
glutSpecialFunc (specialKeys);
glutMouseFunc(mouseButton);
glutMainLoop ();
return 0;

}
