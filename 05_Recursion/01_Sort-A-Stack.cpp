#include <bits/stdc++.h>
using namespace std;

void sortStackUsingMaxHeap(stack<int> &st, priority_queue<int> &pq){
    if(st.empty()){
        while(!pq.empty()){
            int x= pq.top();
            pq.pop();
            st.push(x);
        }
        return;
    }
    int x = st.top();
    pq.push(x);
    st.pop();
    sortStackUsingMaxHeap(st, pq);
}

void print(stack<int> st){
    while(!st.empty()){
        int x = st.top();
        cout<<x<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> st;
    st.push(5);
    st.push(1);
    st.push(4);
    st.push(2);
    st.push(3);

    priority_queue<int> pq;

    sortStackUsingMaxHeap(st, pq);
    print(st);
    
    return 0;
}