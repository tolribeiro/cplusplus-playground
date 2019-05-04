//
//  ctci1-3.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/4/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include<iostream>

using namespace std;

// T: O(n) / S: O(1)
void urlify(string &str, int len) {
    int countSpaces = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ') {
            ++countSpaces;
        }
    }
    int backIndex = len + countSpaces * 2;
    backIndex--;
    for (int i = len - 1; i >= 0; --i) {
        if (str[i] != ' ') {
            str[backIndex--] = str[i];
        } else {
            str[backIndex--] = '0';
            str[backIndex--] = '2';
            str[backIndex--] = '%';
        }
    }
}

int main() {
    string str = "Mr John Smith    ";
    
    urlify(str, 13);
    
    cout << str << endl;
    
    return 0;
}
