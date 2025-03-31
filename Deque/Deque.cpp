#include "Deque.hpp"

template<class T>
Deque<T>::Deque(int capacity) : _size(0), _capacity(capacity), _front(0), _rear(0) {
    if (capacity <= 0)
        throw std::invalid_argument("capacity must be positive");
    _array = new T[capacity];
}


template<class T>
void Deque<T>::expand_array() {
    int newCapacity = 2 * _capacity;
    T* newArray = new T[newCapacity];

    for (int i = 0; i < _size; i++) {
        newArray[i] = _array[(_front + i) % _capacity];
    }

    _front = 0;
    _rear = _size;
    
    delete[] _array;
    
    _array = newArray;
    _capacity = newCapacity;
}

// push / pop

template<class T>
void Deque<T>::push_back(T element) {
    if (_size == _capacity)
        expand_array();

    _array[_rear] = element;
    _rear = (_rear + 1) % _capacity;
    _size++;
}

template<class T>
void Deque<T>::push_front(T element) {
    if (_size == _capacity)
        expand_array();

    _front = (_front - 1 + _capacity) % _capacity;
    _array[_front] = element;
    _size++;
}

template<class T>
void Deque<T>::pop_front() {
    if (empty())
        throw std::out_of_range("cannot pop from an empty deque");

    _front = (_front + 1) % _capacity;
    _size--;
}

template<class T>
void Deque<T>::pop_back() {
    if (empty())
        throw std::out_of_range("cannot pop from an empty deque");

    _rear = (_rear - 1 + _capacity) % _capacity;
    _size--;
}

// access

template<class T>
T Deque<T>::front() const {
    if (empty())
        throw std::out_of_range("empty deque");
    return _array[_front];
}

template<class T>
T Deque<T>::back() const {
    if (empty())
        throw std::out_of_range("empty deque");
    return _array[(_rear - 1 + _capacity) % _capacity];
}

template<class T>
T& Deque<T>::operator[](int index) {
    if (index < 0 || index >= _size)
        throw std::out_of_range("index out of range");
    return _array[(_front + index) % _capacity];
}

template<class T>
const T& Deque<T>::operator[](int index) const {
    if (index < 0 || index >= _size)
        throw std::out_of_range("index out of range");
    return _array[(_front + index) % _capacity];
}


// getters

template<class T>
bool Deque<T>::empty() const {
    return _size == 0;
}

template<class T>
int Deque<T>::size() const {
    return _size;
}
