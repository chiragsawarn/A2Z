// Question: Convert Infix string to Prefix String
// Technique : -
// (1) Reverse Infix with inverted brackets.
// (2) Do infix to postfix {just like before} with inverted associativity rule in case of equal precedence.
//     In case of infix to postfix : -
//         If precedence[ch] == precedence[st.top()]
//              if Associativity[ch]   : Right to Left => Push
//              else Associativity[ch] : Left to Right => Pop
//     In our case : Infix to Prefix : -
//         If precedence[ch] == precedence[st.top()]
//              if Associativity[ch]   : Right to Left => _Pop_
//              else Associativity[ch] : Left to Right => _Push_
//
// (3) Reverse the answer string to get prefix answer string.

// Time: O(n/2) [reverse] + O(2n) [infix to postfix] + O(n/2) [reverse] => O(3n)
// Space: O(n) [stack] + O(n) [answer] => O(2n)

#include <bits/stdc++.h>
using namespace std;

void reverseWithBracketsInverted(string &str){
	int n = str.length();
	for(int i=0; i<n/2; ++i){
		if(str[i] == '(') str[i] = ')';
		if(str[n-i-1] == '(') str[n-i-1] = ')';
		if(str[i] == ')') str[i] = '(';
		if(str[n-i-1] == ')') str[n-i-1] = '(';
		swap(str[i], str[n-i-1]);
	}
}

string infixToPrefix(string exp){
	unordered_map<char,int> precedence = {{'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
	stack<char> st;
	string ans = "";

	reverseWithBracketsInverted(exp);

	for(int i=0; i<exp.length(); ++i){
		char ch = exp[i];

		if(isalnum(ch)){
			ans += ch;
		} else if(ch == '('){
			st.push(ch);
		} else if(ch == ')'){
			while(!st.empty() && st.top() != '('){
				ans += st.top();
				st.pop();
			}
			st.pop();
		} else {
			bool isAssociativityRightToLeft = ch == '^';
			while(!st.empty() && st.top() != '(' && ((precedence[st.top()] > precedence[ch]) || (precedence[st.top()] == precedence[ch] && isAssociativityRightToLeft))){
				ans += st.top();
				st.pop();
			}
			st.push(ch);
		}
	}
	while(!st.empty()){
		ans += st.top();
		st.pop();
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

int main(){
    
    return 0;
}