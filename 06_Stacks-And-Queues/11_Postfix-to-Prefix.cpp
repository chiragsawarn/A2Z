// Question : Postfix to Prefix
// https://www.naukri.com/code360/problems/postfix-to-prefix_1788455?leftPanelTabValue=PROBLEM


#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string &s){
    stack<string> st;
    
    for(char ch:s){
        if(isalnum(ch)){
            st.push(string(1,ch));
        } else {
            string val2 = st.top();
            st.pop();
            string val1 = st.top();
            st.pop();
            string val = ch + val1 + val2;
            st.push(val);
        }
    }

    return st.top();
}

int main(){
    
    return 0;
}