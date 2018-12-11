#include <iostream>
#include "App.h"
#include <vector>
using namespace std;



App::App(int argc, char** argv): GlutApp(argc, argv){
    bool left = false; //checks if 'a' has been pressed 
    bool right = false; //checks if 'd' has been pressed
    bool start = false; //initializes the start of the game

    // first value row
    // second value column
    // third value is the rate
    // fourth value is the X position
    // fifth value is the Y position
    // sixth value is the width
    // seventh value is the height

    //added coin for an extra 10 points  
    //need to make them come later once the timer starts to not conflict with cars coming  
    Coin.push_back(new AnimatedRect("bitcoin-icon.bmp", 1, 1, 100, -.090, 0, .15, .15));

    //background of the game
    Background = new AnimatedRect("newroad.png", 1, 1, 100, -1, 1, 2, 2);       //Background

    //the taxi (player)
    TaxiFront = new AnimatedRect("Taxi-Back-Yellow-icon.bmp", 1, 1, 100, -.275, -0.6, 0.5, 0.5);    //TaxiFront
    
    //right lane
    RedCar.push_back(new AnimatedRect("blue-tesla.png", 1, 1, 10, 0.045, 0.4, 0.1, 0.1));
    //middle lane
    RedCar.push_back(new AnimatedRect("Car-Front-Red-icon.png", 1, 1, 10, -0.045, 0.4, 0.1, 0.1));
    //left lane
    RedCar.push_back(new AnimatedRect("blue-tesla.png", 1, 1, 10, -0.14, 0.4, 0.1, 0.1));
    //balloon in background 
    Balloon = new AnimatedRect("balloon.png", 1, 1, 100, 0.5, .8, 0.15, 0.15);  //Ballon
    //cop car on side of the road
    CopCar = new AnimatedRect("copcar.png", 1, 1, 10, -0.4, 0.4, 0.15, 0.15);  //CopCar
    
  

}

void App::draw() {

    Background->draw2(0.15);
    TaxiFront->draw2(0.25);
    TaxiFront->playOnce();
    CopCar->draw2(0.25);
    Balloon->draw2(0.25);    
    Coin[0]->draw(0.55);

    for(int i = 0; i < RedCar.size(); i++){
        RedCar[i]->draw(0.25);
    }
    
}

void App::keyDown(unsigned char key, float x, float y){
  
    if (key == 27){
        exit(0);
    }
    
    if (key == ' '){
       cout<< "Start Game"<< endl;
       start = true;       
        
        for(int i = 0; i < RedCar.size(); i++){
            RedCar[i]->playOnce();
            Coin[0]->playOnce();  
          }
                
    }

    //taxi goes left
    if(key == 'a'){
        cout<<"left"<<endl;
        left = true;      
    }

    //taxi goes right
    if(key == 'd'){
        cout<<"right"<<endl;
        right = true; 
    }


    
}

void App::idle(){  
    cout<<"idle"<<endl;
    
    while(left){
    TaxiFront->x -=.03;
    left = false;   
    }

    while(right && TaxiFront->x != .5){
    TaxiFront->x +=.03;
    right = false;
    }




}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete TaxiFront;
    delete Background;
    delete Balloon;
    delete CopCar;
    delete RedCar[0];
    delete Coin[0];           // Uncomment
}


