#include <iostream>
#include "Element.h"

using std::endl;
using std::cout;


int main()
{
    Element mainWindow("mainWindow", 01,nullptr);
    Element fileDialog("fileDialog", 100,&mainWindow);
    
    Element fileSaveAsButton("fileSaveAsButton",204,&fileDialog);
    Element fileCancelButton("fileCancelButton",205,&fileDialog);
    
    Element editDialog("editDialog", 101,&mainWindow);
    Element searchButton("searchButton",201,&editDialog);
    Element findButton("findButton",202,&editDialog);
    Element replaceButton("replaceButton",203,&editDialog);

    Element fontDialog("fontDialog", 102,&mainWindow);
    Element aboutDialog("aboutDialog,",103,&mainWindow);
    
    
    cout << "Unit Test" << endl;
    
    mainWindow.addChildElement(&fileDialog);
    mainWindow.addChildElement(&editDialog);
    mainWindow.addChildElement(&fontDialog);
    mainWindow.addChildElement(&aboutDialog);
    cout << "Number of Elements = " << mainWindow.getChildList().size() << endl;
    Element* ref = mainWindow.findChildElement("fileDialog");
    if(ref != nullptr)
    {
        ref->addChildElement(&fileSaveAsButton);
        ref->addChildElement(&fileCancelButton);
        cout << "Number Of elements = " << ref->getChildList().size() << endl;
        
    }
    
    
    

    return 0;
}
