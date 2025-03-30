#ifndef STACK_HPP
#define STACK_HPP

#include<iostream>
using namespace std;

template<class T> 
class Stack{
private:
    T *_array ;
    int _topIndex ;
    int _capacity ;
    void expand_array();
public:
    Stack(int capacity = 1);
    void push(T element);
    void pop() ;
    T top() const;

    int size() const ;
    bool empty() const;

    ~Stack() {
        delete[] _array;
    }

};


#include"Stack.cpp"

#endif