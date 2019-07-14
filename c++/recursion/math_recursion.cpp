//
//  math_recursion.cpp
//  c++
//
//  Created by Thiago Ribeiro on 7/14/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>

using namespace std;

// Sum of n natural numbers
// TIP: Any mathematical function definition
// can be easily converted to a recursive one

int sum(int n) {
    if (n == 0) return 0;
    else return sum(n - 1) + n;
}

int fact(int n) {
    if (n == 0) return 1;
    else return fact(n - 1) * n;
}

int power(int b, int e) {
    if (e == 0) return 1;
    else return power(b, e - 1) * b;
}

int fib(int n) {
    if (n == 0 || n == 1) return 1;
    else return fib(n - 2) + fib(n - 1);
}

int main () {
    cout << sum(5) << endl;
    cout << fact(4) << endl;
    cout << power(2, 3) << endl;
    cout << fib(7) << endl;
    
    return 0;
}
