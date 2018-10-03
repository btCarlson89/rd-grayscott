//
//  PingPong.hpp
//  gray-scott-shader
//
//  Created by Brian on 10/2/18.
//
//

#pragma once

#include "ofMain.h"

class PingPong {
public:
    
    PingPong();
    
    void allocate(int _width, int _height, int _internalformat = GL_RGBA32F_ARB);
    void swap();
    void clear();
    
    ofFbo& operator[](int n){ return fbos[n]; }
    ofFbo* src = &fbos[0];
    ofFbo* dst = &fbos[1];
        
    
private:
    
    ofFbo fbos[2];
};
