// https://leetcode.com/problems/maximum-subarray/description/
// Return the sum of the subarray with maximum sum.

// Brute Force
// [-2,1,-3,4,-1,2,1,-5,4]
// Position start,end. Then run a loop from start to end to calulate sum of each subarray.
// Time: O(n^3)
// Space: O(1)

// Better
// As end moves away from start in each iteration. Lets skip the innermost loop running from start to end, to calculate sum of subarray.
// Instead, we keep summing end as it is moving away.
// Intutively: We are finding sum of all subarrays that start at startIndex.
// Time: O(n^2)
// Space: O(1)

// Optimal
// Use kadane's algo.
// We iterate from left to right summing each element.
// If the leftSubarray's sum becomes negative, then it won't contribute to max sum. Hence we start with fresh sum.
// NOTE: If subarray is entirely negative, our maxSum is what we take at the start which is 0 i.e. or empty subarray.
//       But if the question doesn't accept zero, then we must also keep track of the maxNegative element and return that in this case.
// Time: O(n)
// Space: O(1)
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxNeg = INT_MIN;
    int sum = 0, ans = 0;
    bool isArrayEntirelyNegative = true;

    for(auto val:nums){
        sum += val;
        if(sum <= 0){
            sum = 0;
        } else {
            isArrayEntirelyNegative = false;
            ans = max(ans, sum);
        }
        maxNeg = max(val, maxNeg);
    }

    return isArrayEntirelyNegative ? maxNeg : ans;
}

int main(){
    
    return 0;
}