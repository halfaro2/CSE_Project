#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include <vector>
using namespace std;


class App: public GlutApp {
    AnimatedRect* TaxiFront;        //TaxiFront
    vector<AnimatedRect*> RedCar;   //RedCar
    AnimatedRect* Background;       //Background
    vector<AnimatedRect*> Coin;     //Coin
    AnimatedRect* Balloon;          //Ballon
    vector<AnimatedRect*> CopCar;   //CopCar
    AnimatedRect* PlaneFront;       //PlaneFront
    //adding a comment to test sublime merge program
public:
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
