// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

// Brute Force
// Do a linear answer search from 1->max_element
// In a nested loop do the divisions to see if the result that comes from it is lesser than threshold.
// Time: O(n^2)
// Space: O(1)

// Optimal
// Do a binary search to find the divisor.
// Time: O(nlogn)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int myCeil(int a, int b){
    return (a+b-1)/b;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int high = *max_element(nums.begin(), nums.end());
    int low = 1;

    while(low <= high){
        int mid = low + (high-low)/2;
        long result = 0;
        for(int i=0; i<nums.size(); ++i){
            result += myCeil(nums[i], mid); 
        }
        if(result <= threshold){
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