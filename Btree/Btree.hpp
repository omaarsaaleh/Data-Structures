#ifndef BTREE_HPP
#define BTREE_HPP

#include<iostream> 
using namespace std;


template <typename T, int order>
class BTree {
private:
    struct Node {
        bool isLeaf;
        int numKeys;
        Node* parent ;
        T* keys;
        Node** children;

        Node(bool isLeaf, Node *p)
            : isLeaf(isLeaf), numKeys(0), parent(p) {
            keys = new T[order];
            children = new Node*[order+1](); 
        }

        ~Node() {
            if (!this->isLeaf) {
                for (int i = 0; i <= numKeys; i++) {
                    if(children[i])    
                        delete children[i];
                }
            }
            delete[] keys;
            delete[] children ;
        }
    };

    Node* root;

    void split(Node* node);
    void insertRecursive(Node* node, const T& key);
    void printNode(Node* node, int indent);


public:
    BTree() : root(nullptr){}
    ~BTree(){
        delete root ;
    }


    void insert(const T& key);
    void print();

};


#include"Btree.cpp"


#endif