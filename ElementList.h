#ifndef ELEMENTLIST_H_
#define ELEMENTLIST_H_

#include "Element.h"

class ElementList
{
public:
    ElementList();
    ~ElementList();
    
    void addElement(Element* elem);
    void removeElement(unsigned short id);
    void removeElement(string name);
    bool find(unsigned short id);
    bool find(unsigned int handle);
    bool find(string name);
    //void addChildList(ElementList* el);
    

    Element* _head;
    Element* _current;
    Element* _tail;
    int _nodeCount;
    
};

#endif 
