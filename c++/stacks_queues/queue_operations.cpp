//
//  queue_operations.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/5/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

void showq(queue <int> gq)
{
    queue <int> g = gq;
    
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << endl;
}

int main()
{
    queue <int> gquiz;
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);
    
    cout << "The queue gquiz is : ";
    showq(gquiz);
    
    cout << endl << "gquiz.size() : " << gquiz.size();
    cout << endl << "gquiz.front() : " << gquiz.front();
    cout << endl << "gquiz.back() : " << gquiz.back();
    
    cout << endl << "gquiz.pop() : ";
    gquiz.pop();
    showq(gquiz);
    
    return 0;
}
