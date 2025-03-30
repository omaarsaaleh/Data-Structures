#include"Btree.hpp"


template <typename T, int order>
void BTree<T, order>::split(Node* node) {
    int medianIdx = order / 2;
    T median = node->keys[medianIdx];

    Node* newNode = new Node(node->isLeaf, node->parent);
    // the right takes the smaller half of the remaining
    newNode->numKeys = (order - 1) / 2;
    node->numKeys = (order) / 2;

    
    for (int j = 0; j < newNode->numKeys; j++) 
        newNode->keys[j] = node->keys[j + medianIdx + 1];

    if (!node->isLeaf) 
        for (int j = 0; j <= newNode->numKeys; j++)
            newNode->children[j] = node->children[j + medianIdx + 1];
    

    if (node == root) {
        root = new Node(false, nullptr);
        root->keys[0] = median;
        root->children[0] = node;
        root->children[1] = newNode;
        root->numKeys = 1;
        node->parent = root;
        newNode->parent = root;
        return;
    }

    Node* parent = node->parent;
    int insertPos = 0;

    while (insertPos < parent->numKeys && parent->keys[insertPos] < median)
        insertPos++;

    for (int j = parent->numKeys; j > insertPos; j--) {
        parent->keys[j] = parent->keys[j - 1];
        parent->children[j + 1] = parent->children[j];
    }

    parent->keys[insertPos] = median;
    parent->children[insertPos + 1] = newNode;
    parent->numKeys++;

    if (parent->numKeys == order)
        split(parent);
}

template <typename T, int order>
void BTree<T, order>::insertRecursive(Node* node, const T& key) {
    if (!node->isLeaf) {
        int i = node->numKeys - 1;
        while (i >= 0 && key < node->keys[i]) 
            i--;
        i++;
        insertRecursive(node->children[i], key);
        
    } 
    else {
        // Insert
        int i = node->numKeys - 1;
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
        
        // if the node overflowed 
        if (node->numKeys == order )
            split(node);
        
           
    }
}

template <typename T, int order>
void BTree<T, order>::insert(const T& key) {
    if (!root) {
        root = new Node(true, nullptr);
        root->keys[0] = key;
        root->numKeys = 1;
        return ;
    } 
    insertRecursive(root, key);
}


template <typename T, int order>
void BTree<T, order>::printNode(Node* node, int indent) {
    if (!node) return;

    for (int i = 0; i < indent; i++)
        cout << "  ";
    
    for (int i = 0; i < node->numKeys; i++) {
        cout << node->keys[i];
        if (i < node->numKeys - 1) cout << ",";
    }
    
    cout << '\n';

    if (!node->isLeaf) {
        for (int i = 0; i <= node->numKeys; i++) {
            printNode(node->children[i], indent + 1);
        }
    }
}

template <typename T, int order>
void BTree<T, order>::print() {
    printNode(root, 0);
}
