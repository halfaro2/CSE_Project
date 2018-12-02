//
//  background.h
//  glutapp
//
//  Created by Hector Alfaro on 12/2/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef background_h
#define background_h

class Background : public TextRect {
private:
    float x;
    float y;
    float w;
    float h;
   
    
public:
    Background(float x = 0, float y = 0, float w = 0.5, h = 0.5)
    this -> x = x;
    this -> y = y;
    this -> w = w;
    this -> h = h;
};


#endif /* background_h */
