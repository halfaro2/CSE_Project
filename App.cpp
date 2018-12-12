#include <iostream>
#include "App.h"
#include <vector>
using namespace std;



App::App(int argc, char** argv): GlutApp(argc, argv){
   
    // first value row
    // second value column
    // third value is the rate
    // fourth value is the X position
    // fifth value is the Y position
    // sixth value is the width
    // seventh value is the height
    
    //background
    Background = new TexRect("background.png",-1, 1, 2, 2); 

    //the taxi (player)
    TaxiFront = new AnimatedRect("Taxi-Back-Yellow-icon.bmp", 1, 1, 100, -0.275, -0.6, 0.5, 0.5);    //TaxiFront
    
    //right lane
    RedCar.push_back(new AnimatedRect("blue-tesla.png", 1, 1, 10, 0.045, 0.4, 0.1, 0.1));
    //middle lane
    RedCar.push_back(new AnimatedRect("Car-Front-Red-icon.png", 1, 1, 10, -0.045, 0.4, 0.1, 0.1));
    //left lane
    RedCar.push_back(new AnimatedRect("blue-tesla.png", 1, 1, 10, -0.14, 0.4, 0.1, 0.1));
    
    //added coin for an extra 10 points  
    //need to make them come later once the timer starts to not conflict with cars coming  
    Coin.push_back(new AnimatedRect("bitcoin-icon.bmp", 1, 1, 100, -.090, 0, .15, .15));
    
   
  

}

void App::draw() {

    Background->draw(0.15);
    TaxiFront->draw(0.25); 
    TaxiFront->playOnce();
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
        
        
        for(int i = 0; i < RedCar.size(); i++){
            RedCar[i]->playOnce();
            Coin[0]->playOnce();  
          }
                
    }


    //going left
    if(key == 'a'){
        if(TaxiFront->x = -0.275 && TaxiFront->x != 0.6){
            cout<<"going to left"<<endl;
            TaxiFront->x = -1;
            cout<<TaxiFront->x<<endl;
            TaxiFront->playOnce();
        }
        else if(TaxiFront->x = 0.6){
            cout<<"going to center"<<endl;
            TaxiFront->x = -0.275;
            cout<<TaxiFront->x<<endl;
            TaxiFront->playOnce();
        }

    }

    //going right
    if(key == 'd'){
        if(TaxiFront->x = -0.275 && TaxiFront->x != -1){
            cout<<"going to right"<<endl;
            TaxiFront->x = 0.6;
            cout<<TaxiFront->x<<endl;
            TaxiFront->playOnce();
        }
        else if(TaxiFront->x = -1){
            cout<<"going to center"<<endl;
            TaxiFront->x = -0.275;
            cout<<TaxiFront->x<<endl;
            TaxiFront->playOnce();
        }
    }






    // //taxi goes left
    // if(key == 's'){
    //     TaxiFront-> x = -.275;
    //     cout<<"center"<<endl;
    // }

    // //taxi goes right
    // if(key == 'd'){
    //     TaxiFront-> x = .60;
    //     cout<<"right"<<endl;
    // }
    // if(key == 'a'){
    //     TaxiFront-> x = -.99;
    //     cout<<"left"<<endl;
       
    // }

}

void App::idle(){  
    //cout<<"idle"<<endl;
    
}

void App::displayTimer(){

}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete TaxiFront;
    delete Background;
    delete RedCar[0];
    delete Coin[0];           // Uncomment
}


