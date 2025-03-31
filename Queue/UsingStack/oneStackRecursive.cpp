#include<iostream>
#include<stack>
#include<queue>

using namespace std ;

template<class T>
class Queue{
private:
    stack<T> st ;
    // empty the stack
    // push the element
    // then push other elements reversely to preserve the order
    // Queue  back {2,1} front  add 3
    // {3} -- {3,2} -- {3,2,1}
    void push(stack<T> &st, const T &element){
        if(st.empty()){
            st.push(element);
            return ;
        }
        T top = st.top();
        st.pop();
        push(st, element) ;
        st.push(top) ;
    }
public:
    void push(T element){
        push(st, element) ;
    }
    void pop(){
        st.pop() ;
    }
    void print(){
        stack<T> temp = st;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
    T front(){
        return st.top() ;
    }
    bool empty(){
        return st.empty();
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