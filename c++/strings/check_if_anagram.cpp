//
//  check_if_anagram.cpp
//  c++
//
//  Created by Thiago Ribeiro on 7/17/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

// check if strings are anagrams
// using hash tables
bool is_anagram(string s1, string s2) {
    unordered_map<char, int> h;
    
    for (char &c : s1) {
        h[c]++;
    }
    
    for (char &c : s2) {
        h[c]--;
        if (h[c] < 0) {
            return false;
        }
    }
    return true;
}

int main () {
    string s1 = "decimal";
    string s2 = "medical";
    string out;
    
    out = is_anagram(s1, s2) ? "YES" : "NO";
    
    cout << out << endl;
    
    return 0;
}
