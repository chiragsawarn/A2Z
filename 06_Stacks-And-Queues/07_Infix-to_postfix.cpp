// Question: Convert Infix to Postfix
// https://www.naukri.com/code360/problems/infix-to-postfix_1382146?leftPanelTabValue=PROBLEM

// What is infix : (a+b)^c
// What is postfix : ab+c^

// Rules for converting infix to postfix using a stack: -
// Iterate over all the infix characters (ch)
//    if ch == '(' => push into stack
//    else if ch is an operand (0-9 | a-z | A-Z) => add to ans string
//    else if ch == ')' => pop all stack elements into answer, until  stack top is '(', then pop '(' too
//    else if ch is an operator => 
//            (1) precedence[st.top()] > precedence[ch]  => Pop st.top() and Add it into the ans string. 
//            (2) precedence[st.top()] == precedence[ch] => Check Associativity
//                (2.1) If ch == '^'   => Associativity is Right to Left. So, push the element to the stack. [Performed when loop end automatically]
//			      (2.2) Else ch != '^' => Associativity is Left to Right. So, pop the element from stack. Add it to ans string. And check next.
//            (3) Push ch into the stack.
// 1) Precedence order -> ^:3, *:2, /:2, +:1, -:1
// 2) Stack stores elements in highes precedence order from bottom to top.

// Time complexity : O(n) [iterating infix string] + O(n) [popping elements from stack] => O(2*n)
// Space complexity: O(n) [stack] + O(n) [ans string]

#include <bits/stdc++.h>
using namespace std;

string infixToPostfix(string exp){
	unordered_map<char,int> precedence = {{'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
	stack<char> st;
	string ans = "";

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
			while(!st.empty() && st.top() != '(' && ((precedence[st.top()] > precedence[ch]) || (precedence[st.top()] == precedence[ch] && !isAssociativityRightToLeft))){
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

	return ans;
}

int main(){
    
    return 0;
}