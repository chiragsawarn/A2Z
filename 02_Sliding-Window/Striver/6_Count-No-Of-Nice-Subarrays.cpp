// Question: Count the no of subarrays with k odd integers
// https://leetcode.com/problems/count-number-of-nice-subarrays/

// Optimal : 
//   No of subarays with <= k odd elements
// - No of subarays with <= k-1 odd elements
// ____________________________________________
//   No of subarays with = k odd elements

#include <bits/stdc++.h>
using namespace std;

int findNumOfSubarraysWithLessThanEqualToKOddElements(vector<int>& nums, int k){
    if(k < 0) return 0;
    int i=0, j=0, n=nums.size();
    int countOfOddElements = 0, countOfSubarrays = 0;

    while(j<n){
        if(nums[j]&1){
            ++countOfOddElements;
            while(countOfOddElements > k){
                if(nums[i]&1){
                    --countOfOddElements;
                }
                ++i;
            }
        }
        countOfSubarrays += j-i+1;
        ++j;
    }
    return countOfSubarrays;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    int x = findNumOfSubarraysWithLessThanEqualToKOddElements(nums, k);
    int y = findNumOfSubarraysWithLessThanEqualToKOddElements(nums, k-1);

    return x-y;
}

int main(){
    
    return 0;
}