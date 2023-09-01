//
// Created by lin.chen1 on 2022/9/21.
//

#ifndef C_LEARNING_LIST_H
#define C_LEARNING_LIST_H
#include <iostream>


template<typename Object>
struct Node {
    Object data;
    Node *prev;
    Node *next;

    Node(const Object &d = Object(), Node *p = nullptr, Node *n = nullptr)
            : data(d), prev(p), next(n) {};
};
template<typename Object>
struct List {
    Node<Object> *head = new Node<Object>();
    Node<Object> *tail = new Node<Object>();
    int size;

    List() : size(0) {
        head->next = tail;
        tail->prev = head;
    };

    void add( Object item) {
        tail->prev =tail->prev->next= new Node<Object>(item,tail->prev,tail);
        size++;
    }
    Object * peek(){
        return & this->tail->prev->data;
    }
   Object *  pop(){
        Node<Object> * ele = tail->prev;
        tail->prev=tail->prev->prev;
        tail->prev->next=tail;
        size--;
        return &ele->data;
    }
    Object * take(){
        Node<Object> * ele = head->next;
        head->next=head->next->next;
        head->next->prev=head;
        size--;
        return &ele->data;
    }
};

#endif //C_LEARNING_LIST_H
