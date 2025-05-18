#include "Color.h"


Color::Color() 
{
    _red = 0x0;
    _green = 0x0;
    _blue = 0X0;
}
    
Color::Color(BYTE red,BYTE green,BYTE blue) 
{
   _red = red;
   _green = green;
   _blue = blue;
}



Color::Color(COLORREF color)
{
   _colorRef = color;
   extractBytes();
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
    _red = other._red;
    _green = other._green;
    _blue = other._blue;
    
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
    return _red; 
}
    
void Color::setRed(UINT16 red)
{
    _red = red;  
    
    // Set the third byte to red
    _colorRef = (_colorRef & 0xFF00FFFF) | _red;
}

UINT16 Color::getGreen()const
{
    return _green;
}

void Color::setGreen(UINT16 green)
{
    _green = green;
    _colorRef = (_colorRef & 0xFFFF00FF) | _green;
}

UINT16 Color::getBlue()const
{
    return _blue;
}
 
void Color::setBlue(UINT16 blue)
{
    _blue = blue;
}






COLORREF Color::getColorRef()const
{
    return _colorRef;
}

void Color::setColorRef(COLORREF ref)
{
    _colorRef = ref;
    extractBytes();
}


void Color::extractBytes() 
{
    _red = _colorRef >> 16 & 0XFF;
    _green = _colorRef >> 8 & 0XFF;
    _blue = _colorRef & 0XFF;
}

void Color::setBit(bool value, UINT16 position) 
{
   // Set a specific bit
    if (value) 
    {
      _colorRef |= (1 << position);
    } 
    else 
    {
      _colorRef &= ~(1 << position);
    }
}


string Color::toBinary(ColorRef n) 
{
    string binary = std::bitset<32>(n).to_string();
    
    size_t firstOne = binary.find('1');
    if (firstOne != std::string::npos) 
    {
        return binary.substr(firstOne);
    } 
    else 
    {
        return "0";
    }
}
