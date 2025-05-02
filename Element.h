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
    
    Element* getNextNode()const;
    void setNextNode(Element* element);
    
    Element* getPreviousNode()const;
    void setPreviousNode(Element* element);
    void setListPtr(void* listPtr){_listPtr = listPtr};
    void* getListPtr(){return _listPtr;};
    
private:
    Element* _next;
    Element* _previous;
    bool _hasChildren;
    Element* _childListHead;
    Element* _parent;
    HANDLE _handle;
    void* _listPtr;
};

#endif
