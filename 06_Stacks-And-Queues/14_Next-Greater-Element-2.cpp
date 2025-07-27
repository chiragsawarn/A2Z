// Question : Find the next greater element in a circular array.
// https://leetcode.com/problems/next-greater-element-ii/

// Optimal
// Find the largest element index. That has an answer of -1.
// Then iterate the next n-1 elements in a circular array indexing.
// Note: greater element can only exist on the right.

// Time: O(n) [to find the greatest] + O(n) [to iterate over elements] + O(n) [to empty the stack] => O(3n)
// Space: O(2n) [answer array + stack]

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st;
    int start = max_element(nums.begin(), nums.end()) - nums.begin();
    int n = nums.size();
    vector<int> ans(n);

    for(int i=0; i<n; ++i){
        int idx = start - i;
        if(idx < 0) idx = n + idx;

        while(!st.empty() && st.top() <= nums[idx]) st.pop();

        if(!st.empty()){
            ans[idx] = st.top();
        } else {
            ans[idx] = -1;
        }

        st.push(nums[idx]);
    }

    return ans;
}

int main(){
    
    return 0;
}