// Question: Given a subarray with only a, b, c.
//           Find the no of subarrays that contain one of each: a,b,c.
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

// Optimal
// Note: Once you find the minimum most subarray that contains one of each a,b,c.
//       You can add one for each character before that. As one of each is already found.
// Example: "aaacb" => 3 
// Step 1: lets keep track of the index of lastA, lastB, lastC. 
//         Which are all -1 initially. 
// Step 2: When None of them are -1, then you find your first as well as minimum most subarray. 
//         The minimum most subarray starts at leastOF(lastA, lastB, lastC)
// Step 3: "aa" + "acb" => every character before this minimumSubarray adds 1 to the count, plus 1 for the minimum subarray itself.
//         Hence 2 + 1 => 3


#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int n= s.length();
    int count=0;
    int lastA=-1, lastB=-1, lastC=-1;

    for(int i=0; i<n; ++i){
        if(s[i] == 'a'){
            lastA = i;
        } else if (s[i] == 'b') {
            lastB = i;
        } else {
            lastC = i;
        }

        if(lastA != -1 && lastB != -1 && lastC != -1){
            int minIdx = min(lastA, min(lastB, lastC));
            count += minIdx + 1;
        }
    }

    return count;
}

int main(){
    
    return 0;
}