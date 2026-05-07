#include"sample.h"

void Sample::method(){
    std::cout << Sample::impl->x << std::endl
}

struct Sample::Pimpl {
    int x = 10;
}