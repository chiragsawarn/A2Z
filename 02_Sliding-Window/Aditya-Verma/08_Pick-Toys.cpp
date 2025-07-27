// https://leetcode.com/problems/fruit-into-baskets/description/
// Question
// A kid wants to pick as many toys as possible.
// Toys are available in an array {A,A,A,B,B,C,C,C,C}
// His mom imposes 2 conditions for picking toys:-
// (1) Toys must be picked in a continuous manner. Like a subarray.
// (2) Toys selected at a time should at max be of 2 types.

// Brute Force
// Form all the subarrays. (O(n^2))
// For each subarray check if there are <= 2 types of toys in it. (O(n))
// Update the maxNoOfToys with the len of the subarrys that pass previous check.
// Time: O(n^2)
// Space: O(n) [A freq map to check the types of toys in the subarray]

// Optimal
// Sliding Window: Variable Sized
// Time: O(2n)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    unordered_map<int,int> mp;
    int i=0, j=0, n=fruits.size(), k=2, maxLen=0;

    while(j<n){
        mp[fruits[j]]++;
        while(mp.size() > k){
            mp[fruits[i]]--;
            if(mp[fruits[i]] == 0){
                mp.erase(fruits[i]);
            }
            ++i;
        }
        if(mp.size() <= k){
            maxLen = max(maxLen, j-i+1);
        }
        ++j;
    }

    return maxLen;
}

int main(){
    
    return 0;
}