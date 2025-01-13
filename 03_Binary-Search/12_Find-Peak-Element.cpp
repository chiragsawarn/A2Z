// https://leetcode.com/problems/find-peak-element/description/
// A peak element is an element that is strictly greater than its neighbors.
// Given array nums, find a peak element, and return its index. 
// If the array contains multiple peaks, return the index to any of the peaks.
// Assumption: nums[-1] = nums[n] = -∞. 

// Brute Force
// Do a linear pass, return the index of the first element that is greater than its neighbours.
// Time: O(n)

// Optimal
// Don't be confused that multiple peaks will result in an unsorted array. So we can't apply BS.
// On an element level (say mid): - 
// if (leftToMid < mid & rightToMid < mid) => We found the answer (i.e nums[mid])
// if (leftToMid < mid) => We are on a strictly increasing curve and we will have an answer to the right. So eliminate left subarray.
//                         We are sure that an answer exists on right subarray because the first condition has come out false for the second condition to execute.
//                         Which means rightToMid which is greater than or equal to the answer is still under consideration.
// if (leftToMid > mid) => Strictly decreasing curve. Answer exists in left subarray. So eliminate right subarray.
// Time: O(logn)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size()-1, n = nums.size();

    while(low<=high){
        int mid = low + (high-low)/2;
        long nextToMid = (mid + 1) == n ? LONG_MIN : nums[mid+1];
        long prevToMid = (mid - 1) == -1 ? LONG_MIN : nums[mid-1];

        if(prevToMid < nums[mid] && nums[mid] > nextToMid){
            return mid;
        } 
        if(prevToMid < nums[mid]){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main(){
    
    return 0;
}