##ifndef ELEMENTTREE_H
#define ELEMENTTREE_H


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
    void addChildElement(Element *newElement,Element* parent);
    
    
    
    
public:
    Element* _rootNode;
    ElementList *_rootList;
    
    Element* _nodeIterator;
    ElementList* _listIterator;
    
};

#endif
