#ifndef AnimatedRect_h
#define AnimatedRect_h

#include "TexRect.h"
#include "Timer.h"

class AnimatedRect: public TexRect, protected Timer {
    
    int rows;
    int cols;
    
    int curr_row;
    int curr_col;
    
    bool complete;
    bool animating;
    bool loop;
    bool left;
    bool right;
    
    void advance();
    bool done();
    
public:
    
    AnimatedRect (const char*, int, int, int, float, float, float, float);
    
    virtual void draw(float z);

    void draw2(float z){
        glBindTexture( GL_TEXTURE_2D, texture_id );
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        
        
        float xinc = 1.0/cols;
        float yinc = 1.0/rows;
        
        
        float top = 1 - yinc * (curr_row - 1);
        float bottom = 1 - yinc * curr_row;
        
        float left = xinc * (curr_col - 1);
        float right = xinc * curr_col;
        
        
        glBegin(GL_QUADS);
        
        glTexCoord2f(left, bottom);
        glVertex3f(x, y - h, z);
        
        glTexCoord2f(left, top);
        glVertex3f(x, y, z);
        
        glTexCoord2f(right, top);
        glVertex3f(x+w, y, z);
        
        glTexCoord2f(right, bottom);
        glVertex3f(x+w, y - h, z);
        
        glEnd();
        
        glDisable(GL_TEXTURE_2D);
    }
    
    void playLoop();
    
    void playOnce();
    
    void reset();
    
    void pause();
    
    void resume();
    
    void action();

    void play();
    
};

#endif
