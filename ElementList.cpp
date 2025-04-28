#include "ElementList.h"
#include <iostream>
using std::cout;
using std::endl;


ElementList::ElementList()
{
    cout << "ElementList constructor"  << endl;
    _head = nullptr;
    _tail = nullptr;
    _currentNode = nullptr;
    int _count = 0;
    bool _empty = true;
}

ElementList::~ElementList()
{
    cout << "ElementList Destructor"  << endl;
    
    //TODO: Deallocate memory to avoid leak and bad exit;
    
}


ElementList::ElementList(const ElementList& other)
{
    _head = other._head;
    _tail = other._tail;
    _currentNode = other._currentNode;
    _count = other._count;
    _isEmpty = other._isEmpty;
}

void ElementList::setHead(Element* head)
{
    if(head != nullptr)
    {
        _head = head;
    }
    else
    {
        cout << "ERROR - invalid head"  << endl;
    }
}



/**
  @param element - new element to be added to the list
                   and must have a matching parent
*/
void ElementList::addElement(Element* element)
{
    cout << "adding new Element"  << endl;
    if(element != nullptr)
    {
        if(_head == nullptr)
        {
            cout << "Adding first node"  << endl;
            _head = element;
            _currentNode = element;
            _tail = element;
            _count++;
            _isEmpty = false;
        
        }
        else if(_currentNode->_parent == element->_parent)
        {
            cout << "Adding New node"  << endl;
            _currentNode->_next = element;
            element->_previous = _currentNode;
            _currentNode = _currentNode->_next;
            _tail = _currentNode;
            _count++;
        }
        else
        {
            cout << "Element Parent mismatch" << endl;
        }
    }
}


int ElementList::getCount()
{
    return _count;
}


bool ElementList::isEmpty()
{
    return _isEmpty;
}
