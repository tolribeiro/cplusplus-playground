//
//  ctci1-5.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/4/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

// T: O(n) / S: O(1)
bool one_away(string s1, string s2) {
    int m = (int)s1.length(), n = (int)s2.length();
    
    if (abs(m - n) > 1)
        return false;
    
    int count = 0;
    int i = 0, j = 0;
    
    while (i < m && j < n) {
        if (s1[i] != s2[j]) {
            // first difference found
            if (count == 1)
                return false;
            
            if (m > n) {
                i++;
            } else if (m < n) {
                j++;
            } else {
                i++;
                j++;
            }
            count++;
        } else {
            i++;
            j++;
        }
    }
    
    if (i < m || j < n) {
        count++;
    }
    
    return count == 1;
}

int main () {
    string s1 = "pale";
    string s2 = "bake";
    cout << one_away(s1, s2) << endl;
    
    return 0;
}
