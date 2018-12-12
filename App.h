#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include "Obstacles.h"
#include <vector>
using namespace std;


class App: public GlutApp {
   
    AnimatedRect* TaxiFront;        //TaxiFront
    vector<AnimatedRect*> RedCar;   //RedCar
    vector<AnimatedRect*> Coin;     //Coin
    AnimatedRect* Balloon;          //Ballon
    AnimatedRect* CopCar;   //CopCar
    TexRect* Background;
    //adding a comment to test sublime merge program
public:
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);

    void idle();
    
    ~App();
    
};

#endif
