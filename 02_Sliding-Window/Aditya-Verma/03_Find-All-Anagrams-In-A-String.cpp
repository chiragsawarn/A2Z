// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

// Brute Force
// Convert string p into a freqency map.
// if all the characters in the map turned to zero for a substring, then we have found an anagram.
// for each subsstring check if each char in the freq map turned to zero.
// Time: O(n^2) [find all substrings] x O(n) [Iterate over map to see if each char's freq turned to zero] + O(n) [Forming freq map]
// Time: O(n^3 + n)
// Space: O(n)

// Better
// Use a fixed size window of p.length()
// If this window length turned the freq count for each char to zero. Then we have found an anagram.
// But once freq goes to zero, how do we restore it?
// Ans. Case 1: If freq never goes to zero. => No anagrams found. No need to restore freq map.
//      Case 2: If freq only goes to zero once => 1 anagram found. No need to restore freq map.
//      Case 3: If freq goes to zero more than once => 1 anagram found. Freq map becomes empty. 
//              Then character freqencies are restored from the window that formed the anagram just now.
//              When characters exit the window, they restore the original freq for a new anagram to be found.
//              Even if the freq are restored partially, and then becomes zero again. That means we found a new anagram by reusing are preprocessed calculations from last window.
// Time: O(n) [For sliding window] x O(n) [To iterate over map to see if all frequencies became zero when window hits k] + O(n) [Forming freq map]
// Space: O(n) [for freq map]

// Optimal
// Same as above. Except, we dont iterate over map to see if all frequencies became zero when window hits k.
// if(mp[ch]: 1-->0) => count--;
// if(mp[ch]: 0-->1) => count++;
// when window hits k => if(count == 0): All char's freq have turned to zero. And we have found an anagram.
// Time: O(n) [for sliding window over s] + O(n) [Forming freq map]
// Space: O(n) [for freq map]
#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    unordered_map<char,int> mp;
    for(char ch:p) ++mp[ch];

    vector<int> res;
    int i=0, j=0;
    int n=s.length(), count=mp.size(), k=p.length();

    while(j<n){
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if(mp[s[j]] == 0) --count;
        }
        while(j-i+1 > k){
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]]++;
                if(mp[s[i]] == 1) ++count;
            }
            ++i;
        }
        if(j-i+1 == k){
            if(count == 0){
                res.push_back(i);
            }
        }
        ++j;
    }

    return res;
}

int main(){
    
}

