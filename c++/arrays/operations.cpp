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
#include <map>
#include <unordered_set>

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

void even(int L) {
    int init = 2;
    
    while (L > init) {
        cout << init << " ";
        init += 2;
    }
}

void odd(int L) {
    int init = 1;
    
    while (L > init) {
        cout << init << " ";
        init += 2;
    }
}

void decToBin(int baseTen) {
    vector<string> out;
    int res = baseTen;
    int rem;
    
    if (!baseTen) cout << "0";
    
    while (res != 0) {
        rem = res % 2;
        res = res / 2;
        out.push_back(to_string(rem));
    }
    
    for (short i = out.size() - 1; i >= 0; --i) {
        cout << out[i] << " ";
    }
}

void tabuada() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cout << i << "x" << j << "=" << i * j;
            cout << "\t";
            cout << i << "/" << j << "=" << i / j;
            cout << "\t";
            cout << i << "+" << j << "=" << i + j;
            cout << "\t";
            cout << i << "-" << j << "=" << i - j;
            cout << "\n";
        }
        cout << "\n";
    }
}

void printStars(int n) {
    for (int i = 0; i < n; ++i) {
        cout << "*";
    }
    cout << "\n";
}

void columnGraph(int a, int b, int c, int in) {
    int higher = a;
    
    if (b > a && b > c) {
        higher = b;
    } else if (c > a && c > b) {
        higher = c;
    }
    int divider = higher / in;
    printStars(a / divider);
    printStars(b / divider);
    printStars(in);
}

bool isDigitLog(string s) {
    string str = s.substr(s.find(" ") + 1);

    for (char &c : str) {
        if (c != ' ' && !(c - '0' >= 0 && c - '0' <= 9)) {
            return false;
        }
    }

    return true;
}

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<int>indexArr;
    vector<string> letterArr;
    map<string, string> h;

    for (int i = 0; i < logs.size(); ++i) {
        if (isDigitLog(logs[i])) {
            indexArr.push_back(i);
        } else {
            string logWithNoId = logs[i].substr(logs[i].find(" ") + 1);
            string logId = logs[i].substr(0, logs[i].find(" "));
            
            h[logWithNoId + logId] = logs[i];
        }
    }

    for (auto hItem : h) {
        letterArr.push_back(hItem.second);
    }

    for (int i = 0; i < indexArr.size(); ++i) {
        letterArr.push_back(logs[indexArr[i]]);
    }

    return letterArr;
}

// Leetcode 121
int maxProfit(vector<int>& prices) {
    long prices_size = prices.size() - 1;
    int max_prof = 0;
    int greatest = prices[prices_size];
    
    if (prices_size < 1 || prices_size == 0) return 0;
    
    for (long i = prices_size - 1; i >= 0; --i) {
        if (prices[i] > greatest) {
            greatest = prices[i];
        } else if (prices[i] < greatest) {
            if (greatest - prices[i] > max_prof) {
                max_prof = greatest - prices[i];
            }
        }
    }
    return max_prof;
}

//Leetcode 415
string addStrings(string num1, string num2) {
    int carry = 0;
    long i = num1.size() - 1;
    long j = num2.size() - 1;
    string out;

    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += num2[j] - '0';
            --j;
        }
        carry = sum / 10;
        sum = sum % 10;
        out += (sum + '0');
    }

    // in case both are single digits
    if (carry != 0) {
        out += (carry + '0');
    }
    
    reverse(out.begin(), out.end());
    return out;
}

bool isHappy(int n) {
    unordered_set<int> seen;
    
    // 19
    while (n != 1) {
        int curr = n; // 19
        int sum = 0;
        while (curr != 0) {
            sum += (curr % 10) * (curr % 10);
            curr /= 10;
        }
        if (seen.find(sum) != seen.end()) return false;
        seen.insert(sum);
        n = sum;
    }
    return true;
}

// Leetcode 509
int fib(int N) {
    int sum = 0;
    if (N == 0) return 0;
    else if (N == 1) return 1;
    else {
        int x = 0;
        int y = 1;
        for (int i = 0; i < N - 1; ++i) {
            sum = x + y;
            x = y;
            y = sum;
        }
    }
    return sum;
}

// Leetcode 217
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    
    if (nums.size() == 0 || nums.size() == 1) return false;
    
    for (int &i : nums) {
        set.insert(i);
    }
    return set.size() == nums.size() ? false : true;
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
    
//    vector<int> input = {1, 2, 3, 5, 4, 3};
//    vector<int> input2 = {1, 1, 888, 889, 890, 1};
//    cout << findPeak(input2) << endl;
    
//    even(15);
//    cout << endl;
//    odd(15);
//    cout << endl;
    
//    decToBin(125);
//    cout << endl;
//    decToBin(1);
//    cout << endl;
//    decToBin(0);
//    cout << endl;
//    decToBin(10);
//    cout << endl;
//    decToBin(8);
//    cout << endl;
//    decToBin(4);
//    cout << endl;
//    decToBin(2);
//    cout << endl;
//    decToBin(18);
//    cout << endl;
//    decToBin(7);
//    cout << endl;
//    decToBin(13);
//    cout << endl;
//    decToBin(9);
//    cout << endl;
//    tabuada();
//    columnGraph(2, 8, 20, 10);
//    cout << "\n";
    
//    vector<string> in = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo","a2 act car"};
//
//    reorderLogFiles(in);
    
//    addStrings("1", "9");
    
    return 0;
}

//
