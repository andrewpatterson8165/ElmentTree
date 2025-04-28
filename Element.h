#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <string>
using std::string;


class Element
{
public:
    Element(string name,unsigned short id,Element* parent);
    ~Element();
    
    Element(const Element& other);
    
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
