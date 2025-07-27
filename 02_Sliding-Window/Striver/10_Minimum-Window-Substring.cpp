// Question: Given 2 strings s and t.
//           Find the minimum substring in s, that has all the characters of t.
//           Note: If a character occurs twice in t, then it should appear twice in the substring of s.
// https://leetcode.com/problems/minimum-window-substring/

// Optimal
// Keep a map of the char count of t.
// The size of this map indicates the targetCount. 
// Lets also maintain a variable called currentCount, which indicates the no of characters from t with req count, that are in the window.
// When we iterate over the string s in a sliding window fashion, we decrease the count of anything we find and inject it into the map.
// This way, all the non characters of t -> will always have a non positive count.
// But when a character of t's count becomes zero => Then we increment the currentCount.
// Eventualy at a point, currentCount == targetCount
// while(currentCount == targetCount):
//      Since the conditions are met, we check if (j-i+1 < minLen) 
//          => Update minLen to current window size. also capture startIdx as i.
//      From here we should shrink the window.
//      When we shrink, we increment the count of the character that leaves in the map.
//      So all non characters of t can become 0 at max in the map.
//      but characters of t, will start to become positive.
//      As soon as a character of t becomes positive, we decrease the currentCount. And break out of the loop.
// One edge case is if there is no substring meeting the criteria. For which we have to return "".
// return (startIdx == -1) ? "" : s.substr(startIdx, minLen);

// Time: O(s+t)
// Space: O(52)  [Uppercase and lowercase english characters]

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> mp;
    for(char ch:t){
        mp[ch]++;
    }
    int targetCount = mp.size();
    int count = 0;
    int i=0, j=0, n=s.length();
    int minLen = INT_MAX;
    int startIdx=-1, stopIdx=-1;

    while(j<n){
        mp[s[j]]--;
        if(mp[s[j]] == 0){
            ++count;
        }
        while(count == targetCount){
            if(j-i+1 < minLen){
                minLen = j-i+1;
                startIdx = i;
                stopIdx = j;
            }
            mp[s[i]]++;
            if(mp[s[i]] > 0){
                --count;
            }
            ++i;
        }

        ++j;
    }

    return (startIdx == -1) ? "" : s.substr(startIdx, stopIdx-startIdx+1);
}

int main(){
    
    return 0;
}