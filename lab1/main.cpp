#include <iostream>
#include <allegro.h>
#include <allegro/keyboard.h>
#include <math.h>

class Drawer {
    private:
        float _step;
        float _dy, _dx, _m;

        void _countDefferencesX(int x0, int x1, int y0, int y1) {
            this->_dy = y1 - y0;
            this->_dx = x1 - x0;
            this->_m = this->_dy/this->_dx;
        }

        void _countDefferencesY(int x0, int x1, int y0, int y1) {
            this->_dy = y1 - y0;
            this->_dx = x1 - x0;
            this->_m = this->_dx/this->_dy;
        }

        void _drawLine(int x0, int x1, int y0, int y1) {
            this->_countDefferencesX(x0, x1, y0, y1);

            if (abs(this->_m) < 1) {
                this->_drawInXAxis(x0, x1, y0, y1);
            } else {
                this->_drawInYAxis(x0, x1, y0, y1);
            }
        }

        void _drawInXAxis(int x0, int x1, int y0, int y1) {
            if (x0 > x1) {
                std::swap(x0, x1);
                std::swap(y0, y1);
            }

            if (this->_dx == 0) {
                this->_drawVerticalLine(x0, y0, y1);
                return;
            }

            this->_countDefferencesX(x0, x1, y0, y1);

            this->_drawLineInXAxis(x0, x1, y0);
        }

        void _drawVerticalLine(int x0, int y0, int y1) {
            for(int i = y0; i <= y1; i++) {
                putpixel(screen, x0, i, makecol(255, 0, 0));
            }
        }

        void _drawLineInXAxis(int x0, int x1, int y0) {
            float j = y0;
            for(int i = x0; i <= x1; i++) {
                putpixel(screen, i, int(j + 0.5), makecol(255, 0, 0));
                j += this->_m;
            }
        }

        void _drawInYAxis(int x0, int x1, int y0, int y1) {
            if (y0 > y1) {
                std::swap(x0, x1);
                std::swap(y0, y1);
            }

            if(this->_dx == 0) {
                this->_drawHorizontalLine(x0, y0, y1);
                return;
            }

            _countDefferencesY(x0, x1, y0, y1);

            this->_drawLineInYAxis(x0, y0, y1);
        }

        void _drawHorizontalLine(int x0, int y0, int y1) {
            for(int i = y0; i <= y1; i++) {
                putpixel(screen, x0, i, makecol(255, 0, 0));
            }
        }

        void _drawLineInYAxis(int x0, int y0, int y1) {
            float j = x0;
            for(int i = y0; i <= y1; i++) {
                putpixel(screen, int(j + 0.5), i, makecol(255, 0, 0));
                j += this->_m;
            }
        }

    public:
        void drawForA(int screenWidth, int screenHeight) {
            for(int i = 0; i <= int(screenHeight / 100); i++) {
                this->_drawLine(0, int(screenWidth/2), i + 100, int(screenHeight/2));
            }

            /*for(int x = 0; x <= 8; x++){
                this->_drawLine(screenWidth / 8 * x, 0, screenWidth / 8 * x, screenHeight);
                this->_drawLine(0, screenHeight / 8 * x, screenWidth, screenHeight / 8 * x);
            }*/
        }

        void drawForB(int screenWidth, int screenHeight) {
            this->_drawLine(10, 180, 10, 10);
            this->_drawLine(180, 180, 10, 180);
            this->_drawLine(180, 10, 180, 180);
            this->_drawLine(10, 10, 180, 10);
        }

        void drawForC() {

        }

        void drawForD() {

        }

        void drawForE() {

        }

        void drawForF() {

        }

        void setStep(float step) {
            this->_step = step;
        }
};

class KeyboardController {
    private:
        Drawer * _drawer;

    public:
        KeyboardController() {
            install_keyboard();
            this->_drawer = new Drawer();
        }

        void keyboardListener() {
            this->_drawer->setStep(0.5);
            while(1) {
                int pressedButton = readkey() & 0xff;
                this->_drawer->drawForA(320, 320);
                /*switch((char)pressedButton) {
                    case 'A':
                        this->_drawer->drawForA(320, 200);
                        break;
                    case 'B':
                        this->_drawer->drawForB();
                        break;
                    case 'C':
                        this->_drawer->drawForC();
                        break;
                    case 'D':
                        this->_drawer->drawForD();
                        break;
                    case 'E':
                        this->_drawer->drawForE();
                        break;
                    case 'F':
                        this->_drawer->drawForF();
                        break;
                }*/
            }

        }

        ~KeyboardController() {
            remove_keyboard();
        }
};

int main()
{
    allegro_init();
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 320, 320, 320, 320) != 0)
    {
        allegro_message("Problem z ustawieniem trybu graficznego\n");
    }

    clear_bitmap(screen);

    KeyboardController keyboardController;
    keyboardController.keyboardListener();

    allegro_exit();
    return 0;
}

END_OF_MAIN();
