// https://leetcode.com/problems/longest-palindromic-substring/description/

// Brute Force
// We find all the substrings in O(n^2) complexity.
// Then for each substring, we try to check if its a palindrome or not.
// Time: O(n^3)
// Extra Space: O(1)

// Better
// Assume each character is center of a palindrome. And expand outwards as long as characters are same on each side.
// Time: O(n^2)
// ExtraSpace: O(1) 



#include <bits/stdc++.h>
using namespace std;

int findPalindromeLength_bruteForce(string &s, int i, int j) {
    int mid = (i+j)/2;
    for(int k=i; k<=mid; ++k){
        if(s[k] != s[j-k+i]){
            return 0;
        }
    }
    return j-i+1;
}
string longestPalindrome_bruteForce(string s) {
    int n = s.length(), maxLen = 0;
    int startIdx, endIdx;
    for(int i=0; i<n; ++i){
        for(int j=i; j<n; ++j){
            int palindromeLenOfSubstring = findPalindromeLength_bruteForce(s, i, j);
            if(palindromeLenOfSubstring > maxLen) {
                maxLen = palindromeLenOfSubstring;
                startIdx = i;
                endIdx = j;
            }
        }
    }
    return s.substr(startIdx, endIdx-startIdx+1);
}


void findLengthOfPalindrome_better(string &s, int &start, int &end, int i, int &maxLen, bool isOddPalindrome){
    int n = s.length();
    int left = isOddPalindrome ? i-1 : i;
    int right = i+1;
    while(left>=0 && right<n && s[left] == s[right]){
        if (right-left+1 > maxLen) {
            maxLen = right-left+1;
            start = left; end=right;
        }
        --left; ++right;
    }
}
string longestPalindrome_better(string s) {
    int n = s.length(), maxLen=1;
    int start=0,end=0;
    for(int i=0; i<n; ++i){
        // find even length palindrome
        findLengthOfPalindrome_better(s, start, end, i, maxLen, false);
        // find odd length palindrome
        findLengthOfPalindrome_better(s, start, end, i, maxLen, true);
    }
    return s.substr(start, end-start+1);
}

// Optimal : Manacher's Algo
// https://www.youtube.com/watch?v=8rNwx0tqCEY [start from 35-th minute]
// Why time complexity is linear?
// Because, in the worst case when we do brute force expansion of r. Then until we cross the boundary 'r', we don't do any expansions.
// Ultimately, we stop when r has reached 'n'. i.e. the size of modified string.
// Time: O(lengthOfTransformedString) = O(2n+1)
// Space: O(1)
string transform(string &s){
    string temp = "#";
    for(char ch:s){
        temp += ch;
        temp += '#';
    }
    return temp;
}
string longestPalindrome(string s) {
    string temp = transform(s);
    int n = temp.size();

    vector<int> p(n); p[0] = {0};
    int l=0, r=0, maxLen=1, centerOfMaxLen=0;

    for(int i=0; i<n; ++i){
        int left, right;
        if(i > r){
            left = i-1;
            right = i+1;
        } else {
            int j = l + (r-i); // 'j' is the mirror index of 'i'
            if(j-p[j] > l) {
                p[i] = p[j];
                continue;
            } else {
                left = i - (r-i);
                right = i + (r-i);
            }
        }

        while(left>=0 && right<n && temp[left] == temp[right]){
            --left;
            ++right;
        }
        ++left; --right;// as the last idx is a mismatch

        p[i] = i - left; // as we keep the center 'i' out of the expansion p[i]

        if(p[i] > maxLen){
            maxLen = p[i];
            centerOfMaxLen = i;
            l = i-p[i];
            r = i+p[i];
        }
    }

    return s.substr(centerOfMaxLen/2 - maxLen/2, maxLen);
}

int main(){
    
    return 0;
}