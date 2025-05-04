#ifndef ELEMENTTREE_H
#define ELEMENTTREE_H
#include <iostream>
using std::cout;
using std::endl;

#include "Element.h"
#include "ElementList.h"

class ElementTree
{
public:
    ElementTree(Element* root);
    ElementTree(const ElementTree& other);
    ~ElementTree();
    
    void printTree();
    void addChildList();
    ElementList getCurrentList()const;

    
    
public:
    Element* _rootNode;
    ElementList *_rootList;
    
    Element* _nodeIterator;
    ElementList* _listIterator;
    
};

#endif
