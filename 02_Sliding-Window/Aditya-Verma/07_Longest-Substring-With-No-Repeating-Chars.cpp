// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Brute Force
// Find all substrings. Do a frequncy count for each substring to see it there are no repeating characters. If so, update maxLen.
// Time: O(n^3)

// Optimized
// Sliding Window: Variable Sized
// Concept 1: Use "j-i+1" as K. As k is missing.
//            If window size exceeds map size: We have found a repeating character. Coz the map only contains unique characters.
// Concept 2: To identify the duplicate.
//            All mp[s[i]] == i, except the duplicate where mp[s[i]] = j. We use this to avoid deleting the duplicate.
//            We dont delete the duplicate from the map. We only skip over it with "++i".
// Time: O(n)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> mp;
    int i=0,j=0,n=s.length(),maxLen=0;

    while(j<n){
        mp[s[j]] = j;

        
        while(mp.size() < j-i+1){
            if(i == mp[s[i]]){ // mp[s[i]] is 'i' for all. Except for the duplicate, for which it is 'j'
                mp.erase(s[i]);
            }
            ++i;
        }

        if(mp.size() == j-i+1) {
            maxLen = max(maxLen, j-i+1);
        }
        ++j;
    }

    return maxLen;
}

int lengthOfLongestSubstring_intutive(string s) {
    unordered_map<char,int> mp;
    int i=0,j=0,n=s.length(),maxLen=0;

    while(j<n){
        if(mp.find(s[j]) == mp.end()){
            mp[s[j]] = j;
        } else {
            // we have found a repeating character.
            while(i <= mp[s[j]]){
                mp.erase(s[i]);
                ++i;
            }
            mp[s[j]] = j;
        }
        maxLen = max(maxLen, j-i+1);
        ++j;
    }

    return maxLen;
}

int main(){
    
    return 0;
}