// Given a sorted array in which every element occurs twice, except one element that occurs only once. Find the element occuring once.
// https://leetcode.com/problems/single-element-in-a-sorted-array/

// Optimal
// [1,1,2,2,3,3,4,5,5,6,6]
//  0 1 2 3 4 5 6 7 8 9 10
// Until 4 (i.e. the single number): firstOccurance was on evenIndex & secondOccurance on odd index.
// Observation : -
// (firstOccurance:evenIdx, secondOccurance:oddIdx) => LHS is perfect, eliminate it.
// (firstOccurance:oddIdx, secondOccurance:evenIdx) => LHS has the single element, search it.
// Better code : -
// point low = 1 and high = n-2 => This will save you many edge cases.

// Time: O(logn)

#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low = 1, high = nums.size()-2, n = nums.size();
    if(nums.size() == 1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-1] != nums[n-2]) return nums[n-1];

    while(low<=high){
        int mid = low + (high-low)/2;
        bool isMidOdd = mid&1;
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

        if(isMidOdd){
            if(nums[mid-1] == nums[mid]){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        } else {
            if(nums[mid] == nums[mid+1]){
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