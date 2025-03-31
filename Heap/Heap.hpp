#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
using namespace std ;

// less<T> -> min heap
// greater<T> -> max heap (default)

template <class T, class Comparator = std::greater<T>>
class Heap{
private:
    T *_array ;
    Comparator _compare ;
    int _size ;
    int _capacity ;

    int left(int node_idx) const;
    int right(int node_idx) const;
    int parent(int node_idx) const;
    void heapify_up(int child_idx);
    void heapify_down(int par_idx);

    void expand_array();
public:
    Heap(int capacity = 1) ;

    void push(T element) ;
    void pop() ;
    T top() const;

    int size() const ;
    bool empty() const ;
};


#include "Heap.cpp"

#endif
