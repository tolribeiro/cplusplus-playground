//
//  operations.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/6/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>
#include <queue>
#include "binary_tree_prototype.h"

void in_order(unique_ptr<TreeNode<int>> &tree) {
    if (tree == nullptr) {
        return;
    }
    in_order(tree->left);
    cout << tree->data << endl;
    in_order(tree->right);
}

void pre_order(unique_ptr<TreeNode<int>> &tree) {
    if (tree == nullptr) {
        return;
    }
    cout << tree->data << endl;
    in_order(tree->left);
    in_order(tree->right);
}

void post_order(unique_ptr<TreeNode<int>> &tree) {
    if (tree == nullptr) {
        return;
    }
    in_order(tree->left);
    in_order(tree->right);
    cout << tree->data << endl;
}

void print_by_level(const unique_ptr<TreeNode<int>>& tree) {
    queue<TreeNode<int>*> q;
    
    cout << tree->data << endl;
    q.emplace(tree.get());
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        if (curr->left) {
            cout << curr->left->data << endl;
            q.emplace(curr->left.get());
        }
        if (curr->right) {
            cout << curr->right->data << endl;
            q.emplace(curr->right.get());
        }
    }
}

int main () {
    //      3
    //    1   5
    unique_ptr<TreeNode<int>> tree;
    
    tree = make_unique<TreeNode<int>>(TreeNode<int>{
        3, nullptr, nullptr});
    
    tree->left = make_unique<TreeNode<int>>(TreeNode<int>{
        1, nullptr, nullptr});
    
    tree->right = make_unique<TreeNode<int>>(TreeNode<int>{
        5, nullptr, nullptr});
    
//    in_order(tree);
    
    print_by_level(tree);
    
    return 0;
}
