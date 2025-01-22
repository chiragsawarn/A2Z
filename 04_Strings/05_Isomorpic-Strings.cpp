// https://leetcode.com/problems/isomorphic-strings/

// Brute Force
// We iterate over str1 and change the characters of str2 with the equivalent characters from str1.
// Then we iterate over original str2 and change the characters of original str1 with equivalent characters from str2.
// => If ultimately we end up getting str1 == str2 in both cases, then our strings are isomorphic.
// Example: str1 = "abc" str2 = "agg"
// Itr1 'a' => str2 => "agg"       [Change all occurance of a in str2 with a from str1]
// Itr2 'b' => str2 => "abb"       [Change all occurance of g in str2 with b from str1]
// Itr3 'c' => str2 => "acc"       [Change all occurance of b in str2 with c from str1]
// Ultimately, "abc" != "acc" => false ...(1)

// Part2: str1 = "agg", str2 = "abc"
// Itr1 'a' => str2 => "abc"
// Itr2 'g' => str2 => "agc"       [Change all occurance of b in str2 with g from str1]
// Itr3 'g' => str2 => "agg"       [Change all occurance of c in str2 with c from str1]
// Ultimately, "agg" == "agg" => true  ...(2)

// If and Only If (1) && (2) Both are true, then we return true.
// Time: O(2*n1*n2)
// Space: O(n1 + n2)

// Optimal
// We create a new common language for both the strings. That language is the index of latest occurance of that character.
// We ultimately need to find if a character is being mapped to two characters or not, to answer whether strings are isomorphic.
// Example: str1 = "abc" str2 = "agg"
// {'a':0, 'b':1, 'c':-1}
// {'a':0, 'g':1}
// When you reach 'c' while iterating on str1 chars, you'll see it doesn't map with 'g' which has already been mapped with 'b'
// Time: O(n1)
// Space: O(n1+n2)

#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.length() != t.length()) return false;

    vector<int> mapS(128, -1); 
    vector<int> mapT(128, -1); // ASCII: t[i] = s[i] = i
    
    for(int i = 0; i < s.length(); i++) {
        if(mapS[s[i]] != mapT[t[i]]) {
            return false;
        }
        mapS[s[i]] = mapT[t[i]] = i;
    }
    return true;
}

int main(){
    
    return 0;
}