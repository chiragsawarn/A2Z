// Question: Given an array and integer k, find the maximum of each window of size k.
// https://leetcode.com/problems/sliding-window-maximum/


// Optimal
// Time: O(n) [iteration over main array] + O(n) [to empty deque] => O(2n)
// Space: O(n) [to store maximum element of each window] + O(n) [deque] => O(2n)

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    for(int i=0; i<nums.size(); ++i){
        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k-1){
            ans.push_back(nums[dq.front()]);
            if(dq.front() == i - k + 1) dq.pop_front();
        }
    }

    return ans;
}

int main(){
    
    return 0;
}