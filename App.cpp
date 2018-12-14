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
    bool gameOver = false;
    bool start =  false;

  //background
    Background = new TexRect("CityBackground.bmp",-1, 1, 2, 2);

    //the taxi (player)
    TaxiFront = new TexRect("Taxi-Back-Yellow-icon.bmp", .1, -0.6, 0.5, 0.5);    //TaxiFront
    //-0.6 left  (-0.6, -0.6)
    //0.1  right (0.1, -0.6)
    
    //left lane
    RedCar.push_back(new TexRect("red-tesla.png",-0.1, 0.03 , 0.1, 0.1));

    //right lane
    RedCar.push_back(new TexRect("blue-tesla.png",0.01, 0.03, 0.1, 0.1));
    
    //added coin for an extra 10 points  
    //need to make them come later once the timer starts to not conflict with cars coming  
    Coin.push_back(new TexRect("bitcoin-icon.bmp", -.090, 0.1, .15, .15));
     
   
  

}

void App::draw() {

    Background->draw(0.15);
    TaxiFront->draw(0.25); 
    

    for(int i = 0; i < RedCar.size(); i++){
        RedCar[i]->draw(0.25);
    }

    for(int i = 0; i < Coin.size(); i++){
        Coin[i]->draw(0.55);
    }
    
}

void App::keyDown(unsigned char key, float x, float y){
  
    if (key == 27){
        exit(0);
    }
    
    if (key == ' '){
       cout<< "Start Game"<< endl;
       start = true;
        idle();                     
    }
    
    //going left
    if(key == 'a'){
        cout<<"left"<<endl;
        TaxiFront-> x = -.6;
        TaxiFront->Redraw(0.25);
    }
    //going right
    if(key == 'd'){
        cout<<"right"<<endl;
        TaxiFront-> x = .1;
        TaxiFront->Redraw(0.25);
    }
}


void App::moveObjects(){
    


       
}



void collision(float px, float py){
        
     // if (isGameOver()){
     //  cout << "Game Over!" << endl;
     //  gameOver = true;
     //  }

}

void App::idle(){  

     if(start == true){
 
        for(int i = 0; i < 5; i++){
           
            cout<<"car and coin going down"<<endl;
            RedCar[0]->y -= 0.18;
            RedCar[0]->x -= .1;
            RedCar[0]->w += .1;
            RedCar[0]->h += .1;
            RedCar[0]->Redraw(0.25);
            
            

        }

        reset();


    }


    
}


void App::reset(){

    RedCar[0]->x = -0.1;
    RedCar[0]->y = 0.03;
    RedCar[0]-> w = 0.1;
    RedCar[0]-> h = 0.1;

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


