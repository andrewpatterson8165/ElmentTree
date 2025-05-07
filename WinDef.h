#ifndef WINDEF_H_
#define WINDEF_H_

typedef unsigned short UINT16;
typedef unsigned int HANDLE;

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

