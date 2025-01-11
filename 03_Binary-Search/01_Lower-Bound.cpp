// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/0

// [1, 2, 8, 10, 11, 12, 19], k = 5 
// Lower bound of k=5 is 2 whose index is 1. So return 1.
#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& arr, int k) {
    int low = 0, high = arr.size()-1;
    int ansIdx = -1;
    
    do{
        int mid = (low+high)/2;
        if(arr[mid] == k){
            return mid;
        } else if(arr[mid] < k){
            ansIdx = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }while(low<=high);
    
    return ansIdx;
}

int main(){
    
    return 0;
}