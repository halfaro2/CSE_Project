#include <iostream>
#include "App.h"
#include <vector>
#include <unistd.h>



using namespace std;


unsigned int microseconds = 600000;



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

    GameOver = new AnimatedRect("download.png", 1, 1, 100,-.7, .8 , 1.5, 1.5);
  


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
    
    fastExplosion1 = new AnimatedRect("explosion-sprite.png", 3, 5, 50, 0.1, -0.6, 0.5, 0.5);

    fastExplosion2 = new AnimatedRect("explosion-sprite.png", 3, 5, 50, -0.6, -0.6, 0.5, 0.5);


    

   
    



}

void App::draw() {

    Background->draw(0.15);
    TaxiFront->draw(0.25);
    RedCar[0]->draw(0.25);
    RedCar[1]->draw(0.25);
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

       fastExplosion1->playLoop();

    }
    
    //going left
    if(key == 'a'){
        cout<<"left"<<endl;
        TaxiFront-> x = -.6;
        TaxiFront->Redraw(0.25);
        collision(); 

    }
    //going right
    if(key == 'd'){
        cout<<"right"<<endl;
        TaxiFront-> x = .1;
        TaxiFront->Redraw(0.25);
        collision(); 

//        RedCar[0]->x = TaxiFront ->x;
//        RedCar[0]->y = TaxiFront -> y;
//        collision();

    }

    if(key == 'n'){
        RedCar[0]->x -= 0.1;
        RedCar[0]->y -= 0.126;
        RedCar[0]->Redraw(0.25);
    }
    if(key == '1'){
        RedCar[0]->x = -.2;
        RedCar[0]->y = -0.096;
        
        RedCar[0]->w = .1;
        RedCar[0]->h = .1;
        
        RedCar[0]->Redraw(0.25);
         collision();
        
    }
    if(key == '2'){
        RedCar[0]->x = -.3;
        RedCar[0]->y = -.222;
        
        RedCar[0]->w = .2;
        RedCar[0]->h = .2;
        
        RedCar[0]->Redraw(0.25);
         collision();
        
    }
    if(key == '3'){
        RedCar[0]->x = -.4;
        RedCar[0]->y = -0.348;
        
        RedCar[0]->w = .3;
        RedCar[0]->h = .3;
        
        RedCar[0]->Redraw(0.25);
         collision();
        
    }
    if(key == '4'){
        RedCar[0]->x = -.5;
        RedCar[0]->y = -0.474;
        
        RedCar[0]->w = .3;
        RedCar[0]->h = .3;
        
        RedCar[0]->Redraw(0.25);
         collision();
        
    }
    if(key == '5'){
        RedCar[0]->x = -.6;
        RedCar[0]->y = -.6;
        
        RedCar[0]->w = .3;
        RedCar[0]->h = .3;

        cout<<RedCar[0]->x<<endl;
        cout<<RedCar[0]->y<<endl;
        
        RedCar[0]->Redraw(0.25);
         collision();
        
    }
    if(key == '6'){
        RedCar[1]->x = .028;
        RedCar[1]->y = -.096;
        
        RedCar[1]->w = .1;
        RedCar[1]->h = .1;
        
        RedCar[0]->Redraw(0.25);
         collision();
    }
    if(key == '7'){
        RedCar[1]->x = .046;
        RedCar[1]->y = -.222;
        
        RedCar[1]->w = .2;
        RedCar[1]->h = .2;
        
        RedCar[0]->Redraw(0.25);
         collision();
    }
    if(key == '8'){
        RedCar[1]->x = 0.064;
        RedCar[1]->y = -0.348;
        
        RedCar[1]->w = .3;
        RedCar[1]->h = .3;
        
        RedCar[0]->Redraw(0.25);
         collision();
    }
    if(key == '9'){
        RedCar[1]->x = 0.082;
        RedCar[1]->y = -0.474;
        
        RedCar[1]->w = .3;
        RedCar[1]->h = .3;
        
        RedCar[0]->Redraw(0.25);
         collision();
    }
    if(key == '0'){
        RedCar[1]->x = 0.1;
        RedCar[1]->y = -.6;
        
        RedCar[1]->w = .3;
        RedCar[1]->h = .3;
        
        cout<<RedCar[0]->x<<endl;
        cout<<RedCar[0]->y<<endl;

        RedCar[0]->Redraw(0.25);
         collision();
    }
}

void App::CarDown(){
//    cout<<"decreasing values"<<endl;
//    RedCar[0]->x -= 0.1;
//    RedCar[0]->y -= 0.126;
//    RedCar[0]->Redraw(0.25);
}




void App::collision(){
        
    if(RedCar[0]->x == TaxiFront->x && RedCar[0]->y == TaxiFront->y){
        cout<<"Exiting game[Left Collision]"<<endl;
        fastExplosion2->playOnce();
        GameOver->playOnce();

        RedCar[0]->x = -10;
        RedCar[0]->y = -10;


        TaxiFront->x = -10;
        TaxiFront->y = -10;


        
    }
    if(RedCar[1]->x == TaxiFront->x && RedCar[1]->y == TaxiFront->y){
        cout<<"Exiting game[Right Collision]"<<endl;
        fastExplosion1->playOnce();
        GameOver->playOnce();

        RedCar[1]->x = -10;
        RedCar[1]->y = -10;

        TaxiFront->x = -10;
        TaxiFront->y = -10;
        
    }



}

void App::idle(){ 



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
    delete RedCar[1];
    delete GameOver;
    delete fastExplosion1;
    delete fastExplosion2;
}


