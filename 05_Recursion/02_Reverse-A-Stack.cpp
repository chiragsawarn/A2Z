#include <bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &st, vector<int> &arr){
    if(st.empty()) {
        for(int i=0; i<arr.size(); ++i){
            st.push(arr[i]);
        }
        return;
    }
    int x = st.top();
    st.pop();
    arr.push_back(x);
    reverseStack(st, arr);
}

void print(stack<int> st, string desc){
    cout<<desc<<endl;
    while(!st.empty()){
        int x = st.top();
        cout<<x<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    vector<int> arr;
    print(st, "Before : ");
    reverseStack(st, arr);
    print(st, "After : ");

    return 0;
}