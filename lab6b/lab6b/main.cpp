#include <iostream>
#include <allegro.h>
#include <math.h>
#include <time.h>
#include <cstdlib>

#define W_WIDTH 600
#define W_HEIGHT 600
#define M_PI 3.1415

BITMAP *bmp;
BITMAP *actualBmp;

class Drawer {
    public:
        static void draw(double x[][2], double y[][2]) {
            clear_to_color(bmp, makecol(0, 0, 0));
            for (int i = 0; i < 4; i++) {
                line(bmp, x[i][0], y[i][0], x[i][1], y[i][1], makecol(255, 0, 0));
            }
            blit(bmp, screen, 0, 0, 0, 0, W_WIDTH, W_HEIGHT);
        }
};

class Coordinates {
    public:
        static double originalXs[][2];

        static double originalYs[][2];

        static double actualXs[][2];
        static double actualYs[][2];

        static void setActualXY(const double x[][2], const double y[][2]) {
            for (int i = 0; i < 4; i++) {
                for(int j = 0; j < 2; j++) {
                    actualXs[i][j] = x[i][j];
                    actualYs[i][j] = y[i][j];
                }
            }
        }
};

double Coordinates::originalXs[][2] = {
                {50, 130}, {130, 130}, {130, 50}, {50, 50}
            };

double Coordinates::originalYs[][2] = {
                {50, 50}, {50, 130}, {130, 130}, {130, 50}
            };

double Coordinates::actualXs[][2] = {
                {50, 130}, {130, 130}, {130, 50}, {50, 50}
            };

double Coordinates::actualYs[][2] = {
                {50, 50}, {50, 130}, {130, 130}, {130, 50}
            };

class ResizeHelper {
    public:
        static void zoomIn(double x[][2], double y[][2]) {
            for(int i = 0; i < 4; i++) {
                x[i][0] = (x[i][0] * 1.1) + (1-1.1) * (x[i][0]/2);
                x[i][1] = (x[i][1] * 1.1) + (1-1.1) * (x[i][1]/2);
                y[i][0] = (y[i][0] * 1.1) + (1-1.1) * (y[i][0]/2);
                y[i][1] = (y[i][1] * 1.1) + (1-1.1) * (y[i][1]/2);
            }

            clear_to_color(screen,makecol(0, 0, 0));
            Drawer::draw(x, y);
        }

        static void zoomOut(double x[][2], double y[][2]) {
            for(int i = 0; i < 4; i++) {
                x[i][0] = (x[i][0] * 0.9) + (1-0.9) * (x[i][0]/2);
                x[i][1] = (x[i][1] * 0.9) + (1-0.9) * (x[i][1]/2);
                y[i][0] = (y[i][0] * 0.9) + (1-0.9) * (y[i][0]/2);
                y[i][1] = (y[i][1] * 0.9) + (1-0.9) * (y[i][1]/2);
            }

            clear_to_color(screen,makecol(0, 0, 0));
            Drawer::draw(x, y);
        }
};

class MoverHelper {
    public:
        static void slideLeft(double x[][2], double y[][2]) {
            for(int i = 0; i < 4; i++) {
                for (int j = 0; j < 2; j++) {
                    x[i][j] -= 5;
                }
            }
            clear_to_color(screen,makecol(0, 0, 0));
            Drawer::draw(x, y);
        }

        static void slideRight(double x[][2], double y[][2]) {
            for(int i = 0; i < 4; i++) {
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
        static void turn(double x[][2], double y[][2], int direct) {
            float alfa = (direct * M_PI) / 64;
            float cosa = cos(alfa);
            float sina = sin(alfa);
            int scrMiddleW = W_WIDTH/2;
            int scrMiddleH = W_HEIGHT/2;

            for(int i = 0; i < 4; i++) {
                for (int j = 0; j < 2; j++) {
                    double a = scrMiddleW + ((x[i][j] - scrMiddleW) * cosa);
                    double b = (y[i][j] - scrMiddleH) * sina;
                    double c = scrMiddleW + ((x[i][j] - scrMiddleW) * sina);
                    double d = (y[i][j] - scrMiddleH) * cosa;

                    x[i][j] = a - b;
                    y[i][j] = c + d;
                }
            }
            clear_to_color(screen,makecol(0, 0, 0));
            Drawer::draw(x, y);
        }
};

class ResetHelper {
    public:
        static void reset(double x[][2], double y[][2]) {
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
                        RotationHelper::turn(Coordinates::actualXs, Coordinates::actualYs, -1);
                        break;
                    case 'p':
                        RotationHelper::turn(Coordinates::actualXs, Coordinates::actualYs, 1);
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

class BitmapLoader {
    public:
        static const string FILENAME = "test.bmp";

        static BITMAP * loadBitmapFromFile(string fileName) {
            return load_bmp(fileName, default_palette);
        }

        static BITMAP * loadBitmapFromFile() {
            return load_bmp(FILENAME, default_palette);
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

    bmp = BitmapLoader::loadBitmapFromFile();
    blit(bmp, screen, 0, 0, 0, 0, W_WIDTH, W_HEIGHT);

    //Drawer::draw(Coordinates::actualXs, Coordinates::actualYs);

    //KeyboardController keyboardController;
    //keyboardController.keyboardListener();
    destroy_bitmap(bmp);
    allegro_exit();
    return( 0 );
}
END_OF_MAIN();
