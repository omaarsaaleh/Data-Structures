#include<iostream>
#include<queue>

using namespace std ;

template<class T>
class Stack{
private:
    queue<T> q ;
public:
    // stack adds back gets back
    // queue adds back gets front

    // every time you push an element
    // push it first then push all the other elements in the queue behind it
    void push(T element){
        int sz = q.size() ;
        q.push(element) ;
        for(int _=0; _<sz; _++){
            q.push(q.front());
            q.pop() ;
        }
    }
    void pop(){
        if (!q.empty()) {
            q.pop();
        } 
    }
    void print() {
        queue<T> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};



int main(){
    Stack<int> st ;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    st.print();
    // 4 3 2 1

    return 0; 
}