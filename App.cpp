#include <iostream>
#include "App.h"

App::App(int argc, char** argv): GlutApp(argc, argv){
    TaxiFront = new AnimatedRect("Taxi-Back-Yellow-icon.bmp", 1, 1, 100, -0.5, 0.5, 0.5, 0.5);
    // Replaced prev icon, keep first numbers "1" to make it keep a constant image
    
    RedCar = new AnimatedRect("Car-Front-Red-icon.bmp", 1, 1, 10, 0.5, 0.5, 0.5, 0.5);
}

void App::draw() {
    TaxiFront->draw(0.15);
    RedCar->draw(0.15);
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    
    if (key == ' '){
        RedCar->playOnce();
        TaxiFront->playOnce();
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete TaxiFront;
    delete RedCar;
}
