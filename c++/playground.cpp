//
//  playground.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/17/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include "operations.h"
using namespace std;

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void google_swap(int *x, int *y) {
    int tmp;
    int &a = *x;
    int &b = *y;
    tmp = a;
    a = b;
    b = tmp;
    
}

int balancedStringSplit(string s) {
    stack <char> st;
    int count = 0;
    
    for (char &c : s) {
        if (st.empty()) {
            st.push(c);
            continue;
        }
        char curr = st.top();
        if ((curr == 'R' && c == 'L')
        || (curr == 'L' && c == 'R')) {
            st.pop();
            if (st.empty()) {
                count++;
            }
            continue;
        }
        st.push(c);
        continue;
    }
    return count;
}

int main () {
//    int a = 10;
//    int b = 20;
////    swap(a, b);
//    google_swap(&a, &b);
//
//    cout << a << b << endl;
    cout << balancedStringSplit("RLRRLLRLRL") << endl;
    
}
