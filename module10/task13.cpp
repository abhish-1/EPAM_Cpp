// rect_segfault.cpp
#include <iostream>
class Rectangle {
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int area() const { return width * height; }
};

int main() {
    Rectangle* rect = new Rectangle(3, 4);
    delete rect;
    std::cout << "Area: " << rect->area() << std::endl; // Use after free – crash!
    return 0;
}
