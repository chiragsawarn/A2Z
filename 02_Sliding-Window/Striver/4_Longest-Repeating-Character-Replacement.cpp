// Question: Given a string of only Uppercase english characters. And a number k.
//           You can do at max k operations, to turn any character to any other character.
//           Find the maximum length of window you can make with the same character.
// https://leetcode.com/problems/longest-repeating-character-replacement/

// Optimal
// Create a hashmap of size 26.
// Find the highestFrequencyCount from this map, whenever a character is added.
// if (windowSize-highestFrequencyCount > k) => time to shrink window
// Note: highestFrequencyCount is not bound to any particular character.

// Time: O(n)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int i=0, j=0, n = s.length();
    unordered_map<char,int> mp;
    int maxCount = 1;
    int maxLen = 1;

    while(j<n){
        mp[s[j]]++;
        maxCount = max(maxCount, mp[s[j]]);
        if(j-i+1 - maxCount > k){
            mp[s[i]]--;
            ++i;
        }
        maxLen = max(maxLen, j-i+1);
        ++j;
    }

    return maxLen;
}

int main(){
    
    return 0;
}