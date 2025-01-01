// Find *ALL* Majority elements that occur more than n/3 times.
// https://leetcode.com/problems/majority-element-ii/description/

// Maximum no of integers that can occur more than n/3 times is: floor(n/3)
// So in an array of 8, at max we may have 2 answers.

// Brute Force
// Iterate from left to right. Assume each element as the answer.
// Count how many times it appears in the array.
// If any element appears more than n/3 times then push it in the res array.
// Time: O(n^2)
// Space: O(1)

// Better
// Use a hashmap to store the count of unique elements. Whenever a count hits more than n/3. Push it in res array.
// Time: O(n)
// Space: O(n)

// Optimal

#include <bits/stdc++.h>
using namespace std;



int main(){
    
    return 0;
}