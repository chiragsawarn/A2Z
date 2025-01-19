// https://leetcode.com/problems/split-array-largest-sum/description/

// Brute Force
// 

// Optimal
// Ditto question as assign n books to m students such that each gets one atleast.
// All difficulty lies with writing canSplitIntoKSubarraysWithGivenCapacity
// In this note that we keep countOfSubarrays as 1 initial.
//      => We do this coz if we are summing and we never reach capacity, then we need to increase the count at the end, lets do it at the start for cleaner implementation.
//      => Even if we reach the capacity a few times but not for the last few elements. Then also we need to do a sum increase in the end, this increment handles that as well.

#include <bits/stdc++.h>
using namespace std;

bool canSplitIntoKSubarraysWithGivenCapacity(vector<int>& nums, int k, int capacity){
    int countOfSubarrays=1, sum = 0;
    for(int i=0; i<nums.size(); ++i){
        if(nums[i] > capacity) return false;
        if(nums[i] + sum <= capacity){
            sum += nums[i];
        } else {
            sum = nums[i];
            ++countOfSubarrays;
        }
    }

    return countOfSubarrays > k; // Then k splits are enough to cover with given capacity.
}
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(),0);

    while(low<=high){
        int mid = (low+high)/2;
        if(canSplitIntoKSubarraysWithGivenCapacity(nums, k, mid)){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main(){
    
    return 0;
}