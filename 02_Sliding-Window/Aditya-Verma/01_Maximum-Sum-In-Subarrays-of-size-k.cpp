// Fixed Size Window 1
// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
// Find subarray of size k, with maximum sum where "there are only positive elements".

#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(vector<int>& arr, int k) {
    int i=0, j=0, sum=0, maxSum=0, n=arr.size();
    
    while(j<n){
        // Step 1: Doing sum calculations.
        // Increase sum
        sum += arr[j];
        // Decrease sum
        while(j-i+1 > k){
            sum -= arr[i];
            ++i;
        }
        // Step 2: Updating global maxima when window hits k
        if(j-i+1 == k){
            maxSum = max(maxSum, sum);
        }
        ++j;
    }
    
    return maxSum;
}

int main(){
    
    return 0;
}