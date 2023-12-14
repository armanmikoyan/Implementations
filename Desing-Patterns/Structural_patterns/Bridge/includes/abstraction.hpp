#include "implementation.hpp"

class Shape {
public:
    Shape(Color* color) 
    {
        _color = color;
    }

    virtual void operation() const = 0;
    
protected:
    Color* _color;
};



class Circle : public Shape {
public:
    Circle(Color* color) 
        : Shape(color)
    {
    }
    void operation() const override 
    {
        std::cout << "Circle-> ";
        _color->coloring();
    }
};


class Square : public Shape {
public:
    Square(Color* color) 
        : Shape(color)
    {
    }
    void operation() const override 
    {
        std::cout << "Square-> ";
        _color->coloring();
    }
};