// Question: given a binary subarray, find the no of subarrays with sum k
// https://leetcode.com/problems/binary-subarrays-with-sum/

#include <bits/stdc++.h>
using namespace std;

// Optimal Time: Use a hashmap
// Time: O(n)
// Space: O(n)

int numSubarraysWithSum_withHashMap(vector<int>& nums, int goal) {
    unordered_map<int,int> mp = {{0,1}}; // {prefixSum, numOfWaysToAttainIt}
    int prefixSum = 0, ans = 0;

    for(int i=0; i<nums.size(); ++i){
        prefixSum += nums[i];
        int x = prefixSum - goal;

        if(mp.find(x) != mp.end()){
            ans += mp[x];
        }

        mp[prefixSum]++;
    }

    return ans;
}

// Optimal Space: 
// Using CountOfSubarraysWithSum(<= k) - CountOfSubarraysWithSum(<= k-1) 
// => Count of subarrays with sum k
// Time: O(4n)
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

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int x = findNumOfSubarraysWithLessThanEqualToKOddElements(nums, goal);
    int y = findNumOfSubarraysWithLessThanEqualToKOddElements(nums, goal-1);

    return x-y;
}

int main(){
    
    return 0;
}