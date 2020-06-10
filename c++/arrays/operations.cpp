//
//  main.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/2/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// Display
void display(vector<int> &arr) {
    for (int &elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
}

// Append
void add(vector<int> &arr, int elem) {
    arr.push_back(elem);
}

// Add at index
void insert_at_index(vector<int> *v, unsigned int index, int elem) {
    vector<int> &arr = *v;
    long arr_length = arr.size();
    if (index > arr_length - 1) {
        return;
    }
    if (arr_length == 1) {
        arr[0] = elem;
    } else {
        arr.push_back(0);
        for (int i = (int)arr_length - 1; i > index; --i) {
            arr[i] = arr[i-1];
        }
        arr[index] = elem;
    }
}

// Delete at index
void delete_at_index(vector<int> *v, int index) {
    vector<int> &arr = *v;
    long arr_length = arr.size();
    if (index > arr_length - 1 || arr_length == 1) {
        return;
    }
    for (int i = index; i < arr.size() - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    arr.erase(arr.begin() + arr_length - 1);
}

// array has to be sorted
int binary_search(vector<int> &arr, int key) {
    int l = 0;
    int h = (int)arr.size() - 1;
    
    while (l <= h) {
        int mid = floor((l+h)/2);
        if (key == arr[mid]) {
            return mid;
        } else if (key < arr[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

// Reverse array in place
void reverse_in_place(vector<int> &arr) {
    int i = 0;
    int j = (int)arr.size() - 1;
    int temp;
    
    while (i < j) {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        i++;
        j--;
    }
}


// left shift - insert 0 at remaining
// or erase it
void left_shift(vector<int> *v) {
    vector<int> &arr = *v;
    int arr_size = (int)arr.size() - 1;
    int i;
    
    for (i = 0; i < arr_size; ++i) {
        arr[i] = arr[i + 1];
    }
//    arr[i] = 0;
//  or
    arr.erase(arr.begin() + arr_size);
}

void insert_in_sorted_array(vector<int> *v, int n) {
    vector<int> &arr = *v;
//    3, 6, 8
//    n = 5
//    3, 5, 6, 8
    
//    3, 6, 8, 0
//    3, 6, 8, 8
    arr.push_back(0);
    int i = (int)arr.size() - 2;
    
    while (arr[i] > n) {
        arr[i + 1] = arr[i];
        --i;
    }
    arr[i + 1] = n;
}

void left_rotate_by_one(vector<int> &arr) {
    int temp = arr[0];
    int i;
    
    for (i = 0; i < (int)arr.size() - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    arr[i] = temp;
}

void left_rotate_by_n(vector<int> &arr, int n) {
    for (int i = 0; i < n; ++i) {
        left_rotate_by_one(arr);
    }
}

void insert_sorted_array(vector<int> &arr, int n) {
    int i = (int)arr.size() - 1;
    arr.push_back(0);
    
    while (arr[i] > n) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i+1] = n;
}

// in a sorted list
bool is_sorted(vector<int> &arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void arrange_negative_left_positive_right(vector<int> &arr) {
    int i = 0;
    int j = (int)arr.size() - 1;
    
    while (i < j) {
        while (arr[i] < 0) ++i;
        while (arr[j] >= 0) --j;
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
}

// sorted arrays
vector<int> merge_sorted_arrays(vector<int> &a, vector<int> &b) {
    int i = 0, j = 0, m = (int)a.size(), n = (int)b.size();
    
    vector<int> out;
    
    while (i < m && j < n) {
        if (a[i] < b[i]) {
            out.push_back(a[i]);
            ++i;
        } else {
            out.push_back(b[j]);
            j++;
        }
    }
    
    while (i < m) {
        out.push_back(a[i]);
        i++;
    }
    
    while (j < n) {
        out.push_back(b[j]);
        j++;
    }
    
    return out;
}

// non sorted
void remove_duplicates(vector<int> &arr) {
    int lastDuplicate = 0;
    
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == arr[i + 1] && arr[i] != lastDuplicate) {
            arr.erase(arr.begin() + i);
            lastDuplicate = arr[i];
        }
    }
}

// find peak in array that goes up and down
int findPeak(vector<int> input) {
    int i = 0;
    int j = (int)input.size()-1;
    int mid = (i+j)/2;
    int peak = input[mid];
    
    while (input[mid + 1] > peak) {
        peak = input[mid + 1];
        mid++;
    }
    return peak;
}


int main(int argc, const char * argv[]) {
    vector<int> a = {1, 7};

    
//    insert_at_index(&a, 5, 11);
//    left_shift(&a);
//    insert_in_sorted_array(&a, 5);
//    display(a);
//    delete_at_index(v, 0);
//    cout << binary_search(v, 7) << endl;
//    reverse_in_place(v);
//    left_rotate_by_n(v, 2);
//    insert_sorted_array(v, 4);
    
//    cout << is_sorted(v);
//    arrange_negative_left_positive_right(v);
//    vector<int> o = merge_sorted_arrays(a, b);
//    remove_duplicates(a);
    
//    display(a);
    
    vector<int> input = {1, 2, 3, 5, 4, 3};
    vector<int> input2 = {1, 1, 888, 889, 890, 1};
    cout << findPeak(input2) << endl;
    
    return 0;
}

//
