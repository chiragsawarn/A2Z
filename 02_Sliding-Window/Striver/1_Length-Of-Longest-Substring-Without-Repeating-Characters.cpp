// Question: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int i=0,j=0,n=s.length();
    unordered_set<char> st;
    int ans = 0;

    while(j<n){
        while(st.find(s[j]) != st.end()){
            st.erase(s[i]);
            ++i;
        }
        ans = max(ans, j-i+1);
        st.insert(s[j]);
        ++j;
    }

    return ans;
}

int main(){
    
    return 0;
}