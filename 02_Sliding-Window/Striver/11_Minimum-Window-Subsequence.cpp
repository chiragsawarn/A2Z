// Question: Given two strings S and T
//           Find a substring of S that is a subsequence of T.
//           i.e. it should have all the characters of T in the same order as T, but may be spaced out by filler characters.
// Example: S = "dynamicprogramming" T="mm"
// => Subsequence1: "micprogram" [It has the two m - m spaced out by filler characters]
// => Subsequence2: "mm" {Comes from progra`mm`ing}
// "mm" is the shorter subsequence hence thats our answer.

// Optimized bruteforce
// Time: O(n^2)
// 1) We traverse from left to right to find all characters of T in S: if(S[j] == T[i]) => i++.
//    When we finish traversing T, we have found the endIdx to our subsequence.
// 2) Now we traverse right to left, to find all the characters of T in S again.
//    We are doing this to minimize the length of our subsequence. 
//    When we finish traversing T, we have found the startIdx to our subsequence.
// 3) Using (1) and (2) you will find a contender subsequence. This is still not a guaranteed minimum.
//    To find the next subsequence, we iterate on S again. This time starting from `j` = startIdx+1, 
//    (NOTE: We don't do j=endIdx+1 because subsequences can be partially overlapping.)
//    We keep doing this until startIdx+1 >= S.length()

#include <bits/stdc++.h>
using namespace std;

pair<int, int> helper(const string &S, const string &T, int start) {
    int i = 0, j = start;
    int nS = S.length(), nT = T.length();
    int endIdx = -1, startIdx = -1;

    // Forward
    while (j < nS) {
        if (S[j] == T[i]) {
            if (i == nT - 1) {
                endIdx = j;
                break;
            }
            ++i;
        }
        ++j;
    }

    if (endIdx == -1) return {-1, -1};

    // Backward
    i = nT - 1;
    j = endIdx;
    while (j >= start) {
        if (S[j] == T[i]) {
            if (i == 0) {
                startIdx = j;
                break;
            }
            --i;
        }
        --j;
    }

    return {startIdx, endIdx};
}

string minWindow(string S, string T) {
    int minLen = INT_MAX;
    int resStart = -1;

    int nextStart = 0;
    while (nextStart < S.length()) {
        auto p = helper(S, T, nextStart);
        if (p.first == -1) break;
        if (p.second - p.first + 1 < minLen) {
            minLen = p.second - p.first + 1;
            resStart = p.first;
        }
        nextStart = p.first + 1;  // move past current window's start
    }

    return (resStart == -1) ? "" : S.substr(resStart, minLen);
}

int main(){
    
    return 0;
}