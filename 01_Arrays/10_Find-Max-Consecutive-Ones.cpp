// https://leetcode.com/problems/max-consecutive-ones/
// Optimal
// Time: O(n)
#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount = 0;
    int count = 0;
    for(int i=0; i<nums.size(); ++i){
        if(nums[i] != 1){
            count = 0;
        } else {
            ++count;
            maxCount = max(count, maxCount);
        }
    }
    return maxCount;
}

int main(){
    
    return 0;
}