#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <string>
using std::string;

class Element
{
public:
    Element(string name,unsigned short id,Element* parent){
        _name = name;
        _id = id;
        _parent = parent;
        _hasChildren = false;
        _childCount = 0;
        _next = nullptr;
        _previous = nullptr;
        _childHead = nullptr;
        
    };
    ~Element(){};
    
    Element(const Element& other){
        _name = other._name;
        _id = other._id;
        _parent = other._parent;
        _hasChildren = other._hasChildren;
        _parent = other._parent;
        _next = other._next;
        _childHead = other._childHead;
        _previous = other._previous;
    };
    
    bool hasChildren(){return _hasChildren;}
    int _childCount;
    string _name;
    unsigned short _id;
    unsigned int _handle;
    bool _hasChildren;    
    
    Element* _parent;
    Element* _next;
    Element* _previous;
    Element* _childHead;

};

#endif
