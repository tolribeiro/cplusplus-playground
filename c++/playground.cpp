//
//  playground.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/17/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>

using namespace std;

//struct Rectangle {
//    int length;
//    int breadth;
//};
//
//void print_arr(int A[], int n) {
//    for (int i = 0; i < n; ++i) {
//        cout << A[i] << " ";
//    }
//}
//
//int* fun(int n) {
//    int *p;
//    p = (int *)malloc(n * sizeof(int));
//    return p;
//}
//
//void func1(int &num) {
//    num = 8;
//}
//
//void func2(int *num_ptr) {
//    int &num = *num_ptr;
//    num = 8;
//}

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
//    struct Rectangle r[1] = {{15, 10}};
    
//    cout << r[0].length << endl;
//    int A[5] = {7, 4, 2 ,5, 3};
//    print_arr(A, 5);
//    int *B;
//    B = fun(5);
//    B[0] = 1;
//    cout << "\n" << B[0] << endl;
    
//    int num = 5;
//
//    cout << "before: " << num << endl;
//    func2(&num);
//    cout << "after: " << num << endl;
    Rectangle<int> r(12, 20);
    cout << r.getLength() << endl;
}
