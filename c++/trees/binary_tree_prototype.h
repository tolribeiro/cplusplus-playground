//
//  binary_tree_prototype.h
//  c++
//
//  Created by Thiago Ribeiro on 5/6/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#ifndef binary_tree_prototype_h
#define binary_tree_prototype_h

#include <memory>

using namespace std;

// @include
template <typename T>
struct TreeNode {
    T data;
    unique_ptr<TreeNode<T>> left, right;
};
// @exclude

#endif /* binary_tree_prototype_h */
