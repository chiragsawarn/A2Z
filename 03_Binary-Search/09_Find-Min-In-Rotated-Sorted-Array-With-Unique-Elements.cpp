// Find the minimum in rotated sorted array with "unique" elements.
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Brute Force
// Do a linear iteration to find the minimum.
// This approach treats the array as unsorted.
// Time: O(n)

// Optimal
// To optimize, we need to reduce the search space by half at each step.
// For this we can use the property any element in the rotated sorted array has either left part or right part as sorted.
// So just save the min element of the sorted half as a possible answer. And keep looking for a better answer in the unsorted half.
// Time: O(logn)

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size()-1;
    int minVal = INT_MAX;
    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[low] <= nums[mid]){
            minVal = min(nums[low], minVal);
            low = mid + 1;
        } else {
            minVal = min(nums[mid], minVal);
            high = mid - 1;
        }
    }

    return minVal;
}

int main(){
    
    return 0;
}