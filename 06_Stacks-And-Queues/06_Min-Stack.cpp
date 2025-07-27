// Write a minStack that does PUSH, POP, TOP, and MinElement in O(1)
#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<pair<int,int>> st;
public:
    void push(int val) {
        if(st.empty()){
            st.push({val, INT_MAX});
            return;
        }
        int bottomMin = min(st.top().first, st.top().second);
        st.push({val, bottomMin});
    }
    
    void pop() {
        if(!st.empty()) st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        int bottomMin = min(st.top().first, st.top().second);
        return bottomMin;
    }
};

int main(){
    
    return 0;
}