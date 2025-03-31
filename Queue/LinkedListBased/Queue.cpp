#include "Queue.hpp"

template<class T>
void Queue<T>::push(T element) {
    Node<T> *newNode = new Node<T>(element);
    if (!_rear) {
        _front = _rear = newNode;
    } 
    else {
        _rear->next = newNode;
        _rear = newNode;
    }
    _size++ ;
}

template<class T>
void Queue<T>::pop() {
    if(!_front)
        throw std::out_of_range("cannot pop from an empty queue");
    Node<T> *temp = _front ;
    _front = _front->next ;
    if (!_front) { 
        _rear = nullptr;
    }
    delete temp ;
    _size-- ;
}

template<class T>
T Queue<T>::front() const{
    if(!_front)
        throw std::out_of_range("empty queue");
    return _front->val ;
}

template<class T>
bool Queue<T>::empty() const{
    return _size == 0 ;
}

template<class T>
int Queue<T>::size() const{
    return _size ;
}