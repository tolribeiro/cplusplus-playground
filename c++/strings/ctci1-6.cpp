//
//  ctci1-6.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/4/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>

using namespace std;

string compressed_string(string str) {
    if (str.length() == 1) {
        return str;
    }
    
    int count = 1;
    char lastChar = str[0];
    string out = "";
    
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == lastChar) {
            count++;
        } else {
            out += lastChar + to_string(count);
            lastChar = str[i];
            count = 1;
        }
    }
    out += lastChar + to_string(count);
    return out;

}

int main () {
    string str = "wwwwaaadexxxxxx";
    
    cout << compressed_string(str) << endl;
    
    return 0;
}
