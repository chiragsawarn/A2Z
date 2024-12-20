// https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-array-1587115620/0

// Brute Force
// For each item in array1 you can check if the item exists in array2. Use a visited array to make sure you dont push duplicates into results array.
// Time: O(n*m)

// Optimal
// Use merge fn of merge sort. Add a case for a[i] == b[j].
// Create a push function that gets rid of duplicates.
// NOTE: when a[i] == b[j] => both i and j will be incremented.
// Time: O(n or m) whichever is smaller

#include <bits/stdc++.h>
using namespace std;

void push(vector<int> &res, int x){
    int n = res.size();
    if(n == 0 || (res[n-1] != x)){
        res.push_back(x);
    }
}

vector<int> intersection(vector<int> &a, vector<int> &b) {
    vector<int> res;
    int i=0, j=0;
    int n = a.size(), m = b.size();

    while(i<n && j<m){
        if(a[i] < b[j]){
            ++i;
        } else if(a[i] > b[j]) {
            ++j;
        } else {
            push(res, a[i]);
            ++i;
            ++j;
        }
    }

    return res;
}

int main(){
    
    return 0;
}