//
//  stack-operations.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/5/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include<iostream>
#include <stack>

using namespace std;

void showstack(stack<int> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << endl;
}

int main () {
    stack <int> s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(5);
    s.push(1);
    
    cout << "The stack is : ";
    showstack(s);
    
    cout << endl << "s.size() : " << s.size();
    cout << endl << "s.top() : " << s.top();
    
    
    cout << endl << "s.pop() : ";
    s.pop();
    showstack(s); 
}
