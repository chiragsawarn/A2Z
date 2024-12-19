// Question link
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// Brute Force
// Use Ordered Set to find unique elements.
// Iterate the set to overwrite the start of array with unique elements
// Time: O(nlogn) + n

// Optimal
// Use 2 pointers approach
// If arr[slow] != arr[fast] => swap(arr[slow+1], arr[fast])
// Time: O(n)

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    // 2 pointers approach
    int lastUniqueIdx = 0;
    for(int i=1; i<nums.size(); ++i){
        if(nums[lastUniqueIdx] != nums[i]){
            int newUniqueNumber = nums[i];
            ++lastUniqueIdx;
            nums[lastUniqueIdx] = newUniqueNumber;
        }
    }

    return lastUniqueIdx + 1;
}

int main(){
    
    return 0;
}