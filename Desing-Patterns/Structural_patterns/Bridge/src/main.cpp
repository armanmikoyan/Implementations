#include <iostream>

#include "abstraction.hpp"

int main() {
    Color* red = new Red;
     Color* green = new Green;

    Shape* circle_red = new Circle(red);
    Shape* square_red = new Square(red);

    Shape* circle_green = new Circle(green);
    Shape* square_green = new Square(green);
    
    circle_red->operation();
    square_red->operation();
    circle_green->operation();
    square_green->operation();
}