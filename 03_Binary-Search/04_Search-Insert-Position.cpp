// https://leetcode.com/problems/search-insert-position/

// Brute Force : linear search
// Time: O(n)

// Optimal : Binary Search
// Time: O(logn)


#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    auto itr = lower_bound(nums.begin(), nums.end(), target);
    return itr - nums.begin();
}

int main(){
    
    return 0;
}