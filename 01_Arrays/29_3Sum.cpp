// https://leetcode.com/problems/3sum/description/
// Return *all* unique tripplets that sum to 0.
// Note: Solution array must not contain duplicate tripplets.

// Brute Force
// DO NOT!!! Create a set out of given array. You can use an element twice in a tripplet if it occurs twice in the array.
// Iterate over the set using 3 pointers: i,j,k to find all the tripplets that sum to zero.
// Sort the found tripplet in an orderedSet or stringify it and store it in unordered_set.
// Time: O(n^3)
// Extra Space: O(no of unqique tripplets) [unordered set] => O(n)

// Better
// Iterate over the array. Assume each nums[i] element is part of the solution.
// Then apply the standard 2 sum's searching in visited array if -(nums[i] + nums[j]) exists or not.
// Note: The visited array should actually be a map containing {visitedElement, index} so that we can compare indexOfVisitedElement is not same as i or j
//       OR, you can use an unordered_set and just push the elements between i & j in it, so that you are already sure if -(nums[i] + nums[j]) exists, its not on i or j.
// Time: O(n^2)
// ExtraSpace: O(n) [For visited unordered_map 2sum] + O(n) [For making sure found tripplets are unique] => O(2n)

// Optimal
// NOTE: Everything we do from here on, is just to get rid of the extra space we need to find wheter found tripplet is unique or not.
// Sort the array. And use 3 pointers: i,j,k. Not j and k are the real movers here. i is from the parent nested loop.
// if(nums[i] + nums[j] + nums[k]) > 0 ==> It means bring down the total! So move k downstairs.
// else if(nums[i] + nums[j] + nums[k]) < 0 => Move j upstairs.
// else (nums[i] + nums[j] + nums[k]) == 0 => Store tripplet. Move up j AND move down k.
// Time: O(nlogn + n^2)
// ExtraSpace: O(1) [To return found tripplets as answer]

// Common Mistake: While writing the while loops, add "j<k checks" so pointers don't step out of bound of the array.
// Pointers: j,k only need to skip over duplicates, when tripplet is found. So that duplicate tripplet is not found. But not i.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for(int i=0; i<n-2;){
        int j = i+1;
        int k = n-1;

        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0){
                ++j;
            } else if(sum > 0){
                --k;
            } else {
                res.push_back({nums[i], nums[j], nums[k]});
                int currentJ = nums[j];
                int currentK = nums[k];
                while(j<k && nums[j] == currentJ) ++j;
                while(j<k && nums[k] == currentK) --k;
            }
        }

        int currentI = nums[i];
        while(i<n && nums[i] == currentI) ++i;
    }

    return res;
}

int main(){
    
    return 0;
}