// https://leetcode.com/problems/remove-outermost-parentheses/
// Input: s = "(()())(())" 
// Processing s => "(()())" + "(())" {2 primitive strings}
//              => "()()" + "()" {2 primitive strings with outer brackets removed}
// Output: "()()()"

// Optimal
// Keep track of openParenthesisCount
//      decrement it when you find a closing parentesis.
// Don't push '(' into res array when (after processing current ch) openCount is 1. => Coz its the first open brace.
// Don't push ')' into res array when (after processing current ch) openCount is 0. => Coz its the last closing brace.
// Time: O(n)
// Space: O(n) [To return answer]

#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    int openCount = 0;
    string res = "";
    for(char ch:s){
        if(ch == '(') {
            ++openCount;
            if(openCount > 1){
                // After processing the first '(' openCount is 1.
                // With openCount > 1 => We avoid pushing this outer bracket into res.
                res.push_back(ch);
            }
        } else {
            --openCount;
            if(openCount > 0){
                // After processing the last ')' openCount is 0.
                // With openCount > 0 => We avoid pushing this last out bracket into res.
                res.push_back(ch);
            }
        }
    }
    return res;
}

int main(){
    
    return 0;
}