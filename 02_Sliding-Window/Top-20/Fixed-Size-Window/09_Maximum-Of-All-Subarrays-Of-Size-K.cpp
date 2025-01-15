// https://leetcode.com/problems/sliding-window-maximum/description/
#include <bits/stdc++.h>
using namespace std;

// Optimal : Use Deque
// We scan the array from 0 to n-1, keep "promising" elements in the deque. 
// Each element is pushed and popped at max once.
// Time: O(2n)
// Space: O(n)

vector<int> maxOfAllSubarraysOfSizeK(vector<int> &nums, int k){
    vector<int> maxOfEachSubarrayOfSizeK;
    deque<int> q;
    int i=0, j=0, n=nums.size(); 
    while(j<n){
        while(!q.empty() && nums[j] >= nums[q.back()]){
            q.pop_back();
        }
        q.push_back(j);
        if(j-i+1 == k){
            maxOfEachSubarrayOfSizeK.push_back(nums[q.front()]);
            if(q.front() == i){
                q.pop_front();
            }
            ++i;
        }
        ++j;
    }

    return maxOfEachSubarrayOfSizeK;
}

int main(){
    
    return 0;
}