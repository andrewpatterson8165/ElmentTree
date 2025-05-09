
#include "Element.h"
#include <iostream>
using std::cerr;
using std::endl;


Element::Element(string name,UINT16 id,Element* parent)
{
    _name = name;
    _resourceId = id;
    _parent = parent;
    _childList.clear();
    if(_parent != nullptr)
    {
        _parent->getChildList().push_back(this);
    }
}


Element::~Element()
{
    _childList.clear();
}

Element::Element(const Element& other)
{
    _name = other._name;
    _handle = other._handle;
    _resourceId = other._resourceId;
    _childList.clear();
    for(auto it : other._childList)
    {
        _childList.push_back(it);
    }
}
    
void Element::setName(string name)
{
    _name = name;
}

string Element::getName()const
{
    return _name;
}
    
UINT16 Element::getResourceId()const
{
    return _resourceId;
}

void Element::setResourceId(UINT16 resourceId)
{
    _resourceId = resourceId;
}
    
HANDLE Element::getHandle()const
{
    return _handle;
}

void Element::setHandle(HANDLE handle)
{
    _handle = handle;
}
    
list<Element*> Element::getChildList()const
{
    return _childList;
}

void Element::addChild(Element* node)
{
    _childList.push_back(node);
}
    
void Element::setParent(Element* parent)
{
    _parent = parent;
}

Element* Element::getParent()const
{
    return _parent;
}



Element* Element::findChildElement(string name)const
{
    Element* ref = nullptr;
    for(auto it : _childList)
    {
        if(it->getName() == name)
        {
            ref = it;
        }
    }
    if(ref == nullptr)
    {
        cerr << "Element Not found "  << endl;
    }
    return ref;
}



Element* Element::findChildElement(UINT16 id)const
{
    Element* ref = nullptr;
    for(auto it : _childList)
    {
        if(it->getResourceId() == id)
        {
            ref = it;
        }
    }
    if(ref == nullptr)
    {
        cerr << "Element Not found "  << endl;
    }
    return ref;
}
