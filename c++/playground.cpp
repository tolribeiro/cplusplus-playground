//
//  playground.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/17/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

void print_arr(int A[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
}

int* fun(int n) {
    int *p;
    p = (int *)malloc(n * sizeof(int));
    return p;
}

int main () {
    struct Rectangle r[1] = {{15, 10}};
    
    cout << r[0].length << endl;
    int A[5] = {7, 4, 2 ,5, 3};
    print_arr(A, 5);
    int *B;
    B = fun(5);
    B[0] = 1;
    cout << "\n" << B[0] << endl;
}
