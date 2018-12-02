#include <iostream>
#include "App.h"

App::App(int argc, char** argv): GlutApp(argc, argv){
    //added coin for an extra 10 points    
    Coin = new AnimatedRect("bitcoin-icon.bmp", 1, 1, 100, 0, -.8, .3, .3);
    //background of the game
    Background = new AnimatedRect("CityBackground.bmp", 1, 1, 100, -1, 1, 2, 2);

    TaxiFront = new AnimatedRect("Taxi-Back-Yellow-icon.bmp", 1, 1, 100, -0.5, 0.5, 0.5, 0.5);
    // Replaced prev icon, keep first numbers "1" to make it keep a constant image
    
    RedCar = new AnimatedRect("Car-Front-Red-icon.bmp", 1, 1, 10, 0.5, 0.5, 0.5, 0.5);
}

void App::draw() {

    Coin->draw(0.15);\
    //TaxiFront->draw(0.15);
    RedCar->draw(0.15);
    Background->draw(.15);

}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    
    if (key == ' '){
        Background->playOnce();
        RedCar->playOnce();
        TaxiFront->playOnce();
        Coin->playOnce();
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete TaxiFront;
    delete Background;
    delete RedCar;
    delete Coin;
}
