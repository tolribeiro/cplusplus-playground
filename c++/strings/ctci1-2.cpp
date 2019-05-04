//
//  ctci1-2.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/3/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include<iostream>
#include<unordered_set>

using namespace std;

// T:O(n log) / S: O(1)
bool is_perm_1(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    return s1 == s2;
}

// T:O(n) / S: O(n)
bool is_perm_2(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    
    unordered_set<char> h;
    
    for (char &c : s1) {
        h.insert(c);
    }
    
    for (char &c : s2) {
        if (h.find(c) == h.end()) {
            return false;
        }
    }
    return true;
}
int main() {
    string s1 = "abbccc";
    string s2 = "abcbcc";
    
    cout << is_perm_2(s1, s2) << endl;
    
    return 0;
}

