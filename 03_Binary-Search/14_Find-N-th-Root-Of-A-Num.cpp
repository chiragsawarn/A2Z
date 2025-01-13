// Given n,m : Find n-th root of m.
// Input: n = 2, m = 9
// Output: 3
// Explanation: 3^2 = 9
// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

// Optimal
// Same concept as last question.
// Time: O(logn)

#include <bits/stdc++.h>
using namespace std;

int nthRoot(int n, int m) {
    int low = 0, high = m;
    
    while(low<=high){
        long mid = low + (high-low)/2;
        long pow_ = pow(mid,n);
        if(pow_ == m){
            return mid;
        } else if(pow_ < m){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main(){
    
    return 0;
}