//
// Created by lin.chen1 on 2022/9/21.
//

#ifndef C_LEARNING_NODE_H
#define C_LEARNING_NODE_H


template<typename Object>
struct Node {
    Object data;
    Node *prev;
    Node *next;

    Node(const Object &d = Object(), Node *p = nullptr, Node *n = nullptr)
    : data(d), prev(p), next(n) {};
};
template<typename Object>
struct List{
    Node<Object> * head;
    Node<Object> * tail;
    int size;
};

#endif //C_LEARNING_NODE_H
