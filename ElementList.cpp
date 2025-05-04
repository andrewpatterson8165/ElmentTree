#include "ElementList.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;


ElementList::ElementList(Element* parentElement)
{
    _head = nullptr;
    _tail = nullptr;
    _currentNode = nullptr;
    int _count = 0;
    bool _isEmpty = true;
    _parentElement = parentElement;
    
}

ElementList::~ElementList()
{
    //TODO: Deallocate memory to avoid leak and bad exit;
}


ElementList::ElementList(const ElementList& other)
{
    _head = other._head;
    _tail = other._tail;
    _currentNode = other._currentNode;
    _count = other._count;
    _isEmpty = other._isEmpty;
    _parentElement = other._parentElement;
}

void ElementList::setHead(Element* head)
{
    if(_isEmpty == false)
    {
        cout << "Set Head Error -List not empty" << endl;
        return;
    }
    if(head != nullptr)
    {
        _head = head;
       
    }
    else
    {
        cout << "ERROR - invalid head"  << endl;
    }
    return;
}



/**
  @param element - new element to be added to the list
                   and must have a matching parent
*/
void ElementList::addElement(Element* element)
{
    
    if(element != nullptr)
    {
        if(_head == nullptr)
        {
            cout <<"Adding a new Head" << endl;
            _head = element;
            _currentNode = element;
            _tail = element;
            _count++;
            _isEmpty = false;
        }
        else if(_currentNode->getParentElement() == element->getParentElement())
        {
            cout << "Adding another node to list" << endl;
            _currentNode->setNextNode(element);
            element->setPreviousNode(_currentNode);
            _currentNode = _currentNode->getNextNode();
            _tail = _currentNode;
            _count++;
        }
        else
        {
            cerr << "Element Parent mismatch" << endl;
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


Element* ElementList::findReference(string name)
{
   Element* searchNode = nullptr;
   
   searchNode = _head;
   for(searchNode = _head;searchNode != _tail;searchNode = searchNode->getNextNode())
   {
       if(name == searchNode->_name)
       {
           return searchNode;
       }
    }
    searchNode = nullptr;
    return searchNode;
}

Element* ElementList::findReference(UINT16 resourceId)
{
    Element* searchNode = nullptr;
   
    searchNode = _head;
    for(searchNode = _head;searchNode != _tail;searchNode = searchNode->getNextNode())
    {
        if(resourceId == searchNode->_resourceId)
        {
           return searchNode;
        }
    }
    searchNode = nullptr;
    return searchNode;
}

Element* ElementList::findReference(HANDLE handle)
{
     Element* searchNode = nullptr;
   
    searchNode = _head;
    for(searchNode = _head;searchNode != _tail;searchNode = searchNode->getNextNode())
    {
        if(handle == searchNode->getHandle())
        {
           return searchNode;
        }
    }
    searchNode = nullptr;
    return searchNode;
}



Element* ElementList::operator++()
{
    _currentNode = _currentNode->getNextNode();
    return _currentNode;
    
}

Element* ElementList::operator--()
{
    _currentNode = _currentNode->getPreviousNode();
    return _currentNode;
}

Element* ElementList::getHead()const
{
    return _head;
}
