// Given a sorted array with strictly increasing order.
// Find all mising integers in it in sorted order. Return the K-th missing integer.
// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. 
// The 5th missing positive integer is 9.
#include <bits/stdc++.h>
using namespace std;

// Brute Force
// k shifts towards right, each time you find one element that is in the range of k.
// [2,3,4,7,11], k=5
// [2]+[3,4,7,11], k->6
// [2,3] + [4,7,11], k->7
// [2,3,4] + [7,11], k->8
// [2,3,4,7] + [11], k->9 
// 11 > k=9 => So we stop here.
// Time: O(n) 
// Space: O(1)
int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    
    for(int i=0; i<n; ++i){
        if(arr[i] <= k){
            ++k;
        }else {
            return k;
        }
    }
    return k;
}

// Optimal
// Use binary search to find the index close to answer
// [2,3,4,7,11], k=5
//  0 1 2 3 4
// At the 3rd index we should have 4. But we have 7. So at 7, we have 7-4 => 3 missing numbers.
// ... while 4th index should have 5. But has 11. So at 11, we have 11-5 => 6 missing numbers.
// So we sure our answers lies between 7 and 11.
// Time: O(logn)
// Space: O(1)
int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n-1;

    while(low<=high){
        int mid = low + (high-low)/2;
        int countOfMissingNumbersAtMid = arr[mid] - (mid+1);
        if(countOfMissingNumbersAtMid >= k){
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }

    // int countOfMissingNumAtHigh = arr[high] - (high+1);
    // int kthMissingNumber = arr[high] + (k - countOfMissingNumAtHigh);
    // kthMissingNumber = arr[high] + k - arr[high] + (high+1);
    // kthMissingNumber = k + (high+1);
    int kthMissingNumber = k + low;
    return kthMissingNumber;
}

int main(){
    
    return 0;
}