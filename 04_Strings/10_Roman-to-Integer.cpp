// https://leetcode.com/problems/roman-to-integer/description/
// Optimal
// When adjacent Roman numerals are in decreasing order: they subtract. 
// Else they always add up.
// Time: O(n)
// Space: O(1) [map we made is of very small constant size]

#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> mp= {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int total = 0;
    for(int i=0; i<s.length()-1; ++i){
        if(mp[s[i]] < mp[s[i+1]]){
            total -= mp[s[i]];
        } else {
            total += mp[s[i]];
        }
    }
    // last character remains undealt with
    total += mp[s[s.length()-1]];

    return total;
}

int main(){
    
    return 0;
}