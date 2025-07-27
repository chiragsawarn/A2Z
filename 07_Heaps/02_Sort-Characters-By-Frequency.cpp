// Question: Given a string, reorder the characters such that the character with most frequency comes first.
// Note: If two characters have same freqency then their order doesn't matter.
// https://leetcode.com/problems/sort-characters-by-frequency/

// Optimal
// Time: O(n) [freq map] + O(52log52) [Ordering based on freqency] + O(52log52 + n) [popping each element from heap and placing it in ans]
// Time : O(2n)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    unordered_map<char,int> mp;

    for(char ch:s){
        mp[ch]++;
    }

    priority_queue<pair<int,char>> pq;
    for(auto p:mp){
        pq.push({p.second, p.first});
    }

    string ans = "";
    while(!pq.empty()){
        auto p = pq.top();
        ans += string(p.first, p.second);
        pq.pop();
    }

    return ans;
}

int main(){
    
    return 0;
}