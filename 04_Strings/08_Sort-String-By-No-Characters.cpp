// Sort the given string in descending order based on the no of characters it has.
#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Step 1 : Find freq of each character.
// Maintain a freq count array of size 52. As char are [a-zA-Z0-9]
// Iterate over a to z, then over A to Z, then over 0 to 9.
//      In a nested loop, iterate over the characters of s.
//      Whenever there is a match increment the count of that character.
// Step 2: Make the freq count descending.
// Then sort this freq count in descending order.
// Step 3: Popupate result string.
// Time: O(26*n) [As we do a nested loop]
// Space: O(26 + 26 + 10) => O(1)

// Optimal
// We dont need to do a nested loop. We can directly iterate over the characters of s.
// Time: O(n) [create freq map] + 62log62 [For sorting] + O(n) [res string]=> O(2n)
// Space: O(n) [for freq map] + O(n) [result string] => O(2n)
static bool comparator(pair<int, char> &a, pair<int, char> &b){
    return a.first > b.first;
}
string frequencySort(string s) {
    vector<pair<int,char>> freq(62, {0, '#'});

    for(int i=0; i<s.length(); ++i){
        if('a' <= s[i] && s[i] <= 'z') {
            int idx = s[i] - 'a';
            freq[idx] = {++freq[idx].first, s[i]};
        } else if('A' <= s[i] && s[i] <= 'Z'){
            int idx = s[i] - 'A' + 26;
            freq[idx] = {++freq[idx].first, s[i]};
        } else {
            int idx = s[i] - '0' + 52;
            freq[idx] = {++freq[idx].first, s[i]};
        }
    }

    sort(freq.begin(), freq.end(), comparator);

    string res = "";
    for(auto p:freq){
        while(p.first != 0){
            res += p.second;
            --p.first;
        }
    }

    return res;
}


int main(){
    
    return 0;
}