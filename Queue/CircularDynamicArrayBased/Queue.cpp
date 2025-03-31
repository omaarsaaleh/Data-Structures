#include "Queue.hpp"

template<class T>
Queue<T>::Queue(int capacity) :  _size(0), _front(0), _rear(0) {
    if(capacity <= 0)
        throw invalid_argument("capacity must be positive");
    _capacity = capacity ;
    _array = new T[capacity] ;
}

template<class T>
void Queue<T>::expand_array() {
    int newCapacity = 2 * _size;
    T *newArray = new T[newCapacity];

    for (int i = 0; i < _size; i++) {
        newArray[i] = _array[(_front + i) % _capacity];
    }
    _front = 0;
    _rear = _size;

    delete[] _array;
    
    _array = newArray;
    _capacity =  newCapacity ;
}

template<class T>
void Queue<T>::push(T element) {
    if(_size == _capacity)
        expand_array();
    _array[_rear] = element ;
    _rear = (_rear + 1) % _capacity;
    _size++ ;
}

template<class T>
void Queue<T>::pop() {
    if(empty())
        throw std::out_of_range("cannot pop from an empty queue");
    _front = (_front + 1) % _capacity;
    _size -- ;    
}

template<class T>
T Queue<T>::front() const{
    if(empty())
        throw std::out_of_range("empty queue");
    return _array[_front] ;
}

template<class T>
bool Queue<T>::empty() const{
    return _size == 0 ;
}

template<class T>
int Queue<T>::size() const{
    return _size ;
}