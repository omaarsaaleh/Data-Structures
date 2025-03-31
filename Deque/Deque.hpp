#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <iostream>

template<class T>
class Deque {
private:
    T* _array;
    int _size;
    int _capacity;
    int _front;
    int _rear;

    void expand_array();

public:
    Deque(int capacity = 1);
    ~Deque(){
        delete[] _array;
    }

    void push_back(T element);
    void push_front(T element);
    void pop_front();
    void pop_back();
    
    T front() const;
    T back() const;
    
    bool empty() const;
    int size() const;

    T& operator[](int index) ;
    const T& operator[](int index) const ;
};;

#include "Deque.cpp"

#endif 
