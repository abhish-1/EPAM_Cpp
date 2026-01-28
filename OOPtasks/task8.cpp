//Defines a Box class with member variables: length, width, height Implements
//a member function setDimensions() that uses this-> to assign the private
//members from parameters Implements a function compareVolume(const Box& b)
//that compares the calling object's volume to another Box b, and returns
//*this if its volume is equal or larger; otherwise, returns b Demonstrates
//usage by creating and comparing Box objects
#include<iostream>
using namespace std;
class Box{
    int length;
    int width;
    int height;
public:
    void setDimensions(int length, int width, int height) {
        this->height = height;
        this->width = width;
        this->length = length;
    }
    Box compareVolume(const Box& b) {
        long volume = length*width*height;
        long volume1 =b.length*b.height*b.width;
        if (volume==volume1) return *this;
        return b;
    }
    int getLength() {
        return length;
    }
};
int main() {
    Box b1;
    b1.setDimensions(5,3,2);
    Box b2;
    b2.setDimensions(4,3,2);
    cout<<(b2.compareVolume(b1)).getLength();
}