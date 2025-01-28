// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
// Given a string s: Find the maximum nesting count of parenthesis.
// Example: -
// Input: s = "(1+(2*3)+((8)/4))+1"
// Output: 3

// Better  
// Use stack to keep track of open parenthesis
// Time: O(n)
// Space: O(n)

// Optimal
// Simply maintain count, as string has only one type of bracket and is guarenteed Valid Parenthesis String.
// Time: O(n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int maxDepth_usingStack(string s) {
    stack<char> st;
    int maxDepth=0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '(') st.push('(');
        else if(s[i] == ')') st.pop();

        maxDepth= max(int(st.size()), maxDepth);
    }
    return maxDepth;
}

int maxDepth(string s) {
    int maxCount = 0, count=0;
    for(char &ch:s){
        if(ch == '('){
            ++count;
            maxCount = max(maxCount, count);
        } else if(ch == ')'){
            --count;
        }
    }
    return maxCount;
}

int main(){
    
    return 0;
}