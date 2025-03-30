#include"Stack.hpp"

template<class T>
Stack<T>::Stack(int capacity){
    if(capacity <= 0)
        throw invalid_argument("capacity must be positive");
    
    _capacity = capacity ;
    _array = new T[capacity] ;

    _topIndex = -1 ;
}


template<class T>
void Stack<T>::expand_array(){
    int newCapacity = 2 * (_topIndex + 1);
    T *newArray = new T[newCapacity];

    // preforms shallow copy
    copy(_array, _array + _topIndex + 1, newArray);

    delete[] _array;
    
    _array = newArray;
    _capacity =  newCapacity ;
}

template<class T>
void Stack<T>::push(T element){
    if(_topIndex + 1 == _capacity)
        expand_array();
    _array[++_topIndex] = element ;
}

template<class T>
void Stack<T>::pop(){
    if(_topIndex == -1)
        throw std::out_of_range("cannot pop from an empty stack");
    _topIndex-- ;
}

template<class T>
T Stack<T>::top() const{
    if(_topIndex == -1)
        throw std::out_of_range("cannot pop from an empty stack");
    
    return _array[_topIndex] ;
}

template<class T>
int Stack<T>::size() const{
    return _topIndex+1;
}

template<class T>
bool Stack<T>::empty() const{
    return _topIndex == -1;
}