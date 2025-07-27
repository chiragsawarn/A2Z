// Question : Prefix to Infix 
// https://www.naukri.com/code360/problems/prefix-to-infix_1215000?leftPanelTabValue=PROBLEM

// Traverse the prefix expression right to left.
// Pull out 2 operands from stack. Conjoin then with operator in between and add to the answer.
// Note: order of val1 and val2 is important as we iterate from right->left.

// Time: O(n)
// Space: O(2n)

#include <bits/stdc++.h>
using namespace std;

string prefixToInfixConversion(string &s){
	stack<string> st;
	int n = s.length();

	for(int i=n-1; i>=0; --i){
		char ch = s[i];
		if(isalnum(ch)){
			st.push(string(1, ch));
		} else {
			string val1 = st.top();
			st.pop();
			string val2 = st.top();
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