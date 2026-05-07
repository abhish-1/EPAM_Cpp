#include<iostream>
struct Sample{
public:
    void method();
private:
    struct Pimpl;
    Pimpl* impl;
};