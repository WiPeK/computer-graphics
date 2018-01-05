#include <iostream>
#include <allegro.h>
#include <math.h>
#include <time.h>
#include <cstdlib>

#define W_WIDTH 600
#define W_HEIGHT 600

using namespace std;

BITMAP * bmp, *bmp2, * bmp3;

class BitmapLoader {
    public:

        static BITMAP * loadBitmapFromFile(string fileName) {
            return load_bmp(fileName.c_str(), default_palette);
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
                int alpha = 0;
                switch ((char)pressedButton) {
                    case 'z':
                        if (alpha <= 245) {
                            alpha +=5;
                        }
                        break;
                    case 'x':
                        if (alpha >= 10) {
                            alpha -= 5;
                        }
                        break;
                    alpha = abs(alpha%255);
                    set_trans_blender(0, 0, 0, alpha);
                    masked_blit(bmp2, bmp, 0, 0, 250, 80, W_WIDTH, W_HEIGHT);
                    draw_trans_sprite(bmp, bmp3, 0, 0);
                    blit(bmp, screen, 0, 0, 0, 0, W_WIDTH, W_HEIGHT);
                }
                pressedButton = readkey() & 0xff;
            }
        }

        ~KeyboardController() {
            remove_keyboard();
        }
};

int main()
{
    allegro_init();
    set_color_depth(32);
    bmp = create_bitmap(W_WIDTH, W_HEIGHT);
    bmp2 = BitmapLoader::loadBitmapFromFile("test.bmp");
    bmp3 = BitmapLoader::loadBitmapFromFile("test2.bmp");

    set_alpha_blender();

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, W_WIDTH, W_HEIGHT, W_WIDTH, W_HEIGHT) != 0)
    {
        allegro_message("Problem z ustawieniem trybu graficznego\n");
    }

    KeyboardController keyboardController;
    keyboardController.keyboardListener();

    destroy_bitmap(bmp);
    destroy_bitmap(bmp2);
    destroy_bitmap(bmp3);
    return 0;
}
END_OF_MAIN();
