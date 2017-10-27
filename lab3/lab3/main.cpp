#include <iostream>
#include <allegro.h>
#include <time.h>
#include <math.h>
#include <stack>

using namespace std;

#define SCREENW 400
#define SCREENH 400
#define M_PI 3.14159265358979323846264338327

class Point {
    private:
        int _x, _y;

    public:
        Point(int x, int y) {
            _x = x;
            _y = y;
        }

        int getX() {
            return _x;
        }

        int getY() {
            return _y;
        }
};

class CircleDrawer {
    private:
        BITMAP * _bitmap;
        int _color, _x0, _y0;

        void _drawPixels(int x, int y, int r) {
            int x1, y1;

            for(double i = 0; i <= M_PI; i += 1.0 / (2 * r)){
                x1 = r * cos(i);
                y1 = r * sin(i);
                putpixel(_bitmap, x + x1, y + y1, _color);
                putpixel(_bitmap, x + y1, y + x1, _color);
                putpixel(_bitmap, x - y1, y + x1, _color);
                putpixel(_bitmap, x - x1, y + y1, _color);
                putpixel(_bitmap, x - x1, y - y1, _color);
                putpixel(_bitmap, x - y1, y - x1, _color);
                putpixel(_bitmap, x + y1, y - x1, _color);
                putpixel(_bitmap, x + x1, y - y1, _color);
            }
        }

    public:
        void draw(BITMAP *bitmap, int color) {
            _bitmap = bitmap;
            _color = color;
            _x0 = rand()%SCREEN_W;
            _y0 = rand()%SCREEN_H;
            _drawPixels(_x0, _y0, rand()%100 + 30);
        }

        void fillInside() {
            std::stack <Point> points;

            points.push(Point(_x0, _y0));

            while(points.size() > 0){
                Point point = points.top();
                points.pop();

                if(getpixel(_bitmap, point.getX(), point.getY()) == makecol(0, 0, 0) && getpixel(_bitmap, point.getX(), point.getY()) != _color){
                    putpixel(_bitmap, point.getX(), point.getY(), _color);

                    points.push(Point(point.getX()-1, point.getY()));
                    points.push(Point(point.getX()+1, point.getY()));
                    points.push(Point(point.getX(), point.getY()-1));
                    points.push(Point(point.getX(), point.getY()+1));
                }
            }
        }
};

int main()
{
    srand(time(nullptr));
    allegro_init();
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREENW, SCREENH, SCREENW, SCREENH) != 0)
    {
        allegro_message("Problem z ustawieniem trybu graficznego\n");
    }

    int randomColor = rand()%255;

    install_keyboard();
    BITMAP *bitmap;

    bitmap = create_bitmap(SCREENW, SCREENH);
    clear_to_color(bitmap, makecol(0, 0, 0));

    CircleDrawer drawer;
    drawer.draw(bitmap, randomColor);
    drawer.fillInside();
    blit(bitmap, screen, 0, 0, 0, 0, bitmap->w, bitmap->h);

    int pressedButton = readkey() & 0xff;

    allegro_exit();
    return 0;
}
END_OF_MAIN();
