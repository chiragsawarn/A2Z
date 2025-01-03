// https://leetcode.com/problems/4sum/description/

// Brute Force
// Use 4 pointers, and 4 nested loops to find all quadriplets.
// Sort the quadriplet. Store it in an unordered_map as a string, to avoid duplicates.
// Time: O(n^4)
// ExtraSpace: O(n) [To store quadriplets in unordered_set to avoid duplicates]

// Better
// Use an unordered_set to reduce a loop. i.e. 2sum technique
// Take 3 pointers: i,j,k
// Push all items between j and k into the unordered_set to see if {target - (nums[i]+nums[j]+nums[k])} is available.
// If quadriplet found: push it into a set that stores uniqueQuadriplets.
// Time: O(n^3) + O(nlogn) [To store in set]
// ExtraSpace: O(n)

// Optimal
// Exactly like 3sum
// Time: O(n^3)
// ExtraSpace: O(1)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum_better(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> uniqueQuadriplets;

    for(int i=0; i<n-3; ++i){
        for(int j=i+1; j<n-2; ++j){
            unordered_set<int> st;
            for(int k=j+1; k<n; ++k){
                long x = long(target) - nums[i] - nums[j] - nums[k];
                bool isXinIntRange = x >= INT_MIN && x <= INT_MAX;
                if(isXinIntRange && st.find(x) != st.end()){
                    vector<int> quadriplet = {nums[i], nums[j], nums[k], int(x)};
                    sort(quadriplet.begin(), quadriplet.end());
                    uniqueQuadriplets.insert(quadriplet);
                }
                st.insert(nums[k]);
            }
        }
    }

    vector<vector<int>> res;
    for(auto quadriplet:uniqueQuadriplets){
        res.push_back(quadriplet);
    }

    return res;
}

vector<vector<int>> fourSum_optimal(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for(int i=0; i<n-3; ){
        for(int j=i+1; j<n-2; ){
            int k = j+1;
            int l = n-1;
            while(k < l){
                long sum = (long)nums[i] + nums[j] + nums[k] + nums[l];
                if(sum < target){
                    ++k;
                } else if(sum > target){
                    --l;
                } else {
                    res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    int currentL = nums[l];
                    int currentK = nums[k];
                    while(k<l && nums[l] == currentL) --l;
                    while(k<l && nums[k] == currentK) ++k;
                }
            }
            int currentJ = nums[j];
            while(j<n-2 && nums[j] == currentJ) ++j;
        }
        int currentI = nums[i];
        while(i<n-3 && nums[i] == currentI) ++i;
    }

    return res;
}

int main(){
    
    return 0;
}