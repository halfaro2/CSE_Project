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
        //Coin.push_back(new AnimatedRect("bitcoin-icon.bmp", 1, 1, 100, -.090, 0, .15, .15));
    //background of the game
    Background = new AnimatedRect("newroad.png", 1, 1, 100, -1, 1, 2, 2);

    TaxiFront = new AnimatedRect("Taxi-Back-Yellow-icon.bmp", 1, 1, 100, -.275, -0.6, 0.5, 0.5);
    
    //right lane
    RedCar.push_back(new AnimatedRect("blue-tesla.png", 1, 1, 10, 0.045, 0.4, 0.1, 0.1));
    //middle lane
    RedCar.push_back(new AnimatedRect("Car-Front-Red-icon.png", 1, 1, 10, -0.045, 0.4, 0.1, 0.1));
    //left lane
    RedCar.push_back(new AnimatedRect("blue-tesla.png", 1, 1, 10, -0.14, 0.4, 0.1, 0.1));


    Balloon = new AnimatedRect("balloon.png", 1, 1, 100, 0.5, .8, 0.15, 0.15);
    
    PlaneFront = new AnimatedRect("Airplane-Front-Red-icon.png",1, 1, 100, -.090, 0, .5, .5);

    CopCar.push_back(new AnimatedRect("copcar.png", 1, 1, 10, -0.4, 0.4, 0.15, 0.15));
    
  

}

void App::draw() {

    Background->draw(0.15);
    TaxiFront->draw(0.25);
    CopCar[0]->draw(0.25);
    Balloon->draw(0.25);
    PlaneFront->draw(0.25);
    
    //Coin[0]->draw(0.55);                  //Uncomment

    for(int i = 0; i < RedCar.size(); i++){
        RedCar[i]->draw(0.25);
    }
    
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    
    if (key == ' '){
       cout<< "space bar is being pressed"<< endl;

        Background->playOnce();
        Balloon->playOnce();
        CopCar[0]->playOnce();
        for(int i = 0; i < RedCar.size(); i++){
        RedCar[i]->playOnce();
        PlaneFront ->playOnce();
    }
        TaxiFront->playOnce();
       // Coin[0]->playOnce();          // Uncomment
    }

    if(key == 'a'){
    
       
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete TaxiFront;
    delete Background;
    delete Balloon;
    delete PlaneFront;
    delete CopCar[0];
    delete RedCar[0];
   // delete Coin[0];           // Uncomment
}


