// https://leetcode.com/problems/subarray-sum-equals-k/
// Find the count of subarrays with sum == k

// Optimal
// Use the technique <-----(prefixSum-k)-----><---(k)--->=prefixSum
// To check if subarray ending at i-th index has sum k, check if we encountered a prefix sum of (sum-k) previously.
// Time: O(n)
// Space: O(n) [To maintain an unordered_map with {prefixSum, countOfSubarraysWithSumKatThisIndex}]

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp = {{0,1}}; // {sum, countOfSum}
    int count = 0, sum = 0;

    for(int i=0; i<nums.size(); ++i){
        sum += nums[i];
        int rest = sum - k;
        if(mp.find(rest) != mp.end()){
            count += mp.find(rest)->second;
        }
        ++mp[sum];
    }

    return count;
}

int main(){
    
    return 0;
}