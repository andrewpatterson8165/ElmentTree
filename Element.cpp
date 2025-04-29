
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



void Element::setHasChildren(bool state)
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




