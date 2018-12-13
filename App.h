#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include <vector>
using namespace std;


class App: public GlutApp {
    bool start;
    AnimatedRect* TaxiFront;        //TaxiFront
    vector<AnimatedRect*> RedCar;   //RedCar
    vector<AnimatedRect*> Coin;     //Coin
    TexRect* Background;
    //adding a comment to test sublime merge program
public:
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);

    void idle();

    void timerStart();

    void displayTimer();
    
    ~App();
    
};

#endif
