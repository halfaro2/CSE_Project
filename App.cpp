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
    
    fastExplosion = new AnimatedRect("fireball.bmp", 6, 6, 10, 0.1, -0.6, 0.5, 0.5);
    

}

void App::draw() {

    Background->draw(0.15);
    TaxiFront->draw(0.25);
    fastExplosion->draw(0.30);
    

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
        while(start == true){
            if((RedCar[0] -> x != -.6 ) && (RedCar[0] ->y != -.6)){
            cout<<"decreasing values"<<endl;
            RedCar[0]->x -= 0.1;
            RedCar[0]->y -= 0.126;
            RedCar[0]->Redraw(0.25);
            }
            if ((RedCar[0] -> x == -.6 ) && (RedCar[0] ->y == -.6)) {
                break;
            }
        }
                    
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
        // RedCar[0]->x = TaxiFront ->x;
        // RedCar[0]->y = TaxiFront -> y;
        // collision();
    }

    if(key == 'n'){
        RedCar[0]->x -= 0.1;
        RedCar[0]->y -= 0.126;
        RedCar[0]->Redraw(0.25);
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
        fastExplosion->playLoop();
        
    }
    if((RedCar[0] -> x == 0.1) && RedCar[0] -> y == 0.5){
        cout<<"Exiting game[Right Collision]"<<endl;
        fastExplosion->playOnce();
        exit(0);
    }

}

void App::idle(){  
//    while(start == true){
//        cout<<"decreasing values"<<endl;
//        RedCar[0]->x -= 0.1;
//        RedCar[0]->y -= 0.126;
//        RedCar[0]->Redraw(0.25);
//}
        glutPostRedisplay();
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
    delete Coin[0];
    delete fastExplosion;
}


