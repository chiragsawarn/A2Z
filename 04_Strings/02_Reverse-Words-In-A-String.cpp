// Reverse the words in a string. Return them in a single-space-seperated manner.
// https://leetcode.com/problems/reverse-words-in-a-string/description/
// Example 1
// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2
// Input: s = "  hello world  "
// Output: "world hello"

// Brute Force
// Conver the string into a stringstream object. Then iterate over it to find words.
// Push these words into an array of tokens.
// Then form a result array by concatenating tokens in reverse.
// Time: O(n) [To form stringstream] + O(n) [Iterate over stringstream to make tokens] + O(n) [To form result string from tokensArray]
// Space: O(n) [For stringstream] + O(n) [For tokens Array] + O(n) [res array]

// Optimal
// Iterate over input array in reverse.
// Step 1: Skip trailing spaces. (ONE TIME! Only needed before last word)
// Step 2: Skip the word. (As we dont want to push back word in reverse)
// Step 3: Iterate over the word again to push it in res. 
// Step 4: Skip leading spaces.
// Step 5: Seperate words by adding a space in res.
// Time: O(2n)
// Space : O(n) [res array]

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    string res = "";
    int len = s.length();
    int j=0, i=len-1;
    // Skip trailing spaces
    while(i>=0 && s[i] == ' ') --i;

    while(i>=0){
        // Skip the word
        while(i>=0 && s[i] != ' ') --i;

        // Push the word
        j=i+1;
        while(j<len && s[j] != ' ') {
            res.push_back(s[j]);
            ++j;
        }

        // Skip leading spaces
        while(i>=0 && s[i] == ' ') --i;
        
        // Seperate words
        res.push_back(' ');
    }

    // Remove space from end of the res array
    res.pop_back();

    return res;
}

int main(){
    
    return 0;
}