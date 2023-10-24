#include <iostream>

class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing Shape" << std::endl;
    }
};

class Circle : public Shape {
public:
    int a = 1;
    int b = 1;
    void draw() const override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

class Square : public Shape {
public:
    char cc;
    int a = 1;
    int b = 1;
    int c = 1;
    void draw() const override {
        std::cout << "Drawing Square" << std::endl;
    }
};

void drawShape(const Shape& shape) {
    shape.draw();
}
void showSize(const Shape& shape) {
        std::cout << "size = " << sizeof(shape) << std::endl;
}
class MyClass {
public:
    
    void static PublicFunction() {
        // ...
    }
protected:
    int y;
    void static ProtectedFunction() {
        // ...
    }
};

class Derived : public MyClass {
public:
    void Function() {
        y = 10; // 合法
        ProtectedFunction(); // 合法
    }
};
int main() {
    MyClass::PublicFunction();
    Shape shape;
    Circle circle;
    Square square;
    // int *(*v)[];
    // drawShape(shape);  // Output: Drawing Shape
    // drawShape(circle); // Output: Drawing Circle
    // drawShape(square); // Output: Drawing Square
    // showSize(shape );  
    // showSize(circle); 
    // showSize(square); 
    std::cout << "shape  size = " << sizeof(shape ) << std::endl;
    std::cout << "circle size = " << sizeof(circle) << std::endl;
    std::cout << "square size = " << sizeof(square) << std::endl;
    std::cout << "(Shape)square size = " << sizeof((Shape)square) << std::endl;
    return 0;
}
