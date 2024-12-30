// Given an array with prices of stock on i-th day
// Find the max profit you can make buying any day and selling in the future.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Brute Force
// For each day, consider all future days as selling days.
// This will give you all legal buy sell combos, choose the maximum you get as answer.
// Time: O(n^2)
// Space: O(1)

// Optimal
// Keep track of left minimum. 
// Time: O(n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int leftMinimum = prices[0];
    int maxProfit = INT_MIN;
    for(int i=0; i<prices.size(); ++i){
        leftMinimum = min(leftMinimum, prices[i]);
        maxProfit = max(maxProfit, prices[i]-leftMinimum);
    }

    return maxProfit;
}

int main(){
    
    return 0;
}