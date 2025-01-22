// Given a bunch of strings, find their longest common prefix.
#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Sort the whole array of strings.
// Then compare the first and last string to find the longest common prefix.
// Time: O(n*mlog(n*m))
// Space: O(m) [To return answer]
// n-> no of strings, m-> length of smallest string.

string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(), strs.end()); 
    string &s1 = strs[0];
    string &s2 = strs[strs.size()-1];

    if(s2.length() < s1.length()){
        swap(s1, s2);
    }

    string res = "";
    for(int i=0; i<s1.length(); ++i){
        if(s1[i] == s2[i]){
            res += s1[i];
        }else {
            return res;
        }
    }
    return res;
}

// Optimal
// While iterating over first string's characters
//      In a nested loop, Iterate over the string array to match the character at same index if it exists.
//      The only quirk here, is that a string's length might be lower that strs[0]. If that happens, we end the longestSubstring calulation.
// Time: O(n*m)
// Space: O(m)
// n-> No of string, m-> Length of smallest string.

string longestCommonPrefix(vector<string>& strs) {
    string res = "";
    for(int i=0; i<strs[0].length(); ++i){
        for(int j=1; j<strs.size(); ++j){
            if(strs[j].length() == i || strs[j][i] != strs[0][i]){
                return res;
            }
        }
        res += strs[0][i];
    }

    return res;
}

int main(){
    
    return 0;
}