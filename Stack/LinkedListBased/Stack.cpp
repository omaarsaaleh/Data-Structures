#include"Stack.hpp"


template<class T>
void Stack<T>::push(T element){
    Node<T> *newNode = new Node<T>(element) ;
    if(_head){
        newNode->next = _head ;
    }
    _head = newNode ;
    _size++ ;
}

template<class T>
void Stack<T>::pop(){
    if(!_head)
        throw std::out_of_range("cannot pop from an empty stack");
    Node<T> *temp = _head ;
    _head = _head->next ;
    delete temp ;
    _size-- ;

}

template<class T>
T Stack<T>::top() const{
    if(!_head)
        throw std::out_of_range("empty stack");
    
    return _head->val ;
}

template<class T>
int Stack<T>::size() const{
    return _size;
}

template<class T>
bool Stack<T>::empty() const{
    return !_head;
}