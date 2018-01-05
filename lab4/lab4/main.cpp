#include <iostream>
#include <allegro.h>
#include <math.h>
#include <time.h>
#include <cstdlib>

#define W_WIDTH 600
#define W_HEIGHT 600
#define M_PI 3.1415

class Drawer {
    public:
        static void draw(int x[][2], int y[][2]) {
            for (int i = 0; i < 11; i++) {
                line(screen, x[i][0], y[i][0], x[i][1], y[i][1], makecol(255, 0, 0));
            }
        }
};

class Coordinates {
    public:
        static int originalXs[][2];

        static int originalYs[][2];

        static int actualXs[][2];
        static int actualYs[][2];

        static void setActualXY(const int x[][2], const int y[][2]) {
            for (int i = 0; i < 11; i++) {
                for(int j = 0; j < 2; j++) {
                    actualXs[i][j] = x[i][j];
                    actualYs[i][j] = y[i][j];
                }
            }
        }
};

int Coordinates::originalXs[][2] = {
                {50, 130}, {130, 130}, {130, 50}, {50, 50},
                {65, 85}, {85, 85}, {85, 65}, {65, 65},
                {100, 120}, {65, 100}, {100, 120}
            };

int Coordinates::originalYs[][2] = {
                {50, 50}, {50, 150}, {150, 150}, {150, 50},
                {65, 65}, {65, 85}, {85, 85}, {85, 65},
                {85, 85}, {120, 140}, {140, 120}
            };

int Coordinates::actualXs[][2] = {
                {50, 130}, {130, 130}, {130, 50}, {50, 50},
                {65, 85}, {85, 85}, {85, 65}, {65, 65},
                {100, 120}, {65, 100}, {100, 120}
            };

int Coordinates::actualYs[][2] = {
                {50, 50}, {50, 150}, {150, 150}, {150, 50},
                {65, 65}, {65, 85}, {85, 85}, {85, 65},
                {85, 85}, {120, 140}, {140, 120}
            };

class ResizeHelper {
    public:
        static void zoomIn(int x[][2], int y[][2]) {
            for(int i = 0; i < 11; i++) {
                x[i][0] = (x[i][0] * 1.1) + (1-1.1) * (int)(x[i][0]/2);
                x[i][1] = (x[i][1] * 1.1) + (1-1.1) * (int)(x[i][1]/2);
                y[i][0] = (y[i][0] * 1.1) + (1-1.1) * (int)(y[i][0]/2);
                y[i][1] = (y[i][1] * 1.1) + (1-1.1) * (int)(y[i][1]/2);
            }

            clear_to_color(screen,makecol(0, 0, 0));
            Drawer::draw(x, y);
        }

        static void zoomOut(int x[][2], int y[][2]) {
            for(int i = 0; i < 11; i++) {
                x[i][0] = (x[i][0] * 0.9) + (1-0.9) * (int)(x[i][0]/2);
                x[i][1] = (x[i][1] * 0.9) + (1-0.9) * (int)(x[i][1]/2);
                y[i][0] = (y[i][0] * 0.9) + (1-0.9) * (int)(y[i][0]/2);
                y[i][1] = (y[i][1] * 0.9) + (1-0.9) * (int)(y[i][1]/2);
            }

            clear_to_color(screen,makecol(0, 0, 0));
            Drawer::draw(x, y);
        }
};

class MoverHelper {
    public:
        static void slideLeft(int x[][2], int y[][2]) {
            for(int i = 0; i < 11; i++) {
                for (int j = 0; j < 2; j++) {
                    x[i][j] -= 5;
                }
            }
            clear_to_color(screen,makecol(0, 0, 0));
            Drawer::draw(x, y);
        }

        static void slideRight(int x[][2], int y[][2]) {
            for(int i = 0; i < 11; i++) {
                for (int j = 0; j < 2; j++) {
                    x[i][j] += 5;
                }
            }
            clear_to_color(screen,makecol(0, 0, 0));
            Drawer::draw(x, y);
        }
};

class RotationHelper {
    public:
        static void turnLeft(int x[][2], int y[][2]) {
            float alfa = -M_PI / 64;

            for(int i = 0; i < 11; i++) {
                for (int j = 0; j < 2; j++) {
                    x[i][j] = W_WIDTH + ((x[i][j] - W_WIDTH) * cos(alfa)) - ((y[i][j] - W_HEIGHT) * sin(alfa));
                    y[i][j] = W_HEIGHT + ((x[i][j] - W_WIDTH) * sin(alfa)) + ((y[i][j] - W_HEIGHT) * cos(alfa));
                }
            }
            clear_to_color(screen,makecol(0, 0, 0));
            Drawer::draw(x, y);
        }

        static void turnRigth(int x[][2], int y[][2]) {
            float alfa = M_PI / 64;

            for(int i = 0; i < 11; i++) {
                for (int j = 0; j < 2; j++) {
                    x[i][j] = W_WIDTH + ((x[i][j] - W_WIDTH) * cos(alfa)) - ((y[i][j] - W_HEIGHT) * sin(alfa));
                    y[i][j] = W_HEIGHT + ((x[i][j] - W_WIDTH) * sin(alfa)) + ((y[i][j] - W_HEIGHT) * cos(alfa));
                }
            }
            clear_to_color(screen,makecol(0, 0, 0));
            Drawer::draw(x, y);
        }
};

class ResetHelper {
    public:
        static void reset(int x[][2], int y[][2]) {
            clear_to_color(screen,makecol(0, 0, 0));
            Drawer::draw(x, y);
        }
};

class KeyboardController {
    public:
        KeyboardController() {
            install_keyboard();
        }

        void keyboardListener() {
            int pressedButton = readkey() & 0xff;
            while(!key[KEY_ESC]) {
                switch ((char)pressedButton) {
                    case 's':
                        ResizeHelper::zoomOut(Coordinates::actualXs, Coordinates::actualYs);
                        break;
                    case 'd':
                        ResizeHelper::zoomIn(Coordinates::actualXs, Coordinates::actualYs);
                        break;
                    case 't':
                        MoverHelper::slideLeft(Coordinates::actualXs, Coordinates::actualYs);
                        break;
                    case 'y':
                        MoverHelper::slideRight(Coordinates::actualXs, Coordinates::actualYs);
                        break;
                    case 'o':
                        RotationHelper::turnLeft(Coordinates::actualXs, Coordinates::actualYs);
                        break;
                    case 'p':
                        RotationHelper::turnLeft(Coordinates::actualXs, Coordinates::actualYs);
                        break;
                    case 'x':
                        ResetHelper::reset(Coordinates::originalXs, Coordinates::originalYs);
                        Coordinates::setActualXY(Coordinates::originalXs, Coordinates::originalYs);
                        break;
                }
                pressedButton = readkey() & 0xff;
            }
        }

        ~KeyboardController() {
            remove_keyboard();
        }
};



int main() {
    srand(time(nullptr));
    allegro_init();

    set_color_depth( 32 );

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, W_WIDTH, W_HEIGHT, W_WIDTH, W_HEIGHT) != 0)
    {
        allegro_message("Problem z ustawieniem trybu graficznego\n");
    }

    Drawer::draw(Coordinates::actualXs, Coordinates::actualYs);

    KeyboardController keyboardController;
    keyboardController.keyboardListener();

    allegro_exit();
    return( 0 );
}
END_OF_MAIN();
