#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std ;

// push back
// pop front

template<class T>
struct Node{
    T val ;
    Node *next = nullptr ;
    Node(T val) : val(val){}
};

template<class T>
class Queue{
private:
    
    int _size = 0 ;
    Node<T> *_front = nullptr;
    Node<T> *_rear = nullptr ;

public:
    ~Queue(){
        while(_front){
            Node<T> *temp = _front ;
            _front = _front->next ;
            delete temp ;
        }
    }

    void push(T element);
    void pop() ;
    T front() const;

    bool empty() const;
    int size() const;


};


#include"Queue.cpp"

#endif