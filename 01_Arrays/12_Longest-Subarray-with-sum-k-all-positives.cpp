// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=PROBLEM
// Find the size of longest subarray with given sum k
// NOTE : The array only contains positive elements


// Brute Force
// Find all subarrays possible. Find sum of each subarray. For the subarray with sum = k, update the var largestLength.
// To find all possible subarrays. We let start:0->n-1 and nesting end:0->n-1.
// [1,2,3] => {[1], [1,2], [1,2,3],
//             [2], [2,3],
//             [3]}
// Time: O(n^3) -> First loop decides starting element. Second loop decides ending element. Third loop sums all elements between start and end.
// Space: O(1)

// Optimal
// Use sliding window technique. 
// As all elements are positive:-
// To increase sum: ++fastPtr => increases window size and sum as the next element is guaranteed +ve
// To decrease sum: ++slowPtr => decreases window size and sum, as the lost element is guranteed positive.
// Time: O(n)
// Space: O(1)


#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> arr, long long k) {
    long long i=0, j=0, n=arr.size(), sum=0, maxLen=0;
        
    while(j<n){
        sum += arr[j];
        while(sum>k){
            sum -= arr[i];
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