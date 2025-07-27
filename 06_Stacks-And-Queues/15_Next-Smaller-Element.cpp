// Question : Find the next smaller element to the right
// https://www.naukri.com/code360/problems/next-greater-element_1112581?leftPanelTabValue=PROBLEM

// Optimal : Just use an increasing monotonic stack.
// Time: O(2n)
// Space: O(2n)

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int> st;
    vector<int> ans(n,0);

    for(int i=n-1; i>=0; --i){
        while(!st.empty() && st.top() >= arr[i]) st.pop();
        if(!st.empty()){
            ans[i] = st.top();
        } else {
            ans[i] = -1;
        }

        st.push(arr[i]);
    }

    return ans;
}

int main(){
    
    return 0;
}