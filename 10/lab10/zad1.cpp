#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>

double punkty[20][3];
int MAX=1;
double pointSize=1;


GLubyte fly[] = {

      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

      0x03, 0x80, 0x01, 0xC0, 0x06, 0xC0, 0x03, 0x60,

      0x04, 0x60, 0x06, 0x20, 0x04, 0x30, 0x0C, 0x20,

      0x04, 0x18, 0x18, 0x20, 0x04, 0x0C, 0x30, 0x20,

      0x04, 0x06, 0x60, 0x20, 0x44, 0x03, 0xC0, 0x22,

      0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,

      0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,

      0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,

      0x66, 0x01, 0x80, 0x66, 0x33, 0x01, 0x80, 0xCC,

      0x19, 0x81, 0x81, 0x98, 0x0C, 0xC1, 0x83, 0x30,

      0x07, 0xe1, 0x87, 0xe0, 0x03, 0x3f, 0xfc, 0xc0,

      0x03, 0x31, 0x8c, 0xc0, 0x03, 0x33, 0xcc, 0xc0,

      0x06, 0x64, 0x26, 0x60, 0x0c, 0xcc, 0x33, 0x30,

      0x18, 0xcc, 0x33, 0x18, 0x10, 0xc4, 0x23, 0x08,

      0x10, 0x63, 0xC6, 0x08, 0x10, 0x30, 0x0c, 0x08,

      0x10, 0x18, 0x18, 0x08, 0x10, 0x00, 0x00, 0x08};


void displayPoints(void);
void displayLines(void);
void displayLineStrip(void);
void displayLineLoop(void);
void displayTriangles(void);
void displayTriangleStrip(void);
void displayTriangleFan(void);
void displayQuads(void);
void displayQuadStrip(void);
void displayPolygon(void);

void reshape(int w, int h);

// obsługa klawiatury
void keyboard (unsigned char key, int x, int y);

// obsługa klawiszy funkcyjnych i klawiszy kursora
void specialKeys (int key, int x, int y);

void punktyLos(){
    int i;
    srand(time(NULL));

    for(i=0;i<20;i++){
        punkty[i][0]=(rand()%40)-20;
        punkty[i][1]=(rand()%40)-20;
        punkty[i][2]=rand()%5;
    }
}

int main(int argc, char *argv[]){


    // inicjalizacja biblioteki GLUT
  glutInit (&argc,argv);

    punktyLos();

    //glEnable(GL_LINE_STIPPLE);
    glEnable(GL_POLYGON_STIPPLE);

    //glLineStipple(1,1);
    glPolygonStipple(fly);

  // inicjalizacja bufora ramki
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

  // rozmiary głównego okna programu
  glutInitWindowSize (800,800);

  // utworzenie głównego okna programu
  glutCreateWindow ("Zad1");
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

  //glutDisplayFunc (displayPoints);

  //glutDisplayFunc (displayLines);

  //glutDisplayFunc (displayLineStrip);

  //glutDisplayFunc (displayLineStrip);

  //glutDisplayFunc (displayTriangles);

  //glutDisplayFunc (displayTriangleStrip);

  //glutDisplayFunc (displayTriangleFan);

  //glutDisplayFunc (displayQuadStrip);

  glutDisplayFunc (displayPolygon);

   glutReshapeFunc (reshape);

  // dołączenie funkcji obsługi klawiatury
  //glutKeyboardFunc (keyboard);

// dołączenie funkcji obsługi klawiszy specjalnych
  glutSpecialFunc (specialKeys);

    glutMainLoop ();
  return 0;
}

void displayPoints(){

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

    //gluPerspective(60, 1, 1.0, 10.0);

    glBegin(GL_POINTS);
        for(i=0;i<MAX;i++){
            glVertex3f(punkty[i][0],punkty[i][1],punkty[i][2]);
        }

    glEnd();

    // skierowanie poleceñ do wykonania
  glFlush ();

  // zamiana buforów koloru
  glutSwapBuffers();
}

void displayLines(){

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

    //gluPerspective(60, 1, 1.0, 10.0);

    glBegin(GL_LINES);
        for(i=0;i<MAX;i+=2){
            glVertex3f(punkty[i][0],punkty[i][1],punkty[i][2]);
            glVertex3f(punkty[i+1][0],punkty[i+1][1],punkty[i+1][2]);
        }

    glEnd();

    // skierowanie poleceñ do wykonania
  glFlush ();

  // zamiana buforów koloru
  glutSwapBuffers();
}

void displayLineStrip(){
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

    //gluPerspective(60, 1, 1.0, 10.0);

    glBegin(GL_LINE_STRIP);
        for(i=0;i<MAX;i++){
            glVertex3f(punkty[i][0],punkty[i][1],punkty[i][2]);
        }

    glEnd();

    // skierowanie poleceñ do wykonania
  glFlush ();

  // zamiana buforów koloru
  glutSwapBuffers();
}

void displayLineLoop(){
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

    //gluPerspective(60, 1, 1.0, 10.0);

    glBegin(GL_LINE_LOOP);
        for(i=0;i<MAX;i++){
            glVertex3f(punkty[i][0],punkty[i][1],punkty[i][2]);
        }

    glEnd();

    // skierowanie poleceñ do wykonania
  glFlush ();

  // zamiana buforów koloru
  glutSwapBuffers();
}

void displayTriangles(){
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

    glBegin(GL_TRIANGLES);
        for(i=0;i<MAX;i+=3){
            glVertex3f(punkty[i][0],punkty[i][1],punkty[i][2]);
            glVertex3f(punkty[i+1][0],punkty[i+1][1],punkty[i+1][2]);
            glVertex3f(punkty[i+2][0],punkty[i+2][1],punkty[i+2][2]);
        }

    glEnd();

    // skierowanie poleceñ do wykonania
  glFlush ();

  // zamiana buforów koloru
  glutSwapBuffers();
}

void displayTriangleStrip(){
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

    glBegin(GL_TRIANGLE_STRIP);
        for(i=0;i<MAX;i++){
            glVertex3f(punkty[i][0],punkty[i][1],punkty[i][2]);

        }

    glEnd();

    // skierowanie poleceñ do wykonania
  glFlush ();

  // zamiana buforów koloru
  glutSwapBuffers();
}

void displayTriangleFan(){
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
  glColor3f (0.0,0.0,0.0);
  glPointSize (pointSize);
  glFrontFace(GL_CW);

    //gluPerspective(60, 1, 1.0, 10.0);

    glBegin(GL_TRIANGLE_FAN);
        for(i=0;i<MAX;i++){
            glVertex3f(punkty[i][0],punkty[i][1],punkty[i][2]);

        }

    glEnd();

    // skierowanie poleceñ do wykonania
  glFlush ();

  // zamiana buforów koloru
  glutSwapBuffers();
}

void displayQuads(){

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

    //gluPerspective(60, 1, 1.0, 10.0);

    glBegin(GL_QUADS);
        for(i=0;i<MAX;i++){
            glVertex3f(punkty[i][0],punkty[i][1],punkty[i][2]);
            glVertex3f(punkty[i+1][0],punkty[i+1][1],punkty[i+1][2]);
            glVertex3f(punkty[i+2][0],punkty[i+2][1],punkty[i+2][2]);
            glVertex3f(punkty[i+3][0],punkty[i+3][1],punkty[i+3][2]);
        }

    glEnd();

    // skierowanie poleceñ do wykonania
  glFlush ();

  // zamiana buforów koloru
  glutSwapBuffers();
}

void displayQuadStrip(){

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

    //gluPerspective(60, 1, 1.0, 10.0);

    glBegin(GL_QUAD_STRIP);
        for(i=0;i<MAX;i++){
            glVertex3f(punkty[i][0],punkty[i][1],punkty[i][2]);
        }

    glEnd();

    // skierowanie poleceñ do wykonania
  glFlush ();

  // zamiana buforów koloru
  glutSwapBuffers();
}

void displayPolygon(){

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

    //gluPerspective(60, 1, 1.0, 10.0);

    glBegin(GL_POLYGON);
        for(i=0;i<MAX;i++){
            glVertex3f(punkty[i][0],punkty[i][1],punkty[i][2]);
        }

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

    glOrtho (-20.0,20.0,-20.0,20.0,-20.0,20.0);

  // generowanie sceny 3D
  displayQuadStrip();
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
