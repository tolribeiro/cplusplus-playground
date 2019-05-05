//
//  parenthesis_matching.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/5/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

bool is_matching_par(string str) {
    stack<char> st;
    
    for (char &c : str) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty() ? true : false;
}

int main () {
    string str = "((a+b)*a)";
    cout << is_matching_par(str) << endl;
    
    return 0;
}
