// Find floor and ceil of an unsorted array.
// https://www.geeksforgeeks.org/problems/ceil-the-floor2802/0

// Brute Force
// Sort the array. Then do linear search to find left and right elements to k.
// Time: O(nlogn + n)

// Optimal
// Sort the array. Then do binary search to find lower_bound and upper_bound of k.
// Time: (nlogn + logn)

#include <bits/stdc++.h>
using namespace std;

int getFloor(vector<int> &arr, int k){
    int ansIdx = -1;
    int low = 0, high = arr.size()-1;
    
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

int getCeil(vector<int> &arr, int k){
    int ansIdx = -1;
    int low = 0, high = arr.size()-1;
    
    do{
        int mid = (low+high)/2;
        if(arr[mid] == k){
            return mid;
        } else if(arr[mid] < k){
            low = mid+1;
        } else {
            ansIdx = mid;
            high = mid-1;
        }
    }while(low<=high);
    
    return ansIdx;
}

vector<int> getFloorAndCeil(int x, vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int floorIdx = getFloor(arr, x);
    int ceilIdx = getCeil(arr, x);
    
    int floor_ = (floorIdx == -1) ? -1 : arr[floorIdx];
    int ceil_ = (ceilIdx == -1) ? -1 : arr[ceilIdx];

    return {floor_, ceil_};
}

int main(){
    
    return 0;
}