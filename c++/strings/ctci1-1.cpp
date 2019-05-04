//
//  ctci1-1.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/3/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include<iostream>
#include<unordered_set>

using namespace std;

// T:O(n) / S: O(n) if all unique worst case
bool is_unique_1(string str) {
    unordered_set<char> set;
    
    for (char &c : str) {
        set.insert(c);
    }
    
    return str.size() == set.size();
}

// T: O(n log n) sorting / S: O(1)
bool is_unique_2(string str) {
    sort(str.begin(), str.end());
    
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == str[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string str = "thiago";
    
    cout << is_unique_2(str) << endl;
    
    return 0;
}

