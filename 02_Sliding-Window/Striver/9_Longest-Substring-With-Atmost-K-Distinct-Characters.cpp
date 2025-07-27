// Question: Find the largest subarray that contains K distinct characters.
// https://www.naukri.com/code360/problems/distinct-characters_2221410

// Optimal
// IMPORTANT: Please remove the character from the map, as soon as its count is Zero.
// Time: O(2n)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str){
    int i=0, j=0, n = str.length(), maxLen=0;
    unordered_map<char,int> mp;

    while(j<n){
        mp[str[j]]++;
        while(mp.size() > k){
            mp[str[i]]--;
            if(mp[str[i]] == 0) mp.erase(str[i]);
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