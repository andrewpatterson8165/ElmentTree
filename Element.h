#include <string>
using std::string;

class ElementList;

class Element
{
public:
    Element(string name,unsigned short id,Element* parent){
        _name = name;
        _id = id;
        _parent = parent;
    };
    ~Element(){};
    Element(const Element& other){};
    
    string _name;
    unsigned short _id;
    unsigned int _handle;
    
    
    Element* _parent;
    
    Element* _next;
    
    Element* _previous;
    
    Element* _childHead;
    
    
    
};
