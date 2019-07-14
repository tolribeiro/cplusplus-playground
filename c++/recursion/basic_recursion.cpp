//
//  basic_at_calling_time.cpp
//  c++
//
//  Created by Thiago Ribeiro on 7/14/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>

using namespace std;

// print at calling time
// ascending
void tail(int n) {
    if (n > 0) {
        cout << n << " ";
        tail(n-1);
    }
}

// print at returning time
// descending
void head(int n) {
    if (n > 0) {
        head(n-1);
        cout << n << " ";
    }
}

// recursions two phases (more powerful than loop
// that only has ascending phase
void head_tail(int n) {
    if (n > 0) {
        cout << n << " ";
        head_tail(n - 1);
        cout << n << " ";
    }
}

int main () {
//    func1(3);
//    cout << endl;
//    func2(3);
    head_tail(3);
    return 0;
}


