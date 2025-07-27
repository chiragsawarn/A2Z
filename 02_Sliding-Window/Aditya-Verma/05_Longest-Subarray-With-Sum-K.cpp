// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399

// NOTE: ARRAY CONTAINS ONLY POSITIVES. This is why sliding window is applicable.

// Brute Force
// Find all the subarrays.
// Calculate sum of each subarray while finding it.
// Whenever (sum == k) => ++count
// Time: O(n^2)
// Space: O(1)

// Optimal
// Use variable size sliding window technique
// Time: O(n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int maxLen=0, i=0, j=0, n=a.size();
    long long sum=0;

    while(j<n){
        sum += a[j];
        while(sum > k){
            sum -= a[i];
            ++i;
        }
        if(sum == k){
            maxLen = max(maxLen, j-i+1);
        }
        ++j;
    }
    
    return maxLen;
}

int main(){
    
    return 0;
}