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
        _hasChildren = false;
        _childCount = 0;
    };
    ~Element(){};
    Element(const Element& other){};
    bool hasChildren(){return _hasChildren;}
    void addChild(Element* child);
    int _childCount;
    string _name;
    unsigned short _id;
    unsigned int _handle;
    bool _hasChildren;    
    
    Element* _parent;
    Element* _next;
    Element* _previous;
    Element* _childHead;
    Element* _currentChild;
    


    
    
    
};
