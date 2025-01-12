// Find K - The amount by which array is rotated. Given a sorted rotated array.
// https://www.geeksforgeeks.org/problems/rotation4723/1

// Brute Force
// Do a linear iteration to find the bump.

// Optimal
// Find the minimum element's index in the rotated array.
// Just before the minimum element would be last rotated element.
// So the index of the minimum element is also the amount by which array is rotated.
// Time: O(logn)

#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size()-1, minEleIdx = 0;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[low] <= arr[mid]){
            if(arr[low] < arr[minEleIdx]){
                minEleIdx = low;
            }
            low = mid + 1;
        } else {
            if(arr[mid] < arr[minEleIdx]){
                minEleIdx = mid;
            }
            high = mid - 1;
        }
    }
    
    return minEleIdx;
}

int main(){
    
    return 0;
}