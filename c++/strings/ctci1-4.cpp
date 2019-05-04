//
//  ctci1-4.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/4/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

// T: O(n) / S: O(n)
bool is_palindrome_perm(string str) {
    unordered_map<char, int> h;
    
    for (char &c : str) {
        if (c != ' ') {
            h[tolower(c)]++;
        }
    }
    
    int numberOfOdd = 0;
    for (int i = 0 ; i < str.length(); ++i) {
        if (h[str[i]] % 2 != 0) {
            numberOfOdd++;
        }
    }
    
    return numberOfOdd == 1 || !numberOfOdd;
}

int main() {
    string str = "elloello";
    cout << is_palindrome_perm(str) << endl;
    
    return 0;
}
