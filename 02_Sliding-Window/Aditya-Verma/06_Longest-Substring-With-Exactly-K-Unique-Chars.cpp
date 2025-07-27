// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

// Brute Force
// Find all the substrings. Do a freq count of each of those substrings. Then if k unique characters are found in the substring, then update maxLen.
// Time: O(n^2)
// Space: O(n)

// Optimal
// Sliding Window: Variable Sized
// Create an unordered_map {character, index}
// Store the last index of occurance of the character in the map. 
// Which means when we shrink the window, we don't remove the character unless it's the last occurace of this character.
// Time: O(n)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string &s, int k) {
    unordered_map<char,int> mp;
    
    int i=0, j=0;
    int n = s.length(), maxLen=-1;
    
    while(j<n){
        mp[s[j]] = j;
        while(mp.size() > k){
            if(mp[s[i]] == i){
                mp.erase(s[i]);
            }
            ++i;
        }
        if(mp.size() == k){
            maxLen = max(maxLen, j-i+1);
        }
        ++j;
    }
    
    return maxLen;
}

int main(){
    
    return 0;
}