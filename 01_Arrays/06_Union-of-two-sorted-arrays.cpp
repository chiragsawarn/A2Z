// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
// NOTE : Arrays may contain duplicate elements. Secondly, array lengths may not be same.

// Brute Force
// Use and ordered set to push all the elements. Then push the elements from set into an array to return as answer.
// NOTE: We use ordered set as the answer needs to be returned in sorted format.
// Time: O(nlogn + mlogm) [pushing into set] + O(n+m) [pushing into ans array]
// Space: O(n+m) [set] + O(n+m) [answer array]

// Optimal
// Use the merge part of merge sort, but a special function to push into answer array that eliminates duplicates.
// Time: O(n+m)
// Space: O(n+m) [Only to return answer in required format]
#include <bits/stdc++.h>
using namespace std;

void push(vector<int> &res, int x){
    int n = res.size();
    if(n == 0 || (res[n-1] != x)){
        res.push_back(x);
    }
}

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> res;
    
    int i=0, j=0;
    int n = a.size(), m = b.size();
    
    while(i<n && j<m){
        if(a[i] <= b[j]){
            push(res, a[i]);
            ++i;
        } else {
            push(res, b[j]);
            ++j;
        }
    }
    
    while(i<n){
        push(res, a[i]);
        ++i;
    }
    
    while(j<m){
        push(res, b[j]);
        ++j;
    }
    
    return res;
}

int main(){
    
    return 0;
}