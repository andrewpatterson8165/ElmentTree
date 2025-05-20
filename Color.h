#ifndef COLOR_H_
#define COLOR_H_
#include "WinDef.h"


class Color
{
public:

    const UINT RED_INDEX = 2;
    const UINT GREEN_INDEX = 1;
    const UINT BLUE_INDEX = 0;

    Color();
    
    Color(BYTE red, BYTE green, BYTE blue);
   
    Color(COLORREF color);
  
    Color(const Color& other);
    
    ~Color();

    Color operator=(const Color& other);
    
    operator COLORREF()const;
    
    Color operator=(COLORREF color);
    
    UINT16 getRed()const;
    void setRed(UINT16 red);

    UINT16 getGreen()const;
    void setGreen(UINT16 green);

    UINT16 getBlue()const;
    void setBlue(UINT16 blue);    

    COLORREF getColorRef()const;
    void setColorRef(COLORREF ref);
    
    void extractBytes();
    void printValues();

    void setBit(bool value, UINT16 position);
    bool getBit(UINT16 indexPosition);
private:

    BYTE _red;
    BYTE _green;
    BYTE _blue;
    
    COLORREF _colorRef;


};

#endif

