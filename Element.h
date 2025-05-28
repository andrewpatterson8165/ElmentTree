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

    bool hasChildren(){return _hasChildren;};

    int childCount()const{return _childList.size();};
protected:
    Element(){}; //to support child copy constructors. 
    list<Element*> _childList;
    bool _hasChildren;
    
    HANDLE _handle;
    UINT16 _resourceId;
    string _name;
    Element* _parent;
};

/**********************************************************************************************
* windows_cast - for avoiding annoying warnings during compilation (64-bit compatibility)
**********************************************************************************************/
template< class Out, class In >
inline Out windows_cast( In x )
{
    union //convert one type to another
    {
        In x;
        Out y;
    }convert;

    convert.y = 0;
    convert.x = x;
    return convert.y;
}

#endif


#endif
