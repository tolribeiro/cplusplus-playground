//
//  linked_list_prototype.h
//  c++
//
//  Created by Thiago Ribeiro on 5/5/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#ifndef linked_list_prototype_h
#define linked_list_prototype_h

#include <memory>

using namespace std;

// @include
template <typename T>
struct ListNode {
    int data;
    shared_ptr<ListNode<T>> next;
};

#endif /* linked_list_prototype_h */
