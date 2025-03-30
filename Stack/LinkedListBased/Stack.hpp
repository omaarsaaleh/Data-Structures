#ifndef STACK_HPP
#define STACK_HPP

#include<iostream>
using namespace std;


template<class T> 
struct Node{
    T val ;
    Node *next;
    Node():next(nullptr){}
    Node(T val):next(nullptr){
        this->val = val ;
    }
};

template<class T> 
class Stack{
private:
    Node<T> *_head = nullptr ;
    int _size = 0 ;
public:
    void push(T element);
    void pop() ;
    T top() const;

    int size() const ;
    bool empty() const;

    ~Stack() {
        while(_head){
            Node<T> *temp = _head ;
            _head = _head->next ;
            delete temp ;
        }
    }

};


#include"Stack.cpp"

#endif