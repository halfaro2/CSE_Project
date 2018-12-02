#include <iostream>
#include "App.h"

App::App(int argc, char** argv): GlutApp(argc, argv){
   
   Background = new AnimatedRect("CityBackground.bmp", 1, 1, 100, -1, 1, 2, 2);



    TaxiFront = new AnimatedRect("Taxi-Back-Yellow-icon.bmp", 1, 1, 100, -0.5, 0.5, 0.5, 0.5);
    // Replaced prev icon, keep first numbers "1" to make it keep a constant image
    



    RedCar = new AnimatedRect("Car-Front-Red-icon.bmp", 1, 1, 10, 0.5, 0.5, 0.5, 0.5);
}

void App::draw() {
   
    TaxiFront->draw(0.15);
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
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete TaxiFront;
    delete Background;
    delete RedCar;
}
