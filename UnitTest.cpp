#include "Element.h"


void testMain()
{
    Element mainWindow("mainWindow",001,nullptr);
    Element fileDialog("fileDialog", 100,&mainWindow);
    Element fileDialogSaveButton("fileDialogSaveButton", 200,&fileDialog);
    Element fileDialogCancelButton("fileDialogCancelButton", 201,&fileDialog);
    Element findReplaceDialog("findReplaceDialog",203,&mainWindow);
}







bool findInTree(Element* itr, string name)
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


