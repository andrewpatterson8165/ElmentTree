#include "Element.h"
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

Element::Element(string name,
                 UINT16 resourceId,
                 Element* parent)
{
    _name = name;
    _resourceId = resourceId;
    _parent = parent;
    _hasChildren = false;
    _childCount = 0;
    _next = nullptr;
    _previous = nullptr;
    _childListHead = nullptr;
    _handle = 0;
}

Element::~Element()
{
    
}

Element::Element(const Element& other)
{
   
    _name = other._name;
    _resourceId = other._resourceId;
    _parent = other._parent;
    _hasChildren = other._hasChildren;
    _parent = other._parent;
    _next = other._next;
    _childListHead = other._childListHead;
    _previous = other._previous;
    _handle =  other._handle;
   
}


void Element::setChildrenFlag(bool state)
{
    _hasChildren = state;
}


/**
    Warning: once the childList is set on a node, it cannot be destroyed. 
*/
void Element::setChildrenFirstElement(Element* element)
{
    if(_childListHead != nullptr)
    {
        cout << "Error - child head already set for this element" << endl;
        
    }
    
    if((element != nullptr) && (_hasChildren)){
        _childListHead = element;
        _childListHead->_previous = this;
    }
}


Element* Element::getChildrenFirstElement()const
{
    return _childListHead;
}


Element* Element::getParentElement()const
{
    return _parent;
}

/**
    Warning: once the parent is set on an element, 
             it cannot be modified. 
*/
void Element::setParentElement(Element* element)
{
    if(this->_parent != nullptr)
    {
        _parent = element;
    }
}


string Element::getName()const
{
    return _name;
}

UINT16 Element::getResourceId()const
{
    return _resourceId;
}

HANDLE Element::getHandle()const
{
    return _handle;
}


bool Element::hasChildren()const
{
    return _hasChildren;
}


void Element::setHandle(HANDLE handle)
{
    _handle = handle;
}
