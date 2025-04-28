#include "Element.h"




#include "Element.h"


Element::Element(string name,
                 unsigned short id,
                 Element* parent)
{
        _name = name;
        _id = id;
        _parent = parent;
        _hasChildren = false;
        _childCount = 0;
        _next = nullptr;
        _previous = nullptr;
        _childHead = nullptr;
}

Element::~Element()
{
    
}

Element::Element(const Element& other)
{
   
    _name = other._name;
    _id = other._id;
    _parent = other._parent;
    _hasChildren = other._hasChildren;
    _parent = other._parent;
    _next = other._next;
    _childHead = other._childHead;
    _previous = other._previous;
   
}



