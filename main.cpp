#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
using namespace std;

class Shape {
public:
                  
    virtual double getArea() = 0;           
    virtual double getPerimeter() = 0;      
    virtual string getName() = 0;           
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() override { 
        return M_PI * radius * radius; 
    }
    double getPerimeter() override { 
        return 2 * M_PI * radius; 
    }
    string getName() override { 
        return "Circle"; 
    }
};

class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() override { 
        return width * height; 
    }
    double getPerimeter() override { 
        return 2 * (width + height); 
    }
    string getName() override { 
        return "Rectangle"; 
    }
};

class RightTriangle : public Shape {
protected:
    double base, height;
public:
    RightTriangle(double b, double h) : base(b), height(h) {}
    double getArea() override { 
        return 0.5 * base * height; 
    }
    double getPerimeter() override {
        double hyp = sqrt(base * base + height * height);
        return base + height + hyp;
    }
    string getName() override { 
        return "RightTriangle"; 
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
    string getName() override { 
        return "Square"; 
    }
};

class IsoscelesRightTriangle : public RightTriangle {
public:
    IsoscelesRightTriangle(double leg) : RightTriangle(leg, leg) {}
    string getName() override { 
        return "IsoscelesRightTriangle"; 
    }
};

void printAreaToScreen(Shape *s) {
    cout << s->getName() << " Area = " << s->getArea() << "\n";
}

int main() {
    Circle circ(7);
    Rectangle rect(5, 8);
    Square sq(7);
    RightTriangle righttri(6, 8);
    IsoscelesRightTriangle isos(3);

    assert((int)circ.getArea() == 153);        
    assert((int)circ.getPerimeter() == 43);   

    assert(rect.getArea() == 40);
    assert(rect.getPerimeter() == 26);

    assert(sq.getArea() == 49);
    assert(sq.getPerimeter() == 28);

    assert(righttri.getArea() == 24);             
    assert((int)righttri.getPerimeter() == 24);  

    assert((int)isos.getArea() == 4);      
    assert((int)isos.getPerimeter() == 10); 

    printAreaToScreen(&circ);
    printAreaToScreen(&rect);
    printAreaToScreen(&sq);
    printAreaToScreen(&righttri);
    printAreaToScreen(&isos);

    cout << "Program passed all tests\n";
    return 0;
}
