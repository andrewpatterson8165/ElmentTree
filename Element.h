#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <string>
#include <any>
using std::any;
using std::string;

#include "WinDef.h"


class Element
{
public:
    Element(string name,UINT16 id,Element* parent);
    ~Element();
    
    Element(const Element& other);
    
    
    int _childCount;
    string _name;
    UINT16 _resourceId;
    
    string getName()const;
    UINT16 getResourceId()const;
    
    HANDLE getHandle()const;
    void setHandle(HANDLE handle);
    
    void setChildrenFlag(bool state);
    bool hasChildren()const;
    
    void setChildListHead(Element* element);
    Element* getChildRoot()const {return _childListHead;};
    Element* getParentElement()const; 
    void setParentElement(Element* parent);
    
    Element* getNextNode()const;
    void setNextNode(Element* element);
    
    Element* getPreviousNode()const;
    void setPreviousNode(Element* element);
    
    //old interface (unsafe)
    void setChildList(void* listPtr);
    void* getChildList();
    
    //new interface (safe)
    void setList(any& anyList);
    any getList()const;
    
private:
    Element* _next;
    Element* _previous;
    bool _hasChildren;
    Element* _childListHead;
    Element* _parent;
    HANDLE _handle;
    any _listPtr2;
    void* _listPtr;
};

#endif
