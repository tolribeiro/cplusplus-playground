//
//  operations.cpp
//  c++
//
//  Created by Thiago Ribeiro on 5/5/19.
//  Copyright © 2019 Thiago Ribeiro. All rights reserved.
//

#include <iostream>
#include "linked_list_prototype.h"

template <typename T>
// Print list recursively
void print_ll(shared_ptr<ListNode<T>> head) {
    if (head) {
        cout << "(" << head->data << ")";
        print_ll(head->next);
    }
    cout << endl;
}

template <typename T>
// Print list iteratively
void print_ll_it(shared_ptr<ListNode<T>> head) {
    while (head) {
        cout << "(" << head->data << ")";
        head = head->next;
    }
}

template <typename T>
int count_nodes(shared_ptr<ListNode<T>> head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

template <typename T>
int max_elem(shared_ptr<ListNode<T>> head) {
    int max = INT_MIN;
    while (head) {
        if (head->data > max) {
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

template <typename T>
// Insert given node at head
void insert_at_head(shared_ptr<ListNode<T>> &head,
                    shared_ptr<ListNode<T>> &new_node) {
    new_node->next = head;
    head = new_node;
}

template <typename T>
// Insert given node at tail
void insert_at_tail(shared_ptr<ListNode<T>> &head,
                    shared_ptr<ListNode<T>> new_node) {
    shared_ptr<ListNode<T>> it = head;
    
    while (it->next != nullptr) {
        it = it->next;
    }
    it->next = new_node;
}

template <typename T>
// Insert node after a specific key
void insert_after_data(shared_ptr<ListNode<T>> &head,
                       int key) {
    shared_ptr<ListNode<int>> new_node = make_shared<ListNode<int>>(ListNode<int>{
        3, nullptr});
    shared_ptr<ListNode<T>> it = head;
    while (it->data != key) {
        it = it->next;
    }
    new_node->next = it->next;
    it->next = new_node;
}

template <typename T>
void reverse_ll(shared_ptr<ListNode<T>> &head) {
    shared_ptr<ListNode<T>> r = nullptr;
    shared_ptr<ListNode<T>> q = nullptr;
    shared_ptr<ListNode<T>> p = head;
    
    while (p != nullptr) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}


template <typename T>
void delete_node(shared_ptr<ListNode<T>> &head,
                       int key) {
    shared_ptr<ListNode<T>> it = head;
    while (it) {
        if (it->next->data == key) {
            it->next = it->next->next;
            break;
        } else {
            it = it->next;
        }
    }
}

template <typename T>
bool check_if_sorted(shared_ptr<ListNode<T>> head) {
    shared_ptr<ListNode<T>> it = head;
    while (it->next != nullptr) {
        if (it->next->data < it->data) {
            return false;
        }
        it = it->next;
    }
    return true;
}

shared_ptr<ListNode<int>> merge_sorted_lists(shared_ptr<ListNode<int>> first,
                                             shared_ptr<ListNode<int>> second) {
    
    shared_ptr<ListNode<int>> third, last;
    
    if (first->data < second->data) {
        third = last = first;
        first = first->next;
        last->next = nullptr;
    } else {
        third = last = second;
        second = second->next;
        last->next = nullptr;
    }
    while (first != nullptr && second != nullptr) {
        if (first->data < second->data) {
            last->next = first;
            last = first;
            first = first->next;
            last->next = nullptr;
        } else {
            last->next = second;
            last = second;
            second = second->next;
            last->next = nullptr;
        }
    }
    if (first != nullptr) last->next = first;
    else last->next = second;
    
    return third;
}

void print_ll_circular(shared_ptr<ListNode<int>> head) {
    shared_ptr<ListNode<int>> p = head;
    do {
        cout << "(" << p->data << ")";
        p = p->next;
    } while (p != head);
    cout << endl;
}

int main () {
    shared_ptr<ListNode<int>> L;
    
    L = make_shared<ListNode<int>>(ListNode<int>({
        1, make_shared<ListNode<int>>(ListNode<int>{
            1, make_shared<ListNode<int>>(ListNode<int>{
                5, make_shared<ListNode<int>>(ListNode<int>{
                    8, nullptr})})})}));
    
    shared_ptr<ListNode<int>> new_node = make_shared<ListNode<int>>(ListNode<int>{3, nullptr});
//    insert_at_head(L, new_node);
//    insert_at_tail(L, new_node);
//    insert_after_data(L, 7);
//    delete_node(L, 5);
//    print_ll(L);
//    cout << check_if_sorted(L) << endl;
//    reverse_ll(L);
    print_ll(L);
    return 0;
}
