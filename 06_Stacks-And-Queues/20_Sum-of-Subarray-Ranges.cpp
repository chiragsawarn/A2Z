// Question: Given an array. Find the minimum and maximum element of each subarray.
//           Then return the sum of (max-min) for all possible subarrays.
// https://leetcode.com/problems/sum-of-subarray-ranges/

// Optimal Approach: Using stack
// Find Sum of Minimums
// [1,2,3]
// [3,3,3]:nseIdx
// [-1,0,1]:psIdx
// [1*3+1*2+1*1]: No of subarrays each element is minimum in.
// => [3,2,1]*[1,2,3] => 3 + 4 + 3 => 10

// Find sum of Maximums
// [1,2,3]
// [1,2,3]:ngeIdx
// [-1,-1,-1]:pgIdx
// [1*1+2*1+3*1]: No of subarrays each element is maximum in.
// => [1,2,3]*[1,2,3] => 1 + 4 + 9 => 14

// Return: (sum of maximums - sum of minimums)

// Time: O(3n) [for finding sum of minimums] + O(3n) [for finding sum of maximums] => O(6n)
// Space: O(2n) [stack + ans]

#include <bits/stdc++.h>
using namespace std;

long long findSumOfMinimumsOfAllSubarrays(vector<int> &nums){
    int n = nums.size();
    vector<long long> ans(n, 0);
    stack<int> st;

    // nse
    for(long long i=n-1; i>=0; --i){
        while(!st.empty() && nums[st.top()] > nums[i]) st.pop();

        if(st.empty()){
            ans[i] = (n-i)*nums[i];
        }else {
            ans[i] = (st.top()-i)*nums[i];
        }
        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }
    // ps
    for(long long i=0; i<n; ++i){
        while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

        if(st.empty()){
            ans[i] *= (i-(-1));
        } else {
            ans[i] *= (i-st.top());
        }

        st.push(i);
    }

    return accumulate(ans.begin(), ans.end(), 0LL);
}

long long findSumOfMaximumsOfAllSubarrays(vector<int> &nums){
    int n = nums.size();
    vector<long long> ans(n, 0);
    stack<int> st;

    // nge
    for(long long i=n-1; i>=0; --i){
        while(!st.empty() && nums[st.top()] < nums[i]) st.pop();

        if(st.empty()){
            ans[i] = (n-i)*nums[i];
        } else {
            ans[i] = (st.top()-i)*nums[i];
        }
        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    // pg
    for(long long i=0; i<n; ++i){
        while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();

        if(st.empty()){
            ans[i] *= (i-(-1));
        } else {
            ans[i] *= (i-st.top());
        }

        st.push(i);
    }

    return accumulate(ans.begin(), ans.end(), 0LL);
}

long long subArrayRanges(vector<int>& nums) {
    long long sumOfMinimums = findSumOfMinimumsOfAllSubarrays(nums);
    long long sumOfMaximums = findSumOfMaximumsOfAllSubarrays(nums);

    return sumOfMaximums-sumOfMinimums;
}

int main(){
    
    return 0;
}