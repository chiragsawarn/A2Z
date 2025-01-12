// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

// Brute Force
// Iterate linearly. When you find target, start increasing count.
// Time: O(n)

// Better
// Find the element using Binary search.
// Then move to its left and right linearly to find its ends.
// Time: O(n) in worst case, but average case is better.

// Optimal
// Find the firstOccuranceIdx & lastOccuranceIdx. Then return the difference.
// Note: If firstOccurance is not found, then no need to find lastOccurance.
// Time: O(2*logn)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int countFreq(vector<int>& arr, int target) {
    auto lbItr = lower_bound(arr.begin(), arr.end(), target);
    int count = 0;
    if(lbItr != arr.end() && *lbItr == target) {
        auto ubItr = upper_bound(arr.begin(), arr.end(), target);
        count = ubItr - lbItr;
    }
    
    return count;
}

int main(){
    
    return 0;
}