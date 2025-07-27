#include <bits/stdc++.h>
using namespace std;

// This is the implementation of a Queue using a stack.

class StackQueue{
    stack<int> st;
public:
    void push(int x){
        if(!st.empty()){
            int top_ = st.top();
            st.pop();
            push(x); // recursive call to empty the stack
            st.push(top_);
        } else {
            st.push(x);
        }
    }

    int front(){
        if(st.empty()){
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        return st.top();
    }

    void pop(){
        if(st.empty()){
            cout<<"Queue Underflown!"<<endl;
            return;
        }
        st.pop();
    }

    int size(){
        return st.size();
    }
};

int main(){
    
    return 0;
}