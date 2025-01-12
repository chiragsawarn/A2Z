// Search Element in Rotated Sorted Array - 1 [Only unique elements]
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

// Brute Force
// Do a linear search. Find the target value. We treat the array as unsorted.
// Time: O(n)

// Optimal
// Do a binary search. 
// But we can't reduce the search size by eliminating right or left half just by comparing with nums[mid]
// Use the property: "At any mid, either the left or right half is sorted."
// And by checking if target is in the sorted half or not, we can reduce the search space by half at each step.
// Time: O(logn)

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid] == target){
            return mid;
        }
        // if left part sorted?
        if(nums[low] <= nums[mid]){
            // is target in left part?
            if(nums[low] <= target && target < nums[mid]){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if(nums[mid] < target && target <= nums[high]){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main(){
    
    return 0;
}