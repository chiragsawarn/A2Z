// https://leetcode.com/problems/string-to-integer-atoi/

// Optimal
// Step 1: Process all spaces.
// Step 2: Process the character if sign is there.
//         Set isNegative to true if '-' found.
// Step 3: Process all leading zeros. [Note: A zero is only a leading zero if it happens to after spaces & sign]
// Step 4: Process all [0-9] characters to build resultant number.
//         If while building resultant, it exceeds INT_MAX. Then return INT_MAX or INT_MIN. Depending on isNegative we had set earlier.
// Time: O(n)
// Space: O(1)

// STL : have stoi()
// It doesn't work on too large int. Or non digit characters. Or empty strings. [Hence we can't use it for this question]
// Here is how to use it.
// string largeNum = "9999999999999999999999"; 
// int result = stoi(largeNum); // This will throw std::out_of_range

#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    bool isNegative = false;
    int i=0, n=s.length();
    int ans = 0;

    while(i<n && s[i] == ' ') ++i;
    if(s[i] == '-'){
        isNegative = true;
        ++i;
    } else if(s[i] == '+'){
        ++i;
    }
    while(i<n && s[i] == '0') ++i;

    while(i<n && ('0' <= s[i] && s[i] <= '9')){
        int digit = s[i] - '0';
        long updatedAns = long(ans)*10 + digit;
        if(updatedAns > INT_MAX) {
            if(isNegative) return INT_MIN;
            return INT_MAX;
        }
        ans = updatedAns;
        ++i;
    }

    return isNegative ? -1*ans : ans;
}

int main(){
    
    return 0;
}