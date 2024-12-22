// https://leetcode.com/problems/single-number/

// Brute Force
// Sort the array and the "single element" won't have itself as a neighbour.
// Time: O(nlogn)
// Space: O(1)

// Better
// Store the count in an unordered_map, "single element" will have count of 1
// Time: O(n)
// Space: O(n)

// Best
// Xor them all
// Time: O(n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int xorOfAll = 0;
    for(int i=0; i<nums.size(); ++i){
        xorOfAll ^= nums[i];
    }

    return xorOfAll;
}

int main(){
    
    return 0;
}