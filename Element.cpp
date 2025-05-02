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
    _listPtr = nullptr;
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
    _listPtr = other._listPtr;
   
}
/**
  Warning: if this flag is set to true and child nodes exist. 
           the flag cannot be set back to false. 
*/
void Element::setChildrenFlag(bool state)
{
    if(this->_childListHead == nullptr)
    {
        _hasChildren = state;
    }
    else
    {
        cerr << "Cannot modify child state flag - children exist" << endl;
    }
}

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



Element* Element::getPreviousNode()const
{
    return _previous;
}

Element* Element::getNextNode()const
{
    return _next;
}

void Element::setNextNode(Element* element)
{
    _next = element;
}


void Element::setPreviousNode(Element* element)
{
    _previous = element;
}

void Element::setListPtr(void* listPtr)
{
  _listPtr = listPtr;
}

void* Element::getListPtr()
{
  return _listPtr;
}


Element* Element::getParentElement()const
{
    return _parent;
}


void Element::setChildListHead(Element* element)
{
    if(_childListHead == nullptr)
    {
        cout << "Child List head is set" << endl;
        _childListHead = element;
    }
    else
    {
        cerr << "Cannot re-initialize a head to a list" << endl;
    }
}
