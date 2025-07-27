// Question : Convert Postfix to Infix
// https://www.naukri.com/code360/problems/postfix-to-infix_8382386?leftPanelTabValue=PROBLEM

// Operand found : Push into stack
// Operator found : Pull out top 2 element from stack add the operator between them, and enclose with brackets. Then add to the infix answer string.

// Time: O(n) [iterating over postfix] + O(1) [concatenating string]
// Space: O(n) [stack] + O(n) [answer string]

// Learning : How to create a string out of a character
// string s = string(1, ch);
// 1 is the number of times character 'ch' should be repeated in the string.

#include <bits/stdc++.h>
using namespace std;

string postToInfix(string postfix) {
    stack<string> st;

    for(int i=0; i<postfix.length(); ++i){
        char ch = postfix[i];

        if(isalnum(ch)){
            st.push(string(1,ch));
        } else {
            string val2 = st.top();
            st.pop();
            string val1 = st.top();
            st.pop();

            string val = '(' + val1 + ch + val2 + ')';
            st.push(val);
        }
    }

    return st.top();
}

int main(){
    
    return 0;
}