#include "ElementTree.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

ElementTree::ElementTree(Element* root)
{
    if(root != nullptr)
    {
        _rootNode = root;
        _rootNode->setChildrenFlag(true);
        cout << "Top Node is set" << endl;
        
    }

    _levelCount = 0;
    _totalNodeCount = 0;
}


ElementTree::ElementTree(const ElementTree& other)
{
    
}


ElementTree::~ElementTree()
{
    
}




void ElementTree::addChildElement(Element *newElement,Element* parent)
{
    //Find Parent before we add the child node in a child setChildList
    if(parent != nullptr)
    {
        //Ensure that the parent node has a list added to it.
        if(parent->getChildList() != nullptr)
        {
            //Get the reference to the list
            ElementList* list = 
                reinterpret_cast<ElementList*>(parent->getChildList());
            //Check to see if the new element is valid
            if(newElement != nullptr)
            {
                if(newElement->getParentElement() != parent)
                {
                    cerr << "parent mismatch"  << endl;
                }
                else if(list != nullptr) //add a new element without error
                {
                    list->addElement(newElement);
                }
            }
        }
        else
        {
            parent->setChildrenFlag(true);
            ElementList *newList = new ElementList(parent);
            parent->setChildList(newList);
            newList->addElement(newElement);
            _levelCount++;
           
            
        }
        _totalNodeCount++;
        cout << "Total Node Count = " << _totalNodeCount << endl;
    }
    else
    {
        cerr << "ElementTree::addChildElement() - Bad parent ref" << endl;
    }
}


Element* ElementTree::find(string name,Element* itr)
{
    if(itr != nullptr)
    {
        if(itr->_name == name)
        {
            //return if a match is found
            cout << "Match Found " << endl;
            return itr;
        }
        if(itr->hasChildren())
        {
            
             //Get the reference to the list
            ElementList* list = 
                reinterpret_cast<ElementList*>(itr->getChildList());
            if(list != nullptr)
            {
                Element* fwd = list->findReference(name);
                if(fwd != nullptr)
                {
                    cout << "found match in child list" << endl;
                    return fwd;
                }
                else
                {
                    cout << "recursion call"  << endl;
                    fwd = find(name,list->getHeadNode());
                    
                }
            }
        }
        else if(itr->_next != nullptr)
        {
            itr = find(name,itr->next)
            if(itr != nullptr)
            {
                return nullptr;
            }
        }
    }
    return nullptr;    
        
        
}
