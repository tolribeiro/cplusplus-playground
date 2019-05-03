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
    long arr_length = arr.size();
    if (index > arr_length - 1) {
        return;
    } else if (arr_length == 1) {
        arr[0] = elem;
    } else {
        arr.push_back(0);
        for (int i = (int)arr.size() - 1; i > index; --i) {
            arr[i] = arr[i-1];
        }
        arr[index] = elem;
    }
}

int main(int argc, const char * argv[]) {
    vector<int> v = {7, 8, 9, 2, 3, 5};
    
    insert_at_index(v, 5, 11);

    display(v);
    
    return 0;
}
