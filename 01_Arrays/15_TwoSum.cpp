// https://leetcode.com/problems/two-sum/

// Brute Force
// Lets nums[i] be a, for all nums[j] between i+1 to n-1 check if nums[j] == target - a.
// Time: O(n^2)
// Space: O(1)

// Better
// We can improve searching multiple times by sorting the array and using binary search instead of linear search.
// Time: O(nlogn)
// Space: O(1)

// Best
// Use unordered_set to check if the compliment element was found previously.
// Time: O(n)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for(int i=0; i<nums.size(); ++i){
        int b = target - nums[i];
        if(mp.find(b) != mp.end()){
            int idx = mp.find(b)->second;
            return {i, idx};
        }
        mp[nums[i]] = i;
    }

    return {};
}

int main(){
    
    return 0;
}