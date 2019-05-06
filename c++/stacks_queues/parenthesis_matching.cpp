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

bool areParanthesisBalanced(string expr)
{
    stack<char> s;
    char x;
    
    for (int i = 0; i<expr.length(); ++i) {
        if (expr[i] == '(' || expr[i]=='[' || expr[i] == '{') {
            s.push(expr[i]);
            continue;
        }
        
        if (s.empty())
            return false;
        
        switch (expr[i]) {
            case ')':
                x = s.top();
                s.pop();
                if (x == '{' || x == '[')
                    return false;
                break;
                
            case '}':
                x = s.top();
                s.pop();
                if (x == '(' || x == '[')
                    return false;
                break;
                
            case ']':
                x = s.top();
                s.pop();
                if (x == '(' || x == '{')
                    return false;
                break;
        }
    }
    
    return s.empty();
}

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
    string str = "{()}[]";
    cout << areParanthesisBalanced(str) << endl;
    
    return 0;
}
