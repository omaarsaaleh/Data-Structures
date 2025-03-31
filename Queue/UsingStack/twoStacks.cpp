#include<iostream>
#include<stack>
#include<queue>

using namespace std ;

template<class T>
class Queue{
private:
    stack<T> actualStack ;
    stack<T> helperStack ;
public:
    void push(T element){
        while(!actualStack.empty()){
            helperStack.push(actualStack.top());
            actualStack.pop() ;
        }
        actualStack.push(element);
        while(!helperStack.empty()){
            actualStack.push(helperStack.top());
            helperStack.pop();
        }
    }
    void pop(){
        actualStack.pop() ;
    }
    void print(){
        helperStack = actualStack;
        while (!helperStack.empty()) {
            cout << helperStack.top() << " ";
            helperStack.pop();
        }
        cout << endl;
    }
};



int main(){
    Queue<int> q ;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // 1 2 3 4
    q.print();

    return 0; 
}