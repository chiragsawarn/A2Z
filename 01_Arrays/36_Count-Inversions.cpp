// Find count of pairs in the array such that i<j but arr[i]>arr[j]
//https://www.naukri.com/code360/problems/number-of-inversions_6840276?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems
// Example : [5, 3, 2, 1, 4]
// Answer : 7

// Brute Force
// For each element, count the elements towards its right that are lesser than it.
// Time: O(n^2)
// Space: O(1)

// Optimal 
// Write whole merge sort code. Just add one line to increment answer.
// Technique: When you have 2 sorted arrays that you are merging...
// Example : [i->2,3,5,6] & [j->2,2,4,4,8] 
// Since nums[i] <= nums[j] => ++i;

// [2,i->3,5,6] & [j->2,2,4,4,8] 
// Since nums[i] > nums[j], not only 3, but all elements to the right of 3 in nums1 can make a pair with nums[j] => Increment answer by 3; 
// => ++j;
// [2,i->3,5,6] & [2,j->2,4,4,8]
// Since nums[i] > nums[j], increment answer by 3
// => ++j;

// [2,i->3,5,6] & [2,2,j->4,4,8]
// Since nums[i] <= nums[j] => ++i;

// [2,3,i->5,6] & [2,2,j->4,4,8]
// Since nums[i] > nums[j], increment answer by 2
// ++j;
// [2,3,i->5,6] & [2,2,4,j->4,8]
// Since nums[i] > nums[j], increment answer by 2
// ++j;
// [2,3,i->5,6] & [2,2,4,4,j->8]
// Since nums[i] <= nums[j] => ++i;

// [2,3,5,i->6] & [2,2,4,4,j->8]
// Since nums[i] <= nums[j] => ++i;


// Time: O(nlogn)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high, int &ans){
    int i = low;
    int n1 = mid - low + 1;
    int j = mid+1;
    int n2 = high - mid;
    vector<int> sortedArr;

    while(i<=mid && j<=high){
        if(arr[i] <= arr[j]){
            sortedArr.push_back(arr[i]);
            ++i;
        } else {
            ans += mid - i + 1;
            sortedArr.push_back(arr[j]);
            ++j;
        }
    }

    while(i<=mid){
        sortedArr.push_back(arr[i]);
        ++i;
    }
    while(j<=high){
        sortedArr.push_back(arr[j]);
        ++j;
    }

    // Pushing elements back into original array
    i = low;
    for(int k=0; k<sortedArr.size(); ++k){
        arr[i] = sortedArr[k];
        ++i;
    }
}
void mergeSort(vector<int> &arr, int low, int high, int &ans){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(arr, low, mid, ans);
        mergeSort(arr, mid+1, high, ans);
        merge(arr, low, mid, high, ans);
    }
}
int numberOfInversions(vector<int>&a, int n) {
    int ans = 0;
    mergeSort(a, 0, n-1, ans);
    return ans;
}

int main(){
    
    return 0;
}