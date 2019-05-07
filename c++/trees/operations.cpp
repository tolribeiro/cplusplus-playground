//
//  operations.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/6/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>
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

void level_order(unique_ptr<TreeNode<int>> &tree) {
    if (tree == nullptr) {
        return;
    }
    in_order(tree->left);
    cout << tree->data << endl;
    in_order(tree->right);
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
    
    in_order(tree);
    return 0;
}
