// Find the sum of beauty of all the substrings in a string.
// The beauty of a substring is calculated as => maxFreqOfAnElement - minFreqOfAnElement
// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

// Brute Force
// Use 2 loops to mark the start and end of all substrings. And a third loop to iterate over the substring.
// Then for each substring use a freqMap to find least and highest freq characters.
// Time: O(n^3)
// Space: O(n)

// Optimal
// Use 2 loops to find all the substrings with i as starting point.
// Use a freqMap to find least and highest freq character.
// Time: O(n^2)
// Space: O(n)

// Learning: Don't try to do it without a freqMap. i.e. By maintaing maxFreq, minFreq variables directly in the second loop. It doesn't work.
// Reason it doesn't work is: "aaa" => After first character minFreq is 1. 
// After second character: minFreq = min(minFreq, mp[s[j]]) = min(1, 2) = 1 // This is wrong. After second char, min freq should be 2.
// So instead of trying to maintain minFreq if we think of maintaining minFreqChar.
// Then we need to maintain all contenders of minFreqChar.
// Eg: "aabcb" => After processing "aabc" minFreqChar is b coz it came first.
// But after processing last remaining 'b' => minFreq = min(mp[minFreqChar], mp[s[j]]) => 2 // Which is wrong again. 'c' should have remained in consideration.
// This is why we Iterate over the while freqMap for each substring.

#include <bits/stdc++.h>
using namespace std;

int findBeautyInSubstring(unordered_map<char,int> &mp){
    int minVal=INT_MAX, maxVal=0;
    for(auto p:mp){
        minVal=min(minVal, p.second);
        maxVal=max(maxVal, p.second);
    }
    return maxVal-minVal;
}
int beautySum(string s) {
    int n =s.length(), beauty=0;
    for(int i=0; i<n; ++i){
        int minFreq = INT_MAX, maxFreq = 0;
        char minFreqEle = '#', maxFreqEle = '#';
        unordered_map<char,int> mp;
        for(int j=i; j<n; ++j){
            mp[s[j]]++;
            beauty += findBeautyInSubstring(mp);
        }
    }

    return beauty;
}

int main(){
    
    return 0;
}