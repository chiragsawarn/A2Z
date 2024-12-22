// https://leetcode.com/problems/missing-number/
// The array contains numbers betweeen 0-N where N is the size of the array. Except one number. Find that number.


// Brute Force
// for 0->n check if the number exists in the array or not.
// Time: O(n^2)

// Better
// Sort and do a linear search to check the bump in the array.
// Time: O(nlogn)

// Optimal
// missingNumber = expected_sum - actual_sum
// Where, expected_sum = (n*(n+1))/2
// Time: O(n)

// Better than Optimal
// missingNumber = expectedXor^actualXor
// Where expectedXor = 0^1^2^3^4 And actualXor = 0^1^3^4
// Implying, expectedXor^actualXor => Everything that occurs twice will cancel out... leaving us with the missing number.
// WHY IS IT BETTER THAN SUMMING?
// Because expected sum runs in n^2 and may be too large for interger limits.

#include <bits/stdc++.h>
using namespace std;

int missingNumber_usingSum(vector<int>& nums) {
    int n = nums.size();
    int actualSum = accumulate(nums.begin(), nums.end(), 0);
    int expectedSum = (n*(n+1))/2;
    return expectedSum - actualSum;
}

int missingNumber_usingXor(vector<int>& nums) {
    int xorActual = 0, xorExpected = 0;
    for(int i=0; i<nums.size(); ++i){
        xorActual ^= nums[i];
        xorExpected ^= (i+1);
    }
    return xorActual^xorExpected;
}

int main(){
    
    return 0;
}