#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include<iostream>
#include <initializer_list>
#include <map>
using namespace std;


template<class T>
struct Node{
    T data ;
    Node * next{};
    Node(T val):data(val){}
};

template<class T>
class SinglyLinkedList{
private :
    Node<T> *head{};
    Node<T> *tail{};
    int length{};
    Node<T>* get_nth_node(int n) const;  // o(n)
    void erase_next_node(Node<T> *node); // o(1)


public :
    SinglyLinkedList(){}
    SinglyLinkedList(initializer_list<T> values);
    SinglyLinkedList(const SinglyLinkedList<T>& other);
    ~SinglyLinkedList();
    SinglyLinkedList<T>& operator=(initializer_list<T> values);
    SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>& other);
    
    void push_back(T val); // o(1)
    void push_front(T val); // o(1)
    void pop_back(); // o(n)
    void pop_front(); // o(1)
    
    void erase(int index); // o(n)
    void insert_at(int index,T val); // o(n)
    
    void clear(); //o(n)
    
    int size() const; // o(1)
    bool empty() const; // o(1)

    void reverse(); // o(n)
    void make_unique(); // o(nlogn)
    
    T& operator[](int index) const; // o(n)
    
    void print() const; // o(n)

    void swap(int idx1, int idx2);

    class ConstIterator;
    ConstIterator  cbegin() const { return ConstIterator(this->head); }
    ConstIterator cend() const { return ConstIterator(nullptr); }
    ConstIterator  begin() const { return ConstIterator(this->head); }
    ConstIterator end() const { return ConstIterator(nullptr); }
    
    class Iterator;
    Iterator begin() { return Iterator(this->head); }
    Iterator end() { return Iterator(nullptr); }
    
    T& front(){if(length==0) throw out_of_range("Index out of range");  return this->head->data;} // o(1)
    T& back(){ if(length==0) throw out_of_range("Index out of range");  return this->tail->data;} // o(1)
    
};

template<class T>
class SinglyLinkedList<T>::Iterator {
private:
    Node<T>* current;
    friend class ConstIterator;
public:
    Iterator(Node<T>* start) : current(start) {}
    T& operator*();
    Iterator& operator++(); // Pre-increment
    Iterator& operator++(int); // Post-increment 
    bool operator==(const Iterator& other) const; 
    bool operator==(const ConstIterator& other) const; 
    bool operator!=(const Iterator& other) const;
    bool operator!=(const ConstIterator& other) const;
};

template<class T>
class SinglyLinkedList<T>::ConstIterator {
private:
    const Node<T>* current;
    friend class Iterator;

public:
    ConstIterator(const Node<T> *start) : current(start) {}
    const T& operator*() const;
    ConstIterator& operator++(); // Pre-increment
    ConstIterator& operator++(int); // Post-increment 
    bool operator==(const ConstIterator& other) const; 
    bool operator==(const Iterator& other) const; 
    bool operator!=(const ConstIterator& other) const;
    bool operator!=(const Iterator& other) const;
};





#endif
