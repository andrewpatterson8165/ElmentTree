#include "ElementTree.h"


ElementTree::ElementTree(Element* root)
{
    if(root != nullptr)
    {
        _rootNode = root;
        _rootNode->setChildrenFlag(true);
        cout << "Top Node is set" << endl;
        _nodeIterator = root;
    }
    else
    {
        _nodeIterator = nullptr;
    }
    
    _rootList = nullptr;
    _listIterator = nullptr;
}


ElementTree::ElementTree(const ElementTree& other)
{
    
}


ElementTree::~ElementTree()
{
    
}

void ElementTree::addChildList()
{
    if(_nodeIterator != nullptr)
    {
        _nodeIterator->setChildrenFlag(true);
        ElementList* newList = new ElementList(_nodeIterator);
        
        if(_listIterator == nullptr)
        {
            _rootList = newList;
            _listIterator = _rootList;
            _listIterator->_next = nullptr;
            _listIterator->_previous = nullptr;
            
        }
        else
        {
            
        } 
    }
}

void ElementTree::printTree()
{
    Element* nodeItr = _rootNode;
}

void ElementTree::printTree()
{
    
}
