#include"DynamicArray.hpp"


// constructors

template<class T>
DynamicArray<T>::DynamicArray(int capacity ) {
    if(capacity < -1)
        throw invalid_argument("capacity must be positive");
    _capacity = capacity ;
    _size = 0 ;
    _array = new T[capacity] ;
}


// expand / shrink

template<class T>
void DynamicArray<T>::expand_array(){
    int newCapacity = 2 * _size;
    T *newArray = new T[newCapacity];

    // preforms shallow copy
    copy(_array, _array + _size, newArray);

    delete[] _array;
    
    _array = newArray;
    _capacity =  newCapacity ;
}


template<class T>
void DynamicArray<T>::shrink_to_fit(){
    int newCapacity = (_size > 0) ? _size : 1;
    T *newArray = new T[newCapacity];

    // preforms shallow copy
    copy(_array, _array + _size, newArray);

    delete[] _array;
    
    _array = newArray;
    _capacity =  newCapacity ;
}



// push / pop

template<class T>
void DynamicArray<T>::push_back(T element){
    if(_size == _capacity)
        expand_array();
    _array[_size++] = element ;
}

template<class T>
void DynamicArray<T>::pop_back(){
    if(_size == 0)
        throw std::out_of_range("cannot pop from an empty dynamic array");
    
    // reset to type's default value
    _array[--_size] = T();

}

// insertion / deletion

template<class T>
void DynamicArray<T>::insert_at(int index, T element){
    if(index == _size){
        push_back(element);
        return ;
    }
    if(!is_in_range(index))
        throw out_of_range("index out of range");
    
    if(_size == _capacity)
        expand_array();

    // right shift elements
    copy(_array + index, _array + _size, _array + index + 1);

    _array[index] = element ;
    _size++ ;

}

template<class T>
void DynamicArray<T>::erase_at(int index){
    
    if(!is_in_range(index))
        throw out_of_range("index out of range");

    // left shift elements
    copy(_array + index + 1, _array + _size, _array + index);

    _size-- ;
}



// getters

template<class T>
int DynamicArray<T>::size() const{
    return _size ;
}

template<class T>
int DynamicArray<T>::capacity() const{
    return _capacity ;
}

template<class T>
bool DynamicArray<T>::empty() const{
    return _size == 0 ;
}

template<class T>
bool DynamicArray<T>::is_in_range(int index) const{
    return -1 < index && index < _size ;
}



// utils


template<class T>
int DynamicArray<T>::search(T element) const{
    for(int i=0; i<_size; i++)
        if(_array[i] == element)
            return i ;
    return - 1;
}

template<class T>
int DynamicArray<T>::binary_search(T element) const{
    int l = 0, r = _size - 1;
    while(l <= r){
        int mid = l + (r-l) / 2 ;
        if(_array[mid] == element)
            return mid ;
        else if(_array[mid] > element)
            r = mid - 1 ;
        else if(_array[mid] < element)
            l = mid + 1 ;
    }
    return - 1;
}

template<class T>
void DynamicArray<T>::reverse(int start, int end) {
    if(end == -1)
        end = _size  ;
    
    if(!is_in_range(start))
        throw out_of_range("start index out of range");
    
    if(!is_in_range(end == _size? end - 1 : end ))
        throw out_of_range("end index out of range");

    if(start > end)
        throw invalid_argument("start cannot be bigger than the end");

    for (int i = start; i < (start + end) / 2; i++) 
        swap(_array[i], _array[end - (i - start) - 1]);
}

template<class T>
void DynamicArray<T>::right_rotate(int n) {
    n %= _size ;

    reverse();

    reverse(0, n);

    reverse(n);

}

template<class T>
void DynamicArray<T>::left_rotate(int n) {
    n %= _size ;

    reverse();

    reverse(0, _size - n);
    
    reverse(_size - n);
}

template<class T>
void DynamicArray<T>::print() const{
    for(int i=0; i<_size; i++)
        cout << _array[i] << ' ';
    cout << '\n';
}

// operators

template<class T>
T& DynamicArray<T>::operator[](int index){
    if(!is_in_range(index))
        throw out_of_range("Index out of range");
    return _array[index];
}

template<class T>
const T& DynamicArray<T>::operator[](int index) const {
    if(!is_in_range(index))
        throw out_of_range("Index out of range");
    return _array[index];
}

