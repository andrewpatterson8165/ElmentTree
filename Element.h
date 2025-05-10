#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <list>
#include <string>
using std::string;
using std::list;
#include "WinDef.h"

class Element
{
public:
    Element(string name,UINT16 id,Element* parent);
    ~Element();
    Element(const Element& other);
    
    void setName(string name);
    string getName()const;
    
    UINT16 getResourceId()const;
    void setResourceId(UINT16 resourceId);
    
    HANDLE getHandle()const;
    void setHandle(HANDLE handle);
    
    list<Element*> getChildList()const;
    void addChild(Element* node);
    
    void setParent(Element* parent);
    Element* getParent()const;
    
    Element* findChildElement(string name)const;
    Element* findChildElement(UINT16 id)const;

    bool hasChildren(){ return _childList.empty();};

    int childCount()const{return _childList.size();};
protected:
    list<Element*> _childList;
    bool _hasChildren;
    
    HANDLE _handle;
    UINT16 _resourceId;
    string _name;
    Element* _parent;
};

#endif
