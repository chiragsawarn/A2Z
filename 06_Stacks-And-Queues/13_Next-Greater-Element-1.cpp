// Question: Next Greater Element 1
// Given an array of unique elements, find the next greater element to the right of each element in the array.
// https://leetcode.com/problems/next-greater-element-i/

// Brute Force
// For each element traverse to the right and find the just greater element. if none found save -1 as ans for that element.
// Time: O(n^2)

// Optimal: Monotonic Stack
// A stack is called monotonic when it stores non-decreasing or non-increasing order of elements.
// if we traverse from the right to left, we will know which greater elements are contenders for an element.
// the closest contender will be at the top of the stack.
// if an element is greater than the top of stack, then we can keep popping the top till the next greater element to current element is found.
// Eg: current element is 12 stack has [1,2,3,15]
// We are okay with popping smaller elements than current element coz, the current element will be the closer contender to all the elements to its left.
// Eg: stack: [12,15] after popping 1,2,3 < 12 => next_greater_element(12)->15
//     if current element is 5, stack:[12, 15] => next_greater_element(5)->12
//     else current element is 14, stack:[12, 15] => next_greater_element(14)-> 15 [After popping 12 as 12 <= 14]
// Time: O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    unordered_map<int, int> mp;

    for(int i=nums2.size()-1; i>=0; --i){
        while(!st.empty() && nums2[i] >= st.top()){
            st.pop();
        }
        if(st.empty()){
            mp.insert({nums2[i], -1});
        } else {
            mp.insert({nums2[i], st.top()});
        }
        st.push(nums2[i]);
    }

    vector<int> ans;

    for(int i=0; i<nums1.size(); ++i){
        ans.push_back(mp[nums1[i]]);
    }

    return ans;
}

int main(){
    
    return 0;
}