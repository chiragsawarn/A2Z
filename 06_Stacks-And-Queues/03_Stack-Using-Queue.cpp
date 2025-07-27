#include <bits/stdc++.h>
using namespace std;

// This is a stack implementation using a Queue
// NOTE: Since Queue is FIFO and Stack is LIFO, we need to do extra operations to push an element.
class QueueStack{
    queue<int> q;
public:
    void push(int x){
        int size = q.size();
        q.push(x);
        while(size--){
            q.push(q.front());
            q.pop();
        }
    }

    void pop(){
        if(q.empty()){
            cout<<"Stack Underflown!"<<endl;
            return;
        }
        q.pop();
    }

    int size(){
        return q.size();
    }

    int top(){
        return q.front();
    }
};

int main(){
    
    return 0;
}