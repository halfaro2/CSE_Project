#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include <vector>
using namespace std;


class App: public GlutApp {
    bool start;
    bool gameOver;
    TexRect* TaxiFront;        //TaxiFront
    vector<TexRect*> RedCar;   //RedCar
    vector<TexRect*> Coin;     //Coin
    TexRect* Background;
    AnimatedRect* fastExplosion;
    //adding a comment to test sublime merge program
public:
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);

    void idle();

    void timerStart();

    void displayTimer();

    void reset();

   
    
    void collision();
    
    
    ~App();
    
};

#endif
