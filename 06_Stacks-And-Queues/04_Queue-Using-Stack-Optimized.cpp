#include <bits/stdc++.h>
using namespace std;

// Optimized implementation of a Queue using two stacks
class StackQueue{
    stack<int> inputStack, outputStack;
public:
    void push(int x){
        inputStack.push(x);
    }

    int front(){
        if(!outputStack.empty()){
            return outputStack.top();
        }

        if(inputStack.empty()){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }

        while(!inputStack.empty()){
            int x = inputStack.top();
            inputStack.pop();
            outputStack.push(x);
        }

        return outputStack.top();
    }

    void pop(){
        if(!outputStack.empty()){
            outputStack.pop();
            return;
        }

        if(inputStack.empty()){
            cout<<"Queue is empty!"<<endl;
            return;
        }

        while(!inputStack.empty()){
            int x = inputStack.top();
            inputStack.pop();
            outputStack.push(x);
        }

        outputStack.pop();
    }
};

int main(){
    
    return 0;
}