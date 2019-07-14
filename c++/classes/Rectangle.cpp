//
//  Rectangle.cpp
//  c++
//
//  Created by Thiago Ribeiro on 7/14/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//
#include <iostream>

using namespace std;

template <typename T>
class Rectangle {
private:
    T length;
    T breadth;
public:
    Rectangle();
    Rectangle(T length, T breadth);
    T getLength();
    T area();
    ~Rectangle();
};

template <typename T>
Rectangle<T>::Rectangle() {
    length = breadth = 1;
}

template <typename T>
Rectangle<T>::Rectangle(T length, T breadth) {
    this->length = length;
    this->breadth = breadth;
}

template <typename T>
T Rectangle<T>::area() {
    return length * breadth;
}

template <typename T>
Rectangle<T>::~Rectangle() {}

template <typename T>
T Rectangle<T>::getLength() {
    return length;
}

int main () {
    Rectangle<float> r(12.5, 20.2);
    cout << r.area() << endl;
}
