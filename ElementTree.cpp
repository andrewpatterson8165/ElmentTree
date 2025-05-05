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


Element* ElementTree::findElement(Element* itr, string name)
{
    Element* elem = nullptr;
    
    if (itr == nullptr) 
    {
        elem = itr;
        return elem;
    }
    if (itr->getName() == name) 
    {
        cout << "Match Found"  << endl;
        cout << "getName() return: " << itr->getName() << endl;
        return itr;
    }
    
    if (name < itr->getName()) 
    {
        if(itr->getChildRoot() != nullptr)
        {   cout << "Searching Downward" << endl;
            return findElement(itr->getChildRoot(), name);
        }
    } 
    else 
    {
        if(itr->getNextNode() != nullptr)
        {
            cout << "Searching Rightward" << endl;
            return findElement(itr->getNextNode(), name);
        }
    }
    return elem;    
}
