#include <allegro.h>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

#define SCREEN_W 400
#define SCREEN_H 400



class Rectangle{

     int xP;
     int yP;
     int xK;
     int yK;

 public:

    Rectangle(){

    this->xP = 150;
    this->yP = 150;
    this->xK = 400;
    this->yK = 300;

    printRect();
    }

    Rectangle(int x , int y){

    this->xP = x;
    this->yP = y;
    this->xK = x+300;
    this->yK = y+200;

    printRect();
    }

    bool isCorr(int p1X,int p1Y,int p2X,int p2Y,int p3X,int p3Y){

    int isCorr;

   //p1X+p2X > p3X && p1Y+p2Y > p3Y ? (p1X+p3X > p2X && p1Y + p3Y > p2Y ? isCorr = true : isCorr = false) : isCorr = false;
   //p2X+p3X > p1X && p2Y+p3Y > p1Y ? isCorr = true : isCorr = false;
    p1X*p1Y+p2X*p2Y > p3X*p3Y ? (p1X*p1Y+p3X*p3Y > p2X*p2Y ? isCorr = true : isCorr = false) : isCorr = false;
    p2X* p2Y + p3X *p3Y > p1X*p1Y ? isCorr = true : isCorr = false;

    return isCorr;

    }

    void printRect(){
    rect(screen,xP,yP,xK,yK,makecol(0,0,255));
    }

    void printTriangle(){


    clear_bitmap(screen);
    printRect();

    int p1X;
    int p1Y;
    int p2X;
    int p2Y;
    int p3X;
    int p3Y;

    int midPosX=20+rand()%400;
    int midPosY=20+rand()%400;


    do{
    p1X=midPosX+rand()%200;
    p1Y=midPosY+rand()%200;
    p2X=midPosX+rand()%200;
    p2Y=midPosY+rand()%200;
    p3X=midPosX+rand()%200;
    p3Y=midPosY+rand()%200;
    //std::cout<<"robie sie \n";
    }while(isCorr(p1X,p1Y,p2X,p2Y,p3X,p3Y) == false);

  cutLine(p1X,p1Y,p2X,p2Y);
  cutLine(p2X,p2Y,p3X,p3Y);
  cutLine(p3X,p3Y,p1X,p1Y);
}

void printLine(){


    clear_bitmap(screen);
    printRect();

    int p1X;
    int p1Y;
    int p2X;
    int p2Y;


    do{
    p1X=rand()%400;
    p1Y=rand()%400;
    p2X=rand()%400;
    p2Y=rand()%400;

    //std::cout<<"robie sie \n";
    }while(abs(p1X - p2X) > 150 || abs(p1Y - p2Y) > 150);



  cutLine(p1X,p1Y,p2X,p2Y);
}

void printColor(int p1X,int p1Y, int p2X,int p2Y, char color){

color == 'R' ?  line(screen,p1X,p1Y,p2X,p2Y,makecol(255,0,0)) : line(screen,p1X,p1Y,p2X,p2Y,makecol(0,255,0));

}


void cutLine(int p1X,int p1Y, int p2X,int p2Y){

while (true){

bool modif1= false, modif2 = false;
int tab1[4]= {0,0,0,0};
int tab2[4] ={0,0,0,0};


if (p1X<xP){
        tab1[0] = 1;
        modif1 = true;
}
if (p1X>xK) {
        tab1[1] = 1;
        modif1 = true;
}

if (p1Y<yP) {
        tab1[2] = 1;
        modif1 = true;
}
if (p1Y>yK) {
        tab1[3] = 1;
        modif1 = true;
}
//--------------------------------
if (p2X<xP){
        tab2[0] = 1;
        modif2 = true;
}
if (p2X>xK) {
        tab2[1] = 1;
        modif2 = true;
}

if (p2Y<yP) {
        tab2[2] = 1;
        modif2 = true;
}
if (p2Y>yK) {
        tab2[3] = 1;
        modif2 = true;
}




if (modif1 == false && modif2 == false){

    printColor(p1X,p1Y,p2X,p2Y,'G');
    return;

    }

if ((modif1 == modif2)!= false ){
    printColor(p1X,p1Y,p2X,p2Y,'R');

    return;
    }


if (modif1 == false && modif2 ==true ){

    for(int i = 0; i<4 ;i++)swap(tab1[i],tab2[i]);
        swap(p1X,p2X);
        swap(p1Y,p2Y);

}


if (tab1[0] == 1){
        //cout<<"tab1[0] tu sie sypie"<<endl;
    int temp_x=p1X;
    int temp_y=p1Y;
    p1Y=p1Y+(xP-p1X)*(p2Y-p1Y)/(p2X-p1X);
    p1X=xP;
    printColor(temp_x,temp_y,xP,p1Y,'R');




} else if(tab1[1] == 1 ){
    //cout<<"tab1[1] tu sie sypie"<<endl;
    int temp_x=p1X;
    int temp_y=p1Y;
    p1Y=p1Y+(xK-p1X)*(p2Y-p1Y)/(p2X-p1X);
    p1X=xK;
    printColor(temp_x,temp_y,xK,p1Y,'R');


} else if(tab1[2] == 1){
    //cout<<"tab1[2] tu sie sypie"<<endl;
    int temp_x=p1X;
    int temp_y=p1Y;
    p1X=p1X+(yP-p1Y)*(p2X-p1X)/(p2Y-p1Y);
    p1Y=yP;
    printColor(temp_x,temp_y,p1X,yP,'R');



} else if(tab1[3] == 1){
    //cout<<"tab1[3] tu sie sypie"<<endl;


    int temp_x=p1X;
    int temp_y=p1Y;

    p1X=p1X+(yK-p1Y)*(p2X-p1X)/(p2Y-p1Y);
    p1Y=yK;
    printColor(temp_x,temp_y,p1X,yK,'R');

}

}
}
};

class QuadrangleDrawer {

};

class KeyboardController {
    private:
        QuadrangleDrawer * _quadrangleDrawer;

    public:
        KeyboardController() {
            install_keyboard();
            this->_quadrangleDrawer = new QuadrangleDrawer();
        }

        void keyboardListener() {
            this->_quadrangleDrawer->setStep(10);
            this->_quadrangleDrawer->draw(320, 320);
            int pressedButton = readkey() & 0xff;
        }

        ~KeyboardController() {
            remove_keyboard();
        }
};

int main()
{
    allegro_init();
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_W, SCREEN_H, SCREEN_W, SCREEN_H) != 0)
    {
        allegro_message("Problem z ustawieniem trybu graficznego\n");
    }
    install_keyboard();

    clear_bitmap(screen);

    KeyboardController keyboardController;
    keyboardController.keyboardListener();

    allegro_exit();
    return 0;

    srand(time(NULL));

cout<<"dla c rysuje trojkat"<<endl;
cout<<"dla v rysuje linie"<<endl;

Rectangle rr;

char c;

while(1){

        c = readkey();
    if(c == 'c') rr.printTriangle();
    if(c == 'v') rr.printLine();


}


     return 0;
 }

END_OF_MAIN();
