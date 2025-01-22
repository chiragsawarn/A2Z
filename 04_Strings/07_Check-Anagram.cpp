// https://leetcode.com/problems/valid-anagram/description/

// Brute Force
// For each char in s1, eliminate first occurance of char in s2 if it exists, else return false.
// Time: O(n1*n2)
// Space: O(1)

// Optimal
// Store freq count of s1's characters. And decrement freq count when iterating over s2's characters.
// If at any time, count is 0 for a char in s2, return false.
// Time: O(n1 + n2)
// Space: O(n1)

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    int n1 = s.length(), n2 = t.length();
    if(n1 != n2) return false;

    unordered_map<char,int> mp;
    for(char ch:s){
        mp[ch]++;
    }

    for(char ch:t){
        if(mp.find(ch) == mp.end() || mp[ch] == 0) {
            return false;
        } 
        --mp[ch];
    }

    return true;
}

int main(){
    
    return 0;
}