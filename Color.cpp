#include "Color.h"


Color::Color() 
{
   
    _pack.bytes[2] = 0;
    _pack.bytes[1] = 0;
    _pack.bytes[0] = 0;
    _pack.colorRef = 0;
}
    
Color::Color(BYTE red,BYTE green,BYTE blue) 
{
    _pack.bytes[2] = red;
    _pack.bytes[1] = green;
    _pack.bytes[0] = blue;
    
}



Color::Color(COLORREF color)
{
   this->_colorRef = color;
}
    
Color::Color(const Color& other)
{
   *this = other;
}

Color::~Color()
{
    
}

Color Color::operator=(const Color& other)
{
    _pack = other._pack;
    return *this;
}

Color::operator COLORREF()const
{
    return _colorRef;
}
    
Color Color::operator=(COLORREF color)
{
    _colorRef = color;
    return *this;
    
}
    
UINT16 Color::getRed()const
{
    return _pack.bytes[RED_INDEX];
}
    
void Color::setRed(UINT16 red)
{
    _pack.bytes[RED_INDEX] = red;    
}

UINT16 Color::getGreen()const
{
    return _pack.bytes[GREEN_INDEX]; 
}

void Color::setGreen(UINT16 green)
{
    _pack.bytes[GREEN_INDEX] = green;
}

UINT16 Color::getBlue()const
{
    return _pack.bytes[BLUE_INDEX];
}
 
void Color::setBlue(UINT16 blue)
{
    _pack.bytes[BLUE_INDEX] = blue;
}






COLORREF Color::getColorRef()const
{
    return _pack.colorRef;
}

void Color::setColorRef(COLORREF ref)
{
    _pack.colorRef = ref;
}
