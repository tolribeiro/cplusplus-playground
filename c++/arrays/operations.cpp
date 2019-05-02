//
//  main.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/2/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &arr) {
    for (int &elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
}

void add(vector<int> &arr, int elem) {
    arr.push_back(elem);
}

void insert_at_index(vector<int> &arr, unsigned int index, int elem) {
    if (index > arr.size() - 1) {
        return;
    } else if (arr.size() == 1) {
        arr[0] = elem;
    } else {
        arr.push_back(arr[arr.size()-1]);
        arr[arr.size() - 2] = arr[arr.size() - 3];
        arr[index] = elem;
    }
}

int main(int argc, const char * argv[]) {
    vector<int> v = {1, 2, 9};
    insert_at_index(v, 1, 3);
    display(v);
    
    return 0;
}
