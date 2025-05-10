#include "UnitTest.h"
#include <iostream>
using std::cout;
using std::endl;


UnitTest::UnitTest()
{
    cout << "Unit Test"  << endl;
    
}

UnitTest::~UnitTest()
{
    
}


UnitTest::UnitTest(const UnitTest& other)
{
    
}




void UnitTest::initVars()
{
    _mainWindow = new Element("mainWindow", 0001,nullptr);
    _fileDialog = new Element("fileDialog", 100, _mainWindow);
    _fileDialogSaveButton = new Element("fileDialogSaveButton",200,_fileDialog);
    
    _fileDialogCancelButton = new Element("fileDialogCancelButton",201,_fileDialog);
    _findReplaceDialog = new Element("findReplaceDialog", 101, _mainWindow);
    _findReplaceDialogFindButton = new Element("findReplaceDialogFindButton",202,_findReplaceDialog);
    _findReplaceDialogReplaceButton = new Element("findReplaceDialogReplaceButton",203,_findReplaceDialog);
    _fontDialog = new Element("fontDialog",102,_mainWindow);
    
    _fontDialogOkButton = new Element("fontDialogOkButton", 204,_fontDialog);
    _fontDialogColorButton = new Element("fontDialogColorButton",205,_fontDialog);
    _fontDialogSizeButton = new Element("fontDialogSizeButton",206,_fontDialog);
    _aboutDialog = new Element("AboutDialog", 103,_mainWindow);   
 
    _aboutScrollButton = new Element("aboutScrollButton",207,_aboutDialog);
    _aboutOkButton = new Element("aboutOkButton",208,_aboutDialog);
    
  
    cout << "Main Window has " << _mainWindow->childCount() << endl;
    cout << "File Dialog has "  << _fileDialog->childCount() << endl;
    cout << "Find/Replace Dialog has " << _findReplaceDialog->childCount() << endl; 
}



bool UnitTest::findInTree(Element* itr, string name)
{
    bool flag = false;
    if(itr == nullptr)
    {
        return false;
    }
    if(itr->getName() == name)
    {
        return true;
    }
    else
    {
        if(itr->findChildElement(name))
        {
            return true;
        }
        else
        {
           // Element* ref = itr->getChildList().front();
            
            for(auto it : itr->getChildList())
            {
                if(it->hasChildren())
                {
                   
                    flag = findInTree(it,name);
                    if(flag) 
                    {
                        return true;
                    }
                }
            }
            if(flag)
            {
                return true;
            }
            
        }
    }
    return flag;
}

