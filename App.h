#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include <vector>
using namespace std;


class App: public GlutApp {
    
    bool start;
    bool gameOver;
    
    TexRect* Background;
    TexRect* TaxiFront;     
   
    vector<TexRect*> RedCar;
        
    AnimatedRect* GameOver;
    AnimatedRect* fastExplosion1;
    AnimatedRect* fastExplosion2;
    

public:
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);

    void idle();

    void timerStart();

    void displayTimer();

    void resetRight();

    void resetLeft();

    
    void collision();
    
    void CarDown();
    
    ~App();
    
};

#endif
