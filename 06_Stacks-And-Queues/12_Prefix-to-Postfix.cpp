// Question : Prefix to Postfix
// https://www.naukri.com/code360/problems/convert-prefix-to-postfix_8391014

#include <bits/stdc++.h>
using namespace std;

string preToPost(string s) {
    stack<string> st;

    for(int i=s.length()-1; i>=0; --i){
        char ch = s[i];
        if(isalnum(ch)){
            st.push(string(1, ch));
        } else {
            string val1 = st.top();
            st.pop();
            string val2 = st.top();
            st.pop();
            string val = val1 + val2 + ch;
            st.push(val);
        }
    }

    return st.top();
}

int main(){
    
    return 0;
}