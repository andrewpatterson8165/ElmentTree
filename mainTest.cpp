#include <iostream>
#include "ElementTree.h"
using std::endl;
using std::cout;
int main()
{
   
    Element mainWindow("MainWindow",001,nullptr);
    ElementList mwChildList;

    
    
    ElementTree et(&mainWindow);
    Element fileDialog("FileDialog",10, &mainWindow);
    
    mainWindow.setChildListHead(&fileDialog);
    mwChildList.setHead(&fileDialog);
    mainWindow.setListPtr(&mwChildList);
    Element searchDialog("SearchDialog",11,&mainWindow);
    mwChildList.addElement(&searchDialog);
    
    if(mwChildList.getHead() == &fileDialog)
    {
        cout << "Child List Head test -- PASS" << endl;
    }
    else
    {
        cout << "Child List Head Fail"  << endl;
    }
    

    
    return 0;
}
