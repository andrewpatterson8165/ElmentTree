#ifndef COLOR_H_
#define COLOR_H_

#include "WinDef.h"

class Color
{
public:
    Color();
    Color(BYTE red,BTYE green,BYTE blue);
    Color(COLORREF color);
    Color(const Color& other);
    ~Color();

    

    BYTE getRed();
    void setRed(BYTE red);

    BYTE getGreen();
    void setGreen(BYTE green);

    BYTE getYellow();
    void setYellow(BYTE yellow);    

private:
    BYTE _red;
    BYTE _green;
    BYTE _blue;
    COLORREF _value;


}

#endif

