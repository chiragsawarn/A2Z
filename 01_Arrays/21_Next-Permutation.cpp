// https://leetcode.com/problems/next-permutation/

// Brute Force
// Find each permutation of the array in lexographically sorted order.
// Find the current array in that list of sorted arrays.
// The next item in the sorted array list would be your next Permutation.
// Time: O(n!) [To find all the permutations] x O(n) [To find current array] => O(n*n!)
// Space: O(n*n!)

// Better
// Use STL's next_permutation function

// Optimal
// To find the next iteration, we need to find the array with the longest common prefix to the orignal array.
// So, for [2,1,5,4,3,0,0]
// We start with [2,1,5,4,3] that is the array with longest common prefix to original array but is no larger. We need it larger than original.
// Next, we try  [2,1,5,4] + [3] 
// Next, we try  [2,1,5] + [4,3] => If we permute [4,3] we can't find any permutation greater than original. [3,4] is just smaller.
// Next, we try  [2,1] + [5,4,3]
// Next, we try  [2] + [1,5,4,3] => HEY! Now we can find a permutation of [1,5,4,3] greater than original. So lets find the one that is "barely-greater" so that its the next permutation.
//                                  To find next greater, we need to replace [1] {the pivot} with element just greater than 1 in [5,4,3]
// Great, now we have [2,3] + [_,_,_] => What should the order of the rest of elements be? Answer is ascending order so that the elements are barely greater than original array.
// Instead of using sorting we can notice [5,4,1] are already sorted, so we just reverse the remaining array.
// That leaves us with [2,3] + [1,4,5] => [2,3,1,4,5] {Next permutation}

// NOTE : You need to handle the case in which you dont find a bump/pivot. Eg [5,4,3,2,1]

#include <bits/stdc++.h>
using namespace std;

void nextPermutation_usingSTL(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int pivotIndex = -1;

    // Step 1 : Find the bump
    for(int i=n-2; i>=0; --i){
        if(nums[i] < nums[i+1]){
            // bump found
            int pivot = nums[i];
            pivotIndex = i;

            // Step 2: Replace the bump with next greater element
            for(int j=n-1; j>i; --j){
                if(nums[j] > pivot){
                    int justGreaterThanPivot = nums[j];
                    swap(nums[i], nums[j]);
                    break;
                }
            }
            break;
        }
    }

    // Step 3 : Reverse the decendingly sorted part after the pivot to make it as small as possible.
    reverse(nums.begin()+pivotIndex+1, nums.end());
}

int main(){
    
    return 0;
}