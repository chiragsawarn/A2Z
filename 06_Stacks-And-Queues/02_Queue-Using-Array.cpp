// Write the internal implementation of a queue using an array.
// Goal: Complexity of operations should resemble a queue.
#include <bits/stdc++.h>
using namespace std;

class ArrayQueue{
    vector<int> arr;
    int start,end;
    int capacity;
    int size_;
public:
    ArrayQueue(int capacity) {
        arr.resize(capacity);
        start = -1;
        end = -1;
        this->capacity = capacity;
        size_ = 0;
    }

    void push(int x){
        if(size_ == capacity) {
            cout<<"Queue Overflown!"<<endl;
            return;
        }
        if(start == -1) start = 0;
        end = (end+1)%capacity;
        arr[end] = x;
        ++size_;
    }

    void pop(){
        if(size_ == 0) {
            cout<<"Queue Underflown!"<<endl;
            return;
        }
        start = (start + 1)%capacity;
        --size_;
    }

    bool empty(){
        return size_ == 0;
    }

    int front(){
        if(size_ == 0) {
            cout<<"Queue Empty!"<<endl;
            return -1;
        }
        return arr[start];
    }

    int size(){
        return size_;
    }
};
// int main(){
//     ArrayQueue q(5);
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);

//     q.pop(); // Poppping first inserted item i.e. 1

//     cout<<"Is Queue Empty : "<<q.empty()<<endl; // false
//     cout<<"Size of Queue  : "<<q.size()<<endl;  // [2, 3, 4] => Size:3

//     cout<<"Printing Queue :- "<<endl; // [2, 3, 4]
//     while(!q.empty()){
//         int x = q.front();
//         q.pop();
//         cout<<x<<endl;
//     }
//     return 0;
// }