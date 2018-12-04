#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include <vector>
using namespace std;


class App: public GlutApp {
    AnimatedRect* TaxiFront;
    vector<AnimatedRect*> RedCar;
    AnimatedRect* Background;
    vector<AnimatedRect*> Coin;
    AnimatedRect* Balloon;
    vector<AnimatedRect*> CopCar;
    AnimatedRect* PlaneFront;
    
public:
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
