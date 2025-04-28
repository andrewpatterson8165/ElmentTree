#include "ElementList.h"
#include <iostream>
using std::cout;
using std::endl;


ElementList::ElementList()
{
    
    _head = nullptr;
    _current = nullptr;
    _tail  = nullptr;
    _nodeCount = 0;
}

ElementList::~ElementList()
{
   /* Element *trashNode = _head;
    Element *traverseNode = _head;
    
    while(traverseNode != nullptr)
    {
        
        trashNode = traverseNode;
        if(traverseNode->_next != nullptr)
        {
            cout << "Traversing in constructor"  << endl;
            traverseNode = traverseNode->_next;
            
        }
        if(trashNode != nullptr)
        {
            cout << "Trashing a node.."  << endl;
            delete trashNode;
        }
    }
    */
}

void ElementList::addElement(Element* elem)
{
   
    if(elem != nullptr)
    {
        cout << "element is valid" << endl;
        if((_head == nullptr) && 
           (_nodeCount == 0))
        {
            _head = elem;
            _current = elem;
            _tail = _head;
        }
        else
        {
            _current->_next = elem;
            _current->_next = nullptr;
        }
        _nodeCount++;
    }
    cout << "Node Count = " << _nodeCount << endl;
}

void ElementList::removeElement(unsigned short id)
{
          
}

void ElementList::removeElement(string name)
{
           
}


bool ElementList::find(unsigned short id)
{
    return false;
}
bool ElementList::find(unsigned int handle)
    
{
    return false;
}

bool ElementList::find(string name)
{
    return false;
}



