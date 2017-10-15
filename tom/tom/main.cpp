#include <iostream>
#include <allegro.h>

//BITMAP *screen = create_bitmap(320, 200);

class Odcinki {
public:
    Odcinki();
    void rysujOdcinek(int x0, int y0, int x1, int y1, int col);
    void opcja1();
};

Odcinki::Odcinki()
{

}

void Odcinki::rysujOdcinek(int x0, int y0, int x1, int y1, int col) {

    if (x1<x0)
    {
        std::swap(x0,x1);
        std::swap(y0,y1);
    }

    float dx=x1-x0;
    float dy=y1-y0;

    if (dx==0)
    {
        for (int y=y0; y<=y1; y++)
        {
            putpixel(screen, x0,  y, col);
        }
    }

    float m=dy/dx;
    if (abs(m)<1) {

        float y=y0;
        for(int x=x0; x<=x1; x++) {
            putpixel(screen, x,  int(y+0.5), col);
            y+=m;
        }
    } else {

        if (y1<y0)
        {
            std::swap(x0,x1);
            std::swap(y0,y1);
        }

        m=dx/dy;
        float x=x0;
        for(int y=y0; y<=y1; y++) {

            putpixel(screen, int(x+0.5),  y, col);
            x+=m;
        }



    }
}


void Odcinki::opcja1() {
    //clear_bitmap(screen);
//    int SCREEN_W = 320;
//    int SCREEN_H = 200;
    for (int i=0; i<8; i++) {
        rysujOdcinek(i*SCREEN_W/8,0,i*SCREEN_W/8,SCREEN_H,makecol(255,0,0));
        rysujOdcinek(0,i*SCREEN_H/8,SCREEN_W,i*SCREEN_H/8,makecol(255,0,0));
    }
}

int main()
{
    allegro_init();
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 320, 200, 320, 200) != 0)
    {
        allegro_message("Problem z ustawieniem trybu graficznego\n");
    }
    Odcinki odc;
    odc.opcja1();
        allegro_exit();

    return 0;
}
END_OF_MAIN();
