#include "Element.h"
///TODO - Investigate to see if this should be migrated to a differnt class
void Element::addChild(Element* child)
{
    if(child != nullptr)
    {
        if(_childCount == 0)
        {
            _childHead = child;
            _currentChild = _childHead;
            _childCount++;
        }
        else //If children actually exist
        {
            _currentChild->_next = child;
            _currentChild = _currentChild->_next;
            _childCount++;
        }
    }
    //Element* _parent;
    //Element* _next;
    //Element* _previous;
    //Element* _childHead;
    //Element* _currentChild;
}


