// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

// Brute Force : Linear search
// Time: O(n)

// Optimal : Binary Search
// Use lower_bound => To find first index of occurance.
// Use upper_bound -1 => To find last index of occurance.
// Time: O(logn)

#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange_stl(vector<int>& nums, int target) {
    auto lbItr = lower_bound(nums.begin(), nums.end(), target);
    auto ubItr = upper_bound(nums.begin(), nums.end(), target);

    int start = -1;
    if(lbItr != nums.end() && *lbItr == target){
        start = lbItr - nums.begin();
    }

    int end = -1;
    if(ubItr != nums.begin() && *(ubItr-1) == target){
        end = ubItr - 1 - nums.begin();
    }

    return {start, end};
}

int firstOccurance(vector<int> & nums, int x){
    int low = 0, high = nums.size()-1, ansIdx = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid] == x){
            ansIdx = mid;
            high = mid-1; // Coz find the next one to the left
        } else if(nums[mid] > x){
            high = mid-1;
        } else {
            low = mid + 1;
        }
    }

    return ansIdx;
}
int lastOccurance(vector<int> &nums, int x){
    int low = 0, high = nums.size()-1, ansIdx = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid] == x){
            ansIdx = mid;
            low = mid + 1; // To find the next one to the right
        } else if(nums[mid] > x){
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }

    return ansIdx;
}
vector<int> searchRange(vector<int>& nums, int target) {

    int first = firstOccurance(nums, target);
    if(first == -1) return {-1, -1};
    int last = lastOccurance(nums, target);
    return {first, last};
}

int main(){
    
    return 0;
}