#include "ElementTree.h"
#include <iostream>
using std::cout;
using std::endl;

ElementTree::ElementTree(Element* root)
{
    if(root != nullptr)
    {
        _rootNode = root;
        _rootNode->setChildrenFlag(true);
        cout << "Top Node is set" << endl;
    }
}

ElementTree::~ElementTree()
{
    
}

ElementTree::ElementTree(const ElementTree& other)
{
    
}

