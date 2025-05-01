#ifndef ELEMENTLIST_H_
#define ELEMENTLIST_H_

#include "Element.h"
#include "WinDef.h"

class ElementList
{
public:
    ElementList(Element* parentElement = nullptr);
    ~ElementList();
    ElementList(const ElementList& other);

    Element* operator++();
    Element* operator--();



    void setHead(Element* head);
    Element* getTail();
    Element* getCurrentNode();
    void addElement(Element* element);
    int getCount();
    bool isEmpty();

    ///WARNING: These methods are not safe 
    ///         and should be used carefully.
    Element* findReference(string name);
    Element* findReference(UINT16 resourceId);
    Element* findReference(HANDLE handle);
    



private:
    Element* _parentElement;
    Element* _head;
    Element* _tail;
    Element* _currentNode;
    int _count;
    bool _isEmpty;
};


#endif
