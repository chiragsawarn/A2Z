// Find the floor of the square_root of a number
// Sqrt(25) => 5
// Sqrt(30) => 5
// https://www.geeksforgeeks.org/problems/square-root/0

// Brute Force
// Do a linear trial and error from 1 to n.
// 1*1 == n^2 ? "Found answer!" : 2*2 == n^2 ? "Found Answer!" : ...
// Note: when num*num > n  (first time) => num-1 is the floorOfSqrt and n is not a perfect Square
// Time: O(sqrt(n))
// Space: O(1)

// Optimal
// Follow the same process as above but in a binary search style.
// if (mid*mid == n) => answer found
// else if (mid*mid < n) => mid is a possible answer (n may not be a perfect square!)
// Time: O(logn)


#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int low = 0, high = n, possibleAns = 1;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        int sq = mid*mid;
        if(sq == n){
            return mid;
        } else if(sq < n){
            possibleAns = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return possibleAns;
}

int main(){
    
    return 0;
}