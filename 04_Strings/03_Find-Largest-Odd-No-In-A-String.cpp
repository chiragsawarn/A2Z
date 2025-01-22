// https://leetcode.com/problems/largest-odd-number-in-string/description/
// Input1: num = "52"
// Output1: "5"
// Input2: num = "4206"
// Output2: ""
// Input3: num = "35427"
// Output3: "35427"

// Optimal
// Iterate from back to front and find the first odd index.
// Then return the whole string from start till this index.
// Use the substr fn: substr(startingIdx, noOfElements)
// Time: O(n)
// Space: O(n) [Just to return answer]

#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    for(int i=num.length()-1; i>=0; --i){
        int digit = num[i]-'0';
        if(digit&1){
            return num.substr(0, i+1);
        }
    }
    return "";
}

int main(){
    
    return 0;
}