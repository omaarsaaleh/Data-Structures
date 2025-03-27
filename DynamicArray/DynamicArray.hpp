#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include<iostream> 
using namespace std ;

template<class T>
class DynamicArray{
    private:
       int _size ;
       int _capacity ;
       T* _array ;
       
       void expand_array();
       bool is_in_range(int index) const;
       
    public:
        DynamicArray(int capacity = 1) ;
        
        void push_back(T element);
        void pop_back();
        
        void insert_at(int index, T element);
        void erase_at(int index);
        
        int size() const;
        int capacity() const;
        bool empty() const;
       
        void shrink_to_fit();

        int search(T element) const;
        int binary_search(T element) const;

        void reverse(int st = 0, int end = -1 );
        void right_rotate(int n);
        void left_rotate(int n);

        void print() const ;

        T& operator[](int index);
        const T& operator[](int index) const;

        ~DynamicArray(){
            delete[] _array ;
        }
};

#include"DynamicArray.cpp"

#endif