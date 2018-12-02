#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"


class App: public GlutApp {
    AnimatedRect* TaxiFront;
    AnimatedRect* RedCar;
    AnimatedRect* Background;
    
public:
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
