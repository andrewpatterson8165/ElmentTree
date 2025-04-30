#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <string>
using std::string;

#include "WinDef.h"


class Element
{
public:
    Element(string name,UINT16 id,Element* parent);
    ~Element();
    
    Element(const Element& other);
    
    bool hasChildren(){return _hasChildren;}
    int _childCount;
    string _name;
    UINT16 _resourceId;
    HANDLE _handle;
    
     
    string getName()const;
    UINT16 getResourceId()const;
    
    HANDLE getHandle()const;
    void setHandle(HANDLE handle);
    
    void setChildrenFlag(bool state);
    bool hasChildren()const;
    
    void setChildrenFirstElement(Element* element);
    Element* getChildrenFirstElement()const;
    Element* getParentElement()const; 
    void setParentElement(Element* parent);
    
    
    
    Element* _next;
    Element* _previous;
    
private:
    bool _hasChildren;
    Element* _childListHead;
    Element* _parent;
};

#endif
