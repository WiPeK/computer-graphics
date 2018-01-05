#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

GLdouble fovy = 90;
GLdouble aspect = 1;
GLdouble znear = 5;
GLdouble zfar = 7.5;
GLdouble left = -7.5;
GLdouble right = 5.5;
GLdouble bottom = -7.5;
GLdouble top = 5.5;
GLdouble sx = 0;
GLdouble sy = 0;
GLdouble sz = 0;
GLdouble ra = 0;
GLdouble rx = 0;
GLdouble ry = 0;
GLdouble rz = 0;

float r=4.0;
int i=0;
float a;
GLdouble x = 1;
GLdouble y = 1;
GLdouble xx = 0;
GLdouble yy = 0;



void displaySzescian()
{
    //glBegin (GL_QUADS);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glEdgeFlag(GL_TRUE);

    glColor3f (0,0.5,0.5);
    glVertex3f (-1.0, -1.0, 1.0);
    glVertex3f (-1.0, 1.0, 1.0);
    glVertex3f (1.0, 1.0, 1.0);
    glVertex3f (1.0, -1.0, 1.0);

    glColor3f (0,0.5,1);
    glVertex3f (1.0, 1.0, -1.0);
    glVertex3f (-1.0, 1.0, -1.0);
    glVertex3f (-1.0, -1.0, -1.0);
    glVertex3f (1.0, -1.0, -1.0);

    glColor3f (0.5,0,1);
    glVertex3f (1.0, 1.0, -1.0);
    glVertex3f (1.0, 1.0, 1.0);
    glVertex3f (-1.0, 1.0, 1.0);
    glVertex3f (-1.0, 1.0, -1.0);

    glColor3f (1,0,0.5);
    glVertex3f (-1.0, -1.0, -1.0);
    glVertex3f (-1.0, -1.0, 1.0);
    glVertex3f (1.0, -1.0, 1.0);
    glVertex3f (1.0, -1.0, -1.0);

    glColor3f (0.5,1,0);
    glVertex3f (1.0, 1.0, -1.0);
    glVertex3f (1.0, -1.0, -1.0);
    glVertex3f (1.0, -1.0, 1.0);
    glVertex3f (1.0, 1.0, 1.0);

    glColor3f (0,0.5,1);
    glVertex3f (-1.0, -1.0, 1.0);
    glVertex3f (-1.0, -1.0, -1.0);
    glVertex3f (-1.0, 1.0, -1.0);
    glVertex3f (-1.0, 1.0, 1.0);

  glEnd ();
}

void idle()
{
    ra++;
    rx++;
    ry++;
    rz++;

    i+=1;
    a = i * (float)3.14159 / (float)180;
    x = 0.0 + r * (float)sin(a);
    y = 0.0 + r * (float)cos(a);
    xx = 0.0 + r * (float)cos(a);
    yy = 0.0 - r * (float)cos(a);
    glutPostRedisplay();
}

void rysowanie(float a, float b)
{
    glPushMatrix();
    glTranslated (a,b,-6);
    glRotated (ra,rx,ry,0);
    glScaled (0.75,0.75,0.75);
    displaySzescian();
    glPopMatrix();
}

void display ()
{
  glClearColor (0.0,0.0,0.0,0.0);
  glClear (GL_COLOR_BUFFER_BIT);

  glMatrixMode (GL_MODELVIEW);

  glLoadIdentity ();

  glEnable(GL_CULL_FACE);
  glFrontFace(GL_CW);
  glCullFace(GL_BACK);

  //glTranslated (0,0,-5);


    rysowanie(x,y);
    rysowanie(xx,yy);

  glFlush ();
  glutSwapBuffers();
}

void reshape (int w,int h)
{
  glViewport (0,0,w,h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  //glOrtho	(left, right, bottom, top, zNear, zFar)
  glOrtho (left, right, bottom, top, znear, zfar);

  //gluPerspective(fovy,aspect,znear,zfar);
  display ();
}

void keyboard (unsigned char key, int x, int y)
{
  switch(key){
      case  'e': fovy++;        break;
      case  'r': fovy--;        break;
      case  'q': aspect+=0.1;   break;
      case  'w': aspect-=0.1;   break;
      case  'a': znear+=0.1;    break;
      case  's': znear-=0.1;    break;
      case  'z': zfar+=0.1;     break;
      case  'x': zfar-=0.1;     break;
      case   27: exit(0);
      }
  // odrysowanie okna
  reshape (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
}

int main(int argc, char *argv[])
{
  glutInit (&argc,argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (400,400);
  glutCreateWindow ("Animacja");
  glutDisplayFunc (display);
  glutIdleFunc(idle);
  glutReshapeFunc (reshape);
  glutKeyboardFunc (keyboard);
  glutMainLoop ();
  return 0;

}

