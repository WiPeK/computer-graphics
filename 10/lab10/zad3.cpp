#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <cmath>

// stae do obsługi menu podręcznego
float x_1, y_1, x_2, y_2, x_3, y_3;

/******FUNKCJE GLUTA******/

// funkcja generująca scenę 3D
void display(void);

// zmiana rozmiaru okna
void reshape(int w, int h);

// obsługa klawiatury
void keyboard (unsigned char key, int x, int y);

// obsługa klawiszy funkcyjnych i klawiszy kursora
void specialKeys (int key, int x, int y);

int main(int argc, char *argv[])
{
    // inicjalizacja biblioteki GLUT
  glutInit (&argc,argv);

  // inicjalizacja bufora ramki
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

  // rozmiary głównego okna programu
  glutInitWindowSize (800,800);

  // utworzenie głównego okna programu
  glutCreateWindow ("Trojkat");

  // dołączenie funkcji generującej scenę 3D
  glutDisplayFunc (display);

  // dołączenie funkcji wywoływanej przy zmianie rozmiaru okna
  glutReshapeFunc (reshape);

 // dołączenie funkcji obsługi klawiatury
  glutKeyboardFunc (keyboard);

// dołączenie funkcji obsługi klawiszy specjalnych
  glutSpecialFunc (specialKeys);



  // wprowadzenie programu do obsługi pętli komunikatów
  glutMainLoop ();
  return 0;

}

// funkcja rysująca scenę
void display ()
{
    int i;
  // kolor tła - zawartość bufora koloru
  glClearColor (0.0,0.0,0.0,0.0);

  // czyszczenie bufora koloru
  glClear (GL_COLOR_BUFFER_BIT);

// wybór macierzy modelowania
  glMatrixMode (GL_MODELVIEW);

  // macierz modelowania = macierz jednostkowa
  glLoadIdentity ();

  // przesunięcie obiektu o wektor [0,0,-3]
  glTranslatef (0,0,-3.0);

  // kolor kwadratu
  glColor3f (1.0,1.0,1.0);

  x_1 = -2;
  y_1 = -1;
  x_2 =  2;
  y_2 = -1;

  y_3 = (x_1+x_2)/2;
  y_3 = y_2+sqrt(3)*(x_2-x_1)/2;

  glBegin (GL_TRIANGLES);

  glColor3f(2.0, 0.0, 0.0);
  glVertex3f(x_1, y_1, -2);

  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(x_2, y_2, -2);

  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(x_3, y_3, -2);

  // koniec definicji prymitywu
  glEnd ();

  // skierowanie poleceñ do wykonania
  glFlush ();

  // zamiana buforów koloru
  glutSwapBuffers();
}


// zmiana wielkości okna
void reshape (int w,int h)
{
  // obszar renderingu - całe okno
  glViewport (0,0,w,h);

  //ustawienie rzutowania
  glMatrixMode (GL_PROJECTION);

  // macierz rzutowania = macierz jednostkowa
  glLoadIdentity ();

  //Rozmiar bryły odcinania w rzutowaniu prostokatnym
  glOrtho (-5,5,-5,5,-5,5);


  // generowanie sceny 3D
  display ();
}

// obsługa klawiatury
void keyboard (unsigned char key, int x, int y)
{
  // klawisz +
  switch(key){
      case  '+': break;
      case  '-': break;
  }
  // odrysowanie okna
  reshape (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
}

// obsługa klawiszy funkcyjnych i klawiszy kursora

void specialKeys (int key, int x, int y)
{
  switch (key)
    {
      case GLUT_KEY_UP:   break;
      case GLUT_KEY_DOWN: break;
    }

  // odrysowanie okna
  reshape (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
}

