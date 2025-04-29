/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include "ElementList.h"
using std::endl;
using std::cout;

int main()
{
    ElementList list1;
    Element mainWindow("Main Window",100,nullptr);
    Element fileDialog("FileDialog",200,&mainWindow);
    Element aboutDialog("AboutDialog,",210,&mainWindow);
    
    list1.addElement(&fileDialog);
    
    list1.addElement(&aboutDialog);
    ElementList list2(list1);
   
    UINT16 resource = 200;
    Element* searchElement = list2.findReference(resource);
    if(searchElement == &fileDialog)
    {
        cout << "Match Found" << endl;
        cout << "Name = "  << searchElement->_name << endl;
        cout << "Reference Test Passed" << endl;
    }

    return 0;
}
