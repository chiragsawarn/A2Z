#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Do a linear search to find the target.
// Time: O(n)

// Optimal
// We can try to reduce the search space in half at each step.
// By using the property "for any element, left or right half is sorted"
// So if element is in limits of the sorted half, we can discard the unsorted half, or vice-versa.
// But this isn't full proof as we have duplicates.
// Ex : {1,0,1,1,1} and taget = 0
// Here by checking mid and last elements we can't tell which half is sorted.
// So when we find this troubling condition (nums[low] == nums[mid] == nums[high])
// => Then we: --high; ++low; and hope for the best.
// Which means in worst case [3,3,3,3,3,3,3,3,3] => Time: O(n/2)
// Time in average case : O(logn)

bool search(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid] == target){
            return true;
        }
        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            high = high - 1;
            low = low + 1;
        } else if(nums[low] <= nums[mid]){
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

    return false;
}

int main(){
    
    return 0;
}