//
//  PingPong.cpp
//  gray-scott-shader
//
//  Created by Brian on 10/2/18.
//
//

#include "PingPong.h"

PingPong::PingPong()
{
    
}

void PingPong::allocate(int _width, int _height, int _internalformat)
{
    //  Allocate
    for(int i = 0; i < 2; ++i)
    {
        fbos[i].allocate(_width, _height, _internalformat);
        fbos[i].getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    }
    
    //  Clean
    clear();
}

void PingPong::swap()
{
    std::swap(src, dst);
}

void PingPong::clear()
{
    for(int i = 0; i < 2; ++i)
    {
        fbos[i].begin();
        ofClear(0, 255);
        fbos[i].end();
    }
}
