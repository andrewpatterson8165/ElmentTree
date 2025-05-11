
ElementTree::ElementTree(Element* root)
{
}

ElementTree::


bool ElementTree::findInTree(Element* itr, string name)
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
        Element* ref = itr->findChildElement(name);
        if(ref != nullptr)
        {
            
            return true;
        }
        else
        {
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
        }
    
    }
    return flag;
}

//TODO - DEBUG ME!!!
bool ElementTree::findInTree(Element* itr, UINT16 resourceId)
{
    bool flag = false;
    if(itr == nullptr)
    {
        return false;
    }
    if(itr->getResourceId() == resourceId)
    {
        return true;
    }
    else
    {
        Element* ref = itr->findChildElement(resourceId);
        if(ref != nullptr)
        {
            return true;
        }
        else
        {
            for(auto it : itr->getChildList())
            {
                if(it->hasChildren())
                {
                    cout << "child Name ="  << it->getName() << endl;
                    cout << "Iterator Has Children Flag = true"  << endl;
                   
                    flag = findInTree(it,resourceId);
                    if(flag)
                    {
                        cout << "Match Found"  << endl;
                        return true;
                    }
                }
               
            }
        }
    
    }
    return flag;
}
