// Question Link
// https://www.naukri.com/code360/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse

// Brute Force
// Look at each element - Compare with the rest of the array and see if it is largest
// Time: O(n^2)

// Better
// Sort the array, return last element of sorted array as greatest
// Time: O(nlogn)

// Optimal
// DP
// Maintain a mavVal for a subarray, and update it as the sizeOfSubarray increases


#include <bits/stdc++.h>
using namespace std;

int dpSolution(vector<int> arr){
    int maxVal = arr[0];
    for(int i=0; i<arr.size(); ++i){
        maxVal = max(maxVal, arr[i]);
    }
    return maxVal;
}

int main(){
    
    return 0;
}