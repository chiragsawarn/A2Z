// https://leetcode.com/problems/minimum-window-substring/

// Brute Force
// Find the minimum window substring in s, which contains all the characters of t + 0 or more useless characters.

// Optimal
// Sliding Window: Variable Sized
// Create an unordered map out of the characters of string 't'
// If a char's frequncy < 0 => -2 or -1 => This means you have that char 2 or 1 extra times respectively.
// while(count == 0) => You can remove all these extra characters. Or characters that dont show up in the freq map.
//                      Each time you remove a character, you have a new contender for minimum len substring that has all characters of 't'.
//                      Hence we do answer calculation here itself.
// Time: O(n)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char,int> mp;
    for(auto ch:t){
        mp[ch]++;
    }

    int i=0,j=0,n=s.length(),count=mp.size();
    int start=-1, len=INT_MAX;

    while(j<n){
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if(mp[s[j]] == 0) --count;
        }
        while(count == 0){
            // Answer Calculation
            if(j-i+1 <= len){
                len = j-i+1;
                start = i;
            }
            // Shrinking
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]]++;
                if(mp[s[i]] == 1) ++count;
            }
            ++i;
        }
        ++j;
    }

    return (start == -1) ? "" : s.substr(start, len);
}

int main(){
    
    return 0;
}