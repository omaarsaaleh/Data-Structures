#include"Heap.hpp"

template<class T, class Comparator>
Heap<T, Comparator>::Heap(int capacity) : _compare(Comparator()) { 
    _capacity = capacity ;
    _size = 0 ;
    _array = new T[_capacity] ;
}


template<class T, class Comparator>
int Heap<T, Comparator>::left(int node_idx) const {
    int p = 2 * node_idx + 1;
    return (p < _size) ? p : -1;
}

template<class T, class Comparator>
int Heap<T, Comparator>::right(int node_idx) const {
    int p = 2 * node_idx + 2;
    return (p < _size) ? p : -1;
}

template<class T, class Comparator>
int Heap<T, Comparator>::parent(int node_idx) const{
    return (node_idx == 0) ? -1 : (node_idx - 1) / 2;
}

template<class T, class Comparator>
void Heap<T, Comparator>::expand_array(){
    int newCapacity = 2 * _size;
    T *newArray = new T[newCapacity];

    // preforms shallow copy
    copy(_array, _array + _size, newArray);

    delete[] _array;
    
    _array = newArray;
    _capacity =  newCapacity ;
}


template<class T, class Comparator>
void Heap<T, Comparator>::heapify_up(int child_idx) {
    int par_pos = parent(child_idx);
    
    if (par_pos == -1 || _compare(_array[par_pos], _array[child_idx]))
        return;

    std::swap(_array[child_idx], _array[par_pos]);
    heapify_up(par_pos);
}

template<class T, class Comparator>
void Heap<T, Comparator>::heapify_down(int par_idx) {
    int left_idx = left(par_idx);
    int right_idx = right(par_idx);

    if (left_idx == -1)  return;
		
    if (right_idx != -1 &&  _compare(_array[right_idx], _array[left_idx]))
        left_idx = right_idx;

    // swap and heapify if violates the heap property.
    if ( _compare(_array[left_idx], _array[par_idx])) {
        std::swap(_array[par_idx], _array[left_idx]);
        heapify_down(left_idx);
    }
}


// push/pop

template<class T, class Comparator>
void Heap<T, Comparator>::push(T element) {
    if(_size == _capacity)
        expand_array() ;
    _array[_size] = element;
    heapify_up(_size);
    _size++ ;
}

template<class T, class Comparator>
void Heap<T, Comparator>::pop() {
    if(empty()) 
        throw std::out_of_range("heap is empty");
    _array[0] = _array[--_size];
    heapify_down(0);
}


// getters

template<class T, class Comparator>
T Heap<T, Comparator>::top() const{
    if(empty()) 
        throw std::out_of_range("heap is empty");
    return _array[0] ;
}

template<class T, class Comparator>
bool Heap<T, Comparator>::empty() const{
    return _size == 0 ;
}

template<class T, class Comparator>
int Heap<T, Comparator>::size() const{
    return _size ;
}
