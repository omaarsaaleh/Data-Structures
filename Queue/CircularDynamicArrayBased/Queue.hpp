#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std ;

template<class T>
class Queue{
private:
    T *_array;
    int _capacity ;
    int _size ;
    int _front ;
    int _rear ;

    void expand_array();

public:
    Queue(int capacity = 1);
    ~Queue(){
        delete _array ;
    }

    void push(T element);
    void pop() ;
    T front() const;

    bool empty() const;
    int size() const;


};


#include"Queue.cpp"

#endif