// Defines a class Widget in a header, with a forward-declared private struct Impl and a std::unique_ptr<Impl> impl
// Only provides public methods (e.g., setName, printName) in the header
// Puts the full definition of struct Impl and method implementations in the .cpp file
#pragma once
#include <memory>
#include <string>

class Widget {
public:
    Widget();
    ~Widget();
    void setName(const std::string& name);
    void printName() const;

private:
    struct Impl;                       // Forward declaration
    std::unique_ptr<Impl> impl;        // PIMPL pointer
};


#include"header.h"
#include<memory>
#include<iostream>
#include "widget.h"
#include <iostream>

struct Widget::Impl {
    std::string name;
};

Widget::Widget() : impl(std::make_unique<Impl>()) {}

Widget::~Widget() = default;

void Widget::setName(const std::string& name) {
    impl->name = name;
}

void Widget::printName() const {
    std::cout << "Widget name: " << impl->name << std::endl;
}

#include "widget.h"

int main() {
    Widget w;
    w.setName("PIMPL Example");
    w.printName();
    return 0;
}

