#include <bits/stdc++.h>
using namespace std;

class ArrayStack {
    vector<int> arr;
    int top_ = -1;
public:
    ArrayStack() {
    }
    
    void push(int x) {
        ++top_;
        arr.push_back(x);
    }
    
    int pop() {
        if(!isEmpty()){
            --top_;
            return arr[top_+1];
        }
        return INT_MAX;
    }
    
    int top() {
        if(!isEmpty()) return arr[top_];
        return INT_MAX;
    }
    
    int size() {
        return top_ + 1;
    }
    
    bool isEmpty() {
        return top_ == -1;
    }
};

int main(){
    ArrayStack st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.pop();
    cout<<"Is arrayStack empty: "<<st1.isEmpty()<<endl;
    cout<<"Size of arrayStack : "<<st1.size()<<endl;

    cout<<"Printing arrayStack :-"<<endl;
    while(!st1.isEmpty()){
        int x = st1.top();
        st1.pop();
        cout<<x<<endl;
    }

    return 0;
}