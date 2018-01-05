//#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

// stae do obs�?ugi menu podr�?cznego
enum
{
  EXIT // wyj�?cie
};

/******FUNKCJE GLUTA******/

// funkcja generuj�?ca scen�? 3D
void display(void);

// obs�?uga menu podr�?cznego
void menu(int v);

// zmiana rozmiaru okna
void reshape(int w, int h);

// obs�?uga klawiatury
void keyboard (unsigned char key, int x, int y);

// obs�?uga klawiszy funkcyjnych i klawiszy kursora
void specialKeys (int key, int x, int y);


int main(int argc, char *argv[])
{
    // inicjalizacja biblioteki GLUT
  glutInit (&argc,argv);

  // inicjalizacja bufora ramki
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

  // rozmiary g�?ównego okna programu
  glutInitWindowSize (400,400);

  // utworzenie g�?ównego okna programu
  glutCreateWindow ("Kwadrat");

  // do�?�?czenie funkcji generuj�?cej scen�? 3D
  glutDisplayFunc (display);

  // do�?�?czenie funkcji wywo�?ywanej przy zmianie rozmiaru okna
  glutReshapeFunc (reshape);

 // do�?�?czenie funkcji obs�?ugi klawiatury
  glutKeyboardFunc (keyboard);

// do�?�?czenie funkcji obs�?ugi klawiszy specjalnych
  glutSpecialFunc (specialKeys);

  // utworzenie menu podr�?cznego
  glutCreateMenu (menu);

  // dodadnie pozycji do menu podr�?cznego
  glutAddMenuEntry ("Exit",EXIT);

  // okre�?lenie przycisku myszki obs�?uguj�?cej menu podr�?czne
  glutAttachMenu (GLUT_RIGHT_BUTTON);

  // wprowadzenie programu do obs�?ugi p�?tli komunikatów
  glutMainLoop ();
  return 0;

}

// funkcja rysuj�?ca scen�?
void display ()
{
  // kolor t�?a - zawarto�?�? bufora koloru
  glClearColor (0.0,0.0,0.0,0.0);

  // czyszczenie bufora koloru
  glClear (GL_COLOR_BUFFER_BIT);

// wybór macierzy modelowania
  glMatrixMode (GL_MODELVIEW);

  // macierz modelowania = macierz jednostkowa
  glLoadIdentity ();

  // przesuni�?cie obiektu o wektor [0,0,-3]
  glTranslatef (0,0,-3.0);

  // kolor kwadratu
  glColor3f (1.0,1.0,1.0);

  // pocz�?tek definicji kwadratu z�?oşonego z linii
  glBegin (GL_LINES);


    glVertex3f (1.0, 1.0, 1.0);
    glVertex3f (1.0, -1.0, 1.0);

    glVertex3f (-1.0, 1.0, 1.0);
    glVertex3f (-1.0, -1.0, 1.0);

    glVertex3f (1.0, 1.0, 1.0);
    glVertex3f (-1.0, 1.0, 1.0);

    glVertex3f (1.0, -1.0, 1.0);
    glVertex3f (-1.0, -1.0, 1.0);

  // koniec definicji prymitywu
  glEnd ();

  // skierowanie poleceù do wykonania
  glFlush ();

  // zamiana buforów koloru
  glutSwapBuffers();
}

// obs�?uga menu podr�?cznego
void menu (int value)
{
  switch (value)
    {
      // wyj�?cie
      case EXIT:
        exit(0);
    }
}

// zmiana wielko�?ci okna
void reshape (int w,int h)
{
  // obszar renderingu - ca�?e okno
  glViewport (0,0,w,h);

  //ustawienie rzutowania
  glMatrixMode (GL_PROJECTION);

  // macierz rzutowania = macierz jednostkowa
  glLoadIdentity ();

  //Rozmiar bry�?y odcinania w rzutowaniu prostokatnym
  glOrtho (-2.0,2.0,-2.0,2.0,-2.0,2.0);


  // generowanie sceny 3D
  display ();
}

// obs�?uga klawiatury
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

// obs�?uga klawiszy funkcyjnych i klawiszy kursora

void specialKeys (int key, int x, int y)
{
  switch (key)
    {
      case GLUT_KEY_LEFT: break;
      case GLUT_KEY_UP:   break;
      case GLUT_KEY_RIGHT:break;
      case GLUT_KEY_DOWN: break;
    }

  // odrysowanie okna
  reshape (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
}
