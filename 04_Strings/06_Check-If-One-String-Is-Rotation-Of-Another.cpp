// https://leetcode.com/problems/rotate-string/description/

// Brute Force
// Note n1 and n2 are same. If not, then goal string can't be converted to test string.
// We left rotate goalString one by one. If any rotation matches test string, then we are done.
// n [for each character] x (n [do a rotation] + n [to compare rotation with test string])
// Time: O(n*(n+n)) => O(2n^2) => O(n^2)

// Optimal
// Attach s to itself. And then find the goal string in it.
// Time: O(n)
// Space: O(2n) [As s is concatenated to itself, and we are trying to avoid changing input array]

#include <bits/stdc++.h>
using namespace std;

void rotate_bf(string &goal, int k){
    reverse(goal.begin(),goal.begin()+k-1);
    reverse(goal.begin()+k, goal.end());
    reverse(goal.begin(), goal.end());
}
bool rotateString_bf(string s, string goal) {
    int n1 = s.length(), n2 = goal.length();

    if(n1 != n2) return false;

    for(int i=0; i<n2; ++i){
        rotate_bf(goal, 1);
        if(s == goal){
            return true;
        }
    }
    return false;
}

bool rotateString(string s, string goal) {
    if(s.length() != goal.length()) return false;
    int n=s.length();

    string test = s + s;
    return (test.find(goal) != -1) ? true : false;
}

int main(){
    
    return 0;
}