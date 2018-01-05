#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

double punkty[17][3];
int MAX=1;
double pointSize=2;

void displayFigure(void);

void reshape(int w, int h);

// obsługa klawiatury
void keyboard (unsigned char key, int x, int y);

// obsługa klawiszy funkcyjnych i klawiszy kursora
void specialKeys (int key, int x, int y);

void setPoints(double points[17][3]){
    double tempx,tempy,a,krok;
    int r=20;
    int i=1;

    krok=(M_PI_4)/2;

    points[0][0]=0;
    points[0][1]=0;
    points[0][2]=5;

   points[1][0]=0;
   points[1][1]=20;
   points[1][2]=5;

   points[2][0]=7.65;
   points[2][1]=18.48;
   points[2][2]=5;

   points[3][0]=14.14;
   points[3][1]=14.14;
   points[3][2]=5;

   points[4][0]=18.48;
   points[4][1]=7.65;
   points[4][2]=5;

   points[5][0]=20;
   points[5][1]=0;
   points[5][2]=5;

   points[6][0]=18.48;
   points[6][1]=-7.65;
   points[6][2]=5;

   points[7][0]=14.14;
   points[7][1]=-14.14;
   points[7][2]=5;

   points[8][0]=7.65;
   points[8][1]=-18.48;
   points[8][2]=5;

   points[9][0]=0;
   points[9][1]=-20;
   points[9][2]=5;

   points[10][0]=-7.65;
   points[10][1]=-18.48;
   points[10][2]=5;

   points[11][0]=-14.14;
   points[11][1]=-14.14;
   points[11][2]=5;

   points[12][0]=-18.48;
   points[12][1]=-7.65;
   points[12][2]=5;

   points[13][0]=-20;
   points[13][1]=0;
   points[13][2]=5;

   points[14][0]=-18.48;
   points[14][1]=7.65;
   points[14][2]=5;

   points[15][0]=-14.14;
   points[15][1]=14.14;
   points[15][2]=5;

   points[16][0]=-7.65;
   points[16][1]=18.48;
   points[16][2]=5;


}

int main(int argc, char *argv[]){


    // inicjalizacja biblioteki GLUT
  glutInit (&argc,argv);

  setPoints(punkty);

  // inicjalizacja bufora ramki
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

  // rozmiary głównego okna programu
  glutInitWindowSize (800,800);

  // utworzenie głównego okna programu
  glutCreateWindow ("Zad2");
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

  glutDisplayFunc (displayFigure);

   glutReshapeFunc (reshape);

  // dołączenie funkcji obsługi klawiatury
  //glutKeyboardFunc (keyboard);

// dołączenie funkcji obsługi klawiszy specjalnych
  glutSpecialFunc (specialKeys);

    glutMainLoop ();
  return 0;
}

void displayFigure(){
    int i;
    glClearColor (0.0,0.0,0.0,0.0);

    // czyszczenie bufora koloru
  glClear (GL_COLOR_BUFFER_BIT);

// wybór macierzy modelowania
  glMatrixMode (GL_MODELVIEW);

  // macierz modelowania = macierz jednostkowa
  glLoadIdentity ();

  // przesunięcie obiektu o wektor [0,0,-3]
  glTranslatef (0,0,-3.0);
  glColor3f (1.0,1.0,1.0);
  glPointSize (pointSize);
  glFrontFace(GL_CW);

    //gluPerspective(60, 1, 1.0, 10.0);

    glBegin(GL_TRIANGLE_FAN);
        for(i=0;i<17;i++){
            glVertex3f(punkty[i][0],punkty[i][1],punkty[i][2]);
    }
            glVertex3f(punkty[1][0],punkty[1][1],punkty[1][2]);
    glEnd();


    // skierowanie poleceñ do wykonania
  glFlush ();

  // zamiana buforów koloru
  glutSwapBuffers();

}

void reshape (int w,int h)
{
  // obszar renderingu - całe okno
  glViewport (0,0,w,h);

  //ustawienie rzutowania
  glMatrixMode (GL_PROJECTION);

  // macierz rzutowania = macierz jednostkowa
  glLoadIdentity ();

    glOrtho (-30.0,30.0,-30.0,30.0,-30.0,30.0);

  // generowanie sceny 3D
  displayFigure();
}

void specialKeys (int key, int x, int y){

    switch (key)
    {
      case GLUT_KEY_UP: {MAX+=1;break;};
      case GLUT_KEY_DOWN: {MAX+=2;break;};
      case GLUT_KEY_LEFT: {MAX+=3;break;};
      case GLUT_KEY_RIGHT: {MAX+=4;break;};
    }
  reshape (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
}
