
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
