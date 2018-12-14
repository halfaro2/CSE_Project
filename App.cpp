#include <iostream>
#include "App.h"
#include <vector>
#include <unistd.h>

using namespace std;


App::App(int argc, char** argv): GlutApp(argc, argv){
   
    // first value row
    // second value column
    // third value is the rate
    // fourth value is the X position
    // fifth value is the Y position
    // sixth value is the width
    // seventh value is the height
    
    GameOver = new AnimatedRect("download.png", 1, 1, 100,-.7, .8 , 1.5, 1.5); // GAME OVER SCREEN
  
    Background = new TexRect("CityBackground.bmp",-1, 1, 2, 2); //SETS BACKGROUND

    TaxiFront = new TexRect("Taxi-Back-Yellow-icon.bmp", .1, -0.6, 0.5, 0.5);    //TAXI(PLAYER)
    
    RedCar.push_back(new TexRect("red-tesla.png",-0.1, 0.03 , 0.1, 0.1)); //LEFT LANE CAR
    RedCar.push_back(new TexRect("blue-tesla.png",0.01, 0.03, 0.1, 0.1)); //RIGHT LANE CAR
    
    fastExplosion1 = new AnimatedRect("explosion-sprite.png", 3, 5, 50, 0.1, -0.6, 0.5, 0.5);
    fastExplosion2 = new AnimatedRect("explosion-sprite.png", 3, 5, 50, -0.6, -0.6, 0.5, 0.5);


}

void App::draw() {

    Background->draw(0.15);
    TaxiFront->draw(0.25);
    RedCar[0]->draw(0.30);
    RedCar[1]->draw(0.30);
    fastExplosion1->draw(0.33);
    fastExplosion2->draw(0.33);
    GameOver->draw(0.55);
    
    
}

void App::keyDown(unsigned char key, float x, float y){
  
    if (key == 27){
        exit(0);
    }
    
    if (key == ' '){
       cout<< "Start Game"<< endl;


    }
    
   
    if(key == 'a'){ //GO LEFT
       
        TaxiFront-> x = -.6;
        TaxiFront->Redraw(0.25);
        collision(); 

    }
    
    if(key == 'd'){ //GO RIGHT
        
        TaxiFront-> x = .1;
        TaxiFront->Redraw(0.25);
        collision();
    }

    if(key == 'n'){
        RedCar[0]->x -= 0.1;
        RedCar[0]->y -= 0.126;
        RedCar[0]->Redraw(0.25);
    }
    if(key == '1'){ //GO TO FIRST POSITION OF RED
        RedCar[0]->x = -.2;
        RedCar[0]->y = -0.096;
        
        RedCar[0]->w = .1;
        RedCar[0]->h = .1;
        
        RedCar[0]->Redraw(0.25);
         collision(); //CHECKS COLLISION
        
    }
    if(key == '2'){ //GO TO SECOND POSITION OF RED
        RedCar[0]->x = -.3;
        RedCar[0]->y = -.222;
        
        RedCar[0]->w = .2;
        RedCar[0]->h = .2;
        
        RedCar[0]->Redraw(0.25);
         collision(); //CHECKS COLLISION
        
    }
    if(key == '3'){ //GO TO THIRD POSITION OF RED
        RedCar[0]->x = -.4;
        RedCar[0]->y = -0.348;
        
        RedCar[0]->w = .3;
        RedCar[0]->h = .3;
        
        RedCar[0]->Redraw(0.25);
         collision(); //CHECKS COLLISION
        
    }
    if(key == '4'){ //GO TO FORTH POSITION OF RED
        RedCar[0]->x = -.5;
        RedCar[0]->y = -0.474;
        
        RedCar[0]->w = .3;
        RedCar[0]->h = .3;
        
        RedCar[0]->Redraw(0.25);
         collision(); //CHECKS COLLISION
        
    }
    if(key == '5'){ //GO TO FIFTH POSITION OF RED
        RedCar[0]->x = -.6;
        RedCar[0]->y = -.6;
        
        RedCar[0]->w = .3;
        RedCar[0]->h = .3;
        
        RedCar[0]->Redraw(0.25);
         collision(); //CHECKS COLLISION
         resetLeft();
         RedCar[0]->Redraw(0.25);
        
    }
    if(key == '6'){ //GO TO FIRST POSITION OF BLUE
        RedCar[1]->x = .028;
        RedCar[1]->y = -.096;
        
        RedCar[1]->w = .1;
        RedCar[1]->h = .1;
        
        RedCar[1]->Redraw(0.25);
         collision(); //CHECKS COLLISION
    }
    if(key == '7'){ //GO TO SECOND POSITION OF BLUE
        RedCar[1]->x = .046;
        RedCar[1]->y = -.222;
        
        RedCar[1]->w = .2;
        RedCar[1]->h = .2;
        
        RedCar[1]->Redraw(0.25);
         collision(); //CHECKS COLLISION
    }
    if(key == '8'){ //GO TO THIRD POSITION OF THIRD
        RedCar[1]->x = 0.064;
        RedCar[1]->y = -0.348;
        
        RedCar[1]->w = .3;
        RedCar[1]->h = .3;
        
        RedCar[1]->Redraw(0.25);
         collision(); //CHECKS COLLISION
    }
    if(key == '9'){ //GO TO FORTH POSITION OF BLUE
        RedCar[1]->x = 0.082;
        RedCar[1]->y = -0.474;
        
        RedCar[1]->w = .3;
        RedCar[1]->h = .3;
        
        RedCar[1]->Redraw(0.25);
        collision(); //CHECKS COLLISION
         
    }
    if(key == '0'){ //GO TO FIFTH POSITION OF BLUE
        RedCar[1]->x = 0.1;
        RedCar[1]->y = -.6;
        
        RedCar[1]->w = .3;
        RedCar[1]->h = .3;
        

        RedCar[1]->Redraw(0.25);
         collision(); //CHECKS COLLISION

         resetRight();
         RedCar[1]->Redraw(0.25);
    }
}




void App::collision(){
        
    if(RedCar[0]->x == TaxiFront->x && RedCar[0]->y == TaxiFront->y){ // CHECKS IF TAXI (X,Y) == RED CAR(X,Y)
        cout<<"Game Over[Left Collision]"<<endl;
        fastExplosion2->playOnce(); //PLAYS EXPLOSIVE
        GameOver->playOnce(); //DISPLAY'S GAME OVER SCREEN

        RedCar[0]->x = -10; //REMOVES RED CAR
        RedCar[0]->y = -10; //REMOVES RED CAR


        TaxiFront->x = -10; // REMOVES TAXI
        TaxiFront->y = -10; // REMOVES TAXI


        
    }
    if(RedCar[1]->x == TaxiFront->x && RedCar[1]->y == TaxiFront->y){ // CHECKS IF TAXI (X,Y) == BLUE CAR(X,Y)
        cout<<"Game Over[Right Collision]"<<endl;
        fastExplosion1->playOnce(); //PLAYS EXPLOSIVE
        GameOver->playOnce(); //DISPLAY'S GAME OVER SCREEN

        RedCar[1]->x = -10; // REMOVES BLUE CAR
        RedCar[1]->y = -10; // REMOVES BLUE CAR

        TaxiFront->x = -10; //REMOVES TAXI
        TaxiFront->y = -10; //REMOVES TAXI
        
    }



}

void App::idle(){ 

}



void App::resetRight(){


    RedCar[1]->x = 0.01;
    RedCar[1]->y = 0.03;
    RedCar[1]-> w = 0.1;
    RedCar[1]-> h = 0.1;

}

void App::resetLeft(){


    RedCar[0]->x = -0.1;
    RedCar[0]->y = 0.03;
    RedCar[0]-> w = 0.1;
    RedCar[0]-> h = 0.1;

}



void App::displayTimer(){

}

App::~App(){ // DECONSTRUCTOR
    std::cout << "Exiting..." << std::endl;
    delete TaxiFront;
    delete Background;
    delete RedCar[0];
    delete RedCar[1];
    delete GameOver;
    delete fastExplosion1;
    delete fastExplosion2;
}


