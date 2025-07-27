// Question: Given a non negative number in form of a string. Also given an integer k.
//           We have to remove k digits from the number, to make it as small as possible.
//           Note: No number has leading zeroes, except "0".

// https://leetcode.com/problems/remove-k-digits/description/

// Brute Force
// If number = "2002100" and k = 3.
// Then, we try removing 200 => 2100 | 20 2 => 0100 | 20  1 => 0200 | ... so on
// Then the find the minimum amongst the resultant strings.
// Time: O(n!/(n-k)!) 

// Optimal : use a stack
// Note: There are 3 edge cases.
//       1) We might have remaining elements to be popped. If we encounter a partial monotonically increasing configuration in num.
//       Example: "123" and k = 2
//       Solution: To handle this scenario, write a new loop to pop out all the elements (from the end) until k==0.
//                => "123" ---(k=1)---> "12" ---(k=0)---> "1" ...Answer
//       2) Everything might get popped out if k == num.length(). 
//       Example: "123" and k = 3
//                => "123" ---(k=2)---> "12" ---(k=1)---> "1" ---(k=0)---> "" => "0" ...Answer
//       Solution: If ans becomes empty string then return "0";
//       3) We might have multiple leading zeros in our number.
//       Example: "10000001" and k=1
//                => "10000001" ---(k=0)---> "0000001" => "1" ...Answer
//       Solution: Sanitize the answer to remove leading zeroes before returning the answer.

// Time: O(3n)
// Space: O(2n)

#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;
    int n = num.size();

    for(int i=0; i<n; ++i){
        while(!st.empty() && st.top() > num[i] && k > 0){
            --k;
            st.pop();
        }

        st.push(num[i]);
    }

    while(!st.empty() && k--){
        st.pop();
    }

    string ans = "";
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    while(ans.length() > 0 && ans[ans.length()-1] == '0'){
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());

    return ans == "" ? "0" : ans;
}

int main(){
    
    return 0;
}