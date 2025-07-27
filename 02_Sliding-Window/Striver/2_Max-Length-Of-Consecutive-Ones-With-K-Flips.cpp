// Question: https://leetcode.com/problems/max-consecutive-ones-iii/

#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int i=0, j=0, n=nums.size(), currK=0, ans=0;

    while(j<n){
        if(nums[j] == 0){
            if(currK < k){
                ++currK;
            }else{
                while(nums[i] != 0){
                    ++i;
                }
                ++i;
            }
        }
        ans = max(ans, j-i+1);
        ++j;
    }

    return ans;
}

int main(){
    
    return 0;
}