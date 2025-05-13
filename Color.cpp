#include "Color.h"


Color::Color() 
{
    _pack.bytes[RED_INDEX] = 0;
    _pack.bytes[GREEN_INDEX] = 0;
    _pack.bytes[BLUE_INDEX] = 0;
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


void extractBytes(uint32_t dword, uint8_t bytes[4]) 
{
    uint8_t* bytePtr = reinterpret_cast<uint8_t*>(&dword);
    for (int i = 0; i < 4; ++i) 
    {
        bytes[i] = bytePtr[i];
    }
}


void extractBytes(uint32_t dword_value)
{
    
    uint8_t byte0 = static_cast<uint8_t>(dword_value & 0xFF);        // Least significant byte (DD)
    uint8_t byte1 = static_cast<uint8_t>((dword_value >> 8) & 0xFF);   // Second byte (CC)
    uint8_t byte2 = static_cast<uint8_t>((dword_value >> 16) & 0xFF);  // Third byte (BB)
    uint8_t byte3 = static_cast<uint8_t>((dword_value >> 24) & 0xFF);  // Most significant byte (AA)

}



int byteExtractTest() 
{
    uint32_t myDword = 0xAABBCCDD;
    uint8_t byte0, byte1, byte2, byte3;
    uint8_t byteArray[4];
    
    byteArray[0] = byte0;
    byteArray[1] = byte1;
    byteArray[2] = byte2;
    byteArray[3] = byte3;
    
    extractBytes(myDword, byteArray);
    byte0 = byteArray[0];
    byte1 = byteArray[1];
    byte2 = byteArray[2];
    byte3 = byteArray[3];

    cout << "Byte 0: 0x" << hex << static_cast<int>(byte0) << std::endl;
    cout << "Byte 1: 0x" << hex << static_cast<int>(byte1) << std::endl;
    cout << "Byte 2: 0x" << hex << static_cast<int>(byte2) << std::endl;
    cout << "Byte 3: 0x" << hex << static_cast<int>(byte3) << std::endl;

    extractBytes(myDword, byteArray);

    cout << "Byte array: 0x" << std::hex 
              << static_cast<int>(byteArray[0]) << " 0x"
              << static_cast<int>(byteArray[1]) << " 0x"
              << static_cast<int>(byteArray[2]) << " 0x"
              << static_cast<int>(byteArray[3]) << std::endl;
                 
    return 0;
}


