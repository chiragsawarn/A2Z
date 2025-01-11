// https://leetcode.com/problems/maximum-product-subarray/

// Brute Force
// Find all the subarrays
// Find their products.
// Return the maxProduct as answer.
// Time: O(n^3)
// Space: O(1)

// Better
// Find subarray and product at the same time.
// Eliminate the third loop.
// Approach: Find all subarray products that start with i
// Time: O(n^2)
// Space: O(1)

// Optimal
// Use observation to make cases:-
// (1) All positives => res is product of all.
// (2) Even Negative => res is product of all.
// (3) Odd Negatives => res is max(prefixProduct, suffixProduct) of the negative number being ignored.
//                      Note: Each negative no of ignored one by one.
// (4) Array contains zero => Zero is ignored. So max(prefixProduct, suffixProduct) still holds.
//                      But to ignore zero. Reset prefixProduct = 1, when it becomes zero. Same for suffixProduct.
// Time: O(n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int prefixProduct = 1, suffixProduct = 1;
    int maxProduct = INT_MIN, n = nums.size();

    for(int i=0; i<n; ++i){
        if(prefixProduct == 0) prefixProduct = 1;
        if(suffixProduct == 0) suffixProduct = 1;

        prefixProduct *= nums[i];
        suffixProduct *= nums[n-1-i];
        maxProduct = max(maxProduct,max(prefixProduct, suffixProduct));
    }

    return maxProduct;
}

int main(){
    
    return 0;
}