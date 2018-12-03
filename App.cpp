#include <iostream>
#include "App.h"
#include <vector>
using namespace std;



App::App(int argc, char** argv): GlutApp(argc, argv){
    // keep first value "1" to make it keep a constant image
    // second value keep at "1"
    // third value is the rate
    // fourth value is the X position
    // fifth value is the Y position
    // sixth value is the width
    // seventh value is the height

    //added coin for an extra 10 points    
    Coin.push_back(new AnimatedRect("bitcoin-icon.bmp", 1, 1, 100, 0, -.8, .3, .3));
    //background of the game
    Background = new AnimatedRect("newroad.png", 1, 1, 100, -1, 1, 2, 2);

    TaxiFront = new AnimatedRect("Taxi-Back-Yellow-icon.bmp", 1, 1, 100, -0.5, 0.0, 0.5, 0.5);
    
    RedCar.push_back(new AnimatedRect("Car-Front-Red-icon.bmp", 1, 1, 10, 0.5, 0.0, 0.5, 0.5));

    Balloon = (new AnimatedRect("ballon.jpeg", 1, 1, 10, 0.5, 0.0, 1, 0.5));
}

void App::draw() {
    //Balloon->draw(.15);

    Background->draw(0.15);
    
    TaxiFront->draw(0.25);
    RedCar[0]->draw(0.25);
    Coin[0]->draw(0.55);
    
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    
    if (key == ' '){
        Balloon->playOnce();
       Background->playOnce();
        RedCar[0]->playOnce();
        TaxiFront->playOnce();
        Coin[0]->playOnce();
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete TaxiFront;
    delete Background;
    delete Balloon;
    delete RedCar[0];
    delete Coin[0];
}
