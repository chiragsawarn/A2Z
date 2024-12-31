// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// Example : [100,4,200,1,3,2] => [1,2,3,4] so 4 is the length of longest consecutive sequence.
// https://leetcode.com/problems/longest-consecutive-sequence/description/

// Brute Force
// Sort the array. Then find the longest subarray with incrementally increasing elements.
// Time: O(nlogn) [To sort] + O(n) [To find longest subarray] => O(nlogn + n)
// Space: O(1)

// Optimal
// Find start of a sequence [Where element-1 DoesNotExist]. And increment count for everyelement that comes after it. Update maxCount = max(maxCount, count);
// Time: O(2n)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st;
    for(auto val:nums){
        st.insert(val);
    }

    int maxCount = 0;
    for(auto val:st){
        if(st.find(val-1) == st.end()){
            int count = 1;
            int nextVal = val+1;
            while(st.find(nextVal) != st.end()){
                ++count;
                st.erase(nextVal); //optional step : helps reduce time
                ++nextVal;
            }
            maxCount = max(maxCount, count);
        }
    }

    return maxCount;
}

int main(){
    
    return 0;
}