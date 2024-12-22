// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505
// Find the longest subarray's length that has sum == k. Provided, the array may have -ve integers as well.
#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Find all subarrays possible. Find sum of each subarray. For the subarray with sum = k, update the var largestLength.
// To find all possible subarrays. We let start:0->n-1 and nesting end:0->n-1.
// [1,2,3] => {[1], [1,2], [1,2,3],
//             [2], [2,3],
//             [3]}
// Time: O(n^3) -> First loop decides starting element. Second loop decides ending element. Third loop sums all elements between start and end.
// Space: O(1)

int brute(vector<int> &arr, int k){
    int n = arr.size(), maxSum=INT_MIN;
    for(int start=0; start<n; ++start){
        for(int end=start; end<n; ++end){
            int sum = 0;
            for(int i=start; i<=end; ++i){
                sum += arr[i];
            }
            if(end-start+1 == k){
                maxSum = max(sum, maxSum);
            }
        }
    }
    return maxSum;
}

// Better
// [1] -> [1,2] -> [1,2,3] -> [1,2,3,4]
// Instead of running a loop between start to end to find sum.
// Just add nums[end] as it keep moving. as save a nested loop.
// Time: O(n^2)
// Space: O(1)
int better(vector<int> &arr, int k){
    int n = arr.size(), maxSum=INT_MIN;
    for(int start=0; start<n; ++start){
        int sum = 0;
        for(int end=start; end<n; ++end){
            sum += arr[end];
            if(end-start+1 == k){
                maxSum = max(sum, maxSum);
            }
        }
    }
    return maxSum;
}

// Optimal
// Do a prefix sum as you iterate on the array. Ans store each new prefix sum into a hashmap as mp.insert(currentSum, currentIndex).
// If the current element is the end of a subarray summing upto k. Then a prefix sum of (currentSum - k) must have occured before and will be present in the hashmap.
// If hashmap has currentSum-k as an entry. Then use the index in that entry and currentIdx to update the answer variable.
// Time: O(n)
// Extra Space: O(n)

int getLongestSubarray(vector<int>& nums, int k){
    unordered_map<int,int> mp = {{0,-1}}; // COMMON MISTAKE: Critical to ensure we have a sum == 0 found at the start.
    int sum = 0, maxLen = 0;

    for(int i=0; i<nums.size(); ++i){
        sum += nums[i];
        int rest = sum-k;
        if(mp.find(rest) != mp.end()){
            int endIdxOfRest = mp.find(rest)->second;
            maxLen = max(maxLen, i-endIdxOfRest);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }

    return maxLen;
}

int main(){
    
    return 0;
}