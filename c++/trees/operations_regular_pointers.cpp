//
//  operations_regular_pointers.cpp
//  c++
//
//  Created by Thiago Ribeiro on 7/20/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>
#include <memory>
#include <queue>

using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode<T> *left, *right;
};

int data;
TreeNode<int> *p, *t;
queue<TreeNode<int>*> q;
TreeNode<int> *root;

// Create
void create_binary_tree() {
    int data;
    TreeNode<int> *p, *t;
    queue<TreeNode<int>*> q;
    
    cout << "Enter root node: ";
    cin >> data;
    root = new TreeNode<int>{data, nullptr, nullptr};
    q.emplace(root);
    
    while (!q.empty()) {
        p = q.front();
        q.pop();
        cout << "Enter left node: ";
        cin >> data;
        if (data != -1) {
            t = new TreeNode<int>{data, nullptr, nullptr};
            p->left = t;
            q.emplace(t);
        }
        cout << "Enter right node: ";
        cin >> data;
        if (data != -1) {
            t = new TreeNode<int>{data, nullptr, nullptr};
            p->right = t;
            q.emplace(t);
        }
    }
}

// Read (recursively)
void in_order(TreeNode<int> *tree) {
    if (tree == NULL) {
        return;
    }
    in_order(tree->left);
    cout << tree->data << endl;
    in_order(tree->right);
}

void pre_order(TreeNode<int> *tree) {
    if (tree == nullptr) {
        return;
    }
    cout << tree->data << endl;
    in_order(tree->left);
    in_order(tree->right);
}

int main () {
    //      1
    //    2   3
    
    create_binary_tree();
    pre_order(root);
    
    return 0;
}

