// https://leetcode.com/problems/rearrange-array-elements-by-sign/
// Maintaining the order of elements, rearrange the array such that pos and neg elements are positioned in alternating manner.

// Brute Force
// See the index is even or odd.
// If index is even slide in first positive you find towards the right
// If index is odd, slide in the first negative you find towards the right.
// Time: O(n^2)
// Space: O(1)

// Better [Actually best, as it covers more scenarios]
// Take two auxillary arrays: positiveArray and negativeArray
// Push items from original into these in first pass, then push items back into the original in second pass.
// NOTE: This approach will help solve the version of this question in which noOfPositiveElements and noOfNegativeElements in the original array might be unequal.
// Time: O(2n)
// Space: O(n)

// Optimal
// Take a single auxillary array. And two pointers pos and neg
// Iterate over original array, when item is positive => push it in auxArr[pos+2], else push it in auxArr[neg+2]
// Time: O(n)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size(), pos = -2, neg = -1;
    vector<int> res(n);
    
    for(int i=0; i<n; ++i){
        if(nums[i] < 0){
            neg += 2;
            res[neg] = nums[i];
        } else {
            pos += 2;
            res[pos] += nums[i];
        }
    }

    return res;
}

int main(){
    
    return 0;
}