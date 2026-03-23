// Uses the PIMPL idiom for a Widget class (Widget.h and Widget.cpp)
// The implementation (Impl) allocates some dynamic memory (e.g., a char* buffer or similar) and cleans it up in its destructor (RAII)
// In main(), creates and destroys a Widget, and verify (with print/log output) that Impl resources are properly managed by Widget’s destructor
#pragma once
#include<memory>
class Widget{
    public:
        Widget();
        ~Widget();

        void setName(const std::string &name);
        void printData() const;
    private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

#include "Widget.h"
#include <iostream>
#include <cstring>

// Full definition hidden in source
struct Widget::Impl {
    std::string name;
    char *buffer;
    Impl() : buffer(new char[100]) {
        std::cout << "[Impl] Allocated buffer at " << static_cast<void*>(buffer) << std::endl;
    }
    ~Impl() {
        std::cout << "[Impl] Deleting buffer at " << static_cast<void*>(buffer) << std::endl;
        delete[] buffer;
    }
};

Widget::Widget() : impl(std::make_unique<Impl>()) {}

Widget::~Widget() = default;

void Widget::setName(const std::string &name) {
    impl->name = name;
    std::strncpy(impl->buffer, name.c_str(), 99);
    impl->buffer[99] = '\0'; // Ensure null termination
}

void Widget::printData() const {
    std::cout << "Widget name: " << impl->name << ", buffer: " << impl->buffer << std::endl;
}


#include "Widget.h"
int main() {
    {
        Widget w;
        w.setName("PIMPL+RAII Example");
        w.printData();
    } // Widget and its Impl are destroyed here; resource cleanup printed
    return 0;
}
