
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
