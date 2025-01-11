// https://leetcode.com/problems/binary-search/
#include <bits/stdc++.h>
using namespace std;

int binarySearch_recursive(vector<int> &nums, int low, int high, int target){
    if(low > high){
        return -1;
    }
    int mid = (low+high)/2;
    if(nums[mid] == target){
        return mid;
    } else if(nums[mid] < target){
        return binarySearch_recursive(nums, mid+1, high, target);
    } else {
        return binarySearch_recursive(nums, low, mid-1, target);
    }
}
int search(vector<int>& nums, int target) {
    return binarySearch_recursive(nums, 0, nums.size()-1, target);
}

int search_iterative(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;
    do{
        int mid = (low+high)/2;
        if(nums[mid] == target){
            return mid;
        } else if(nums[mid] < target){
            low = mid+1;
        } else {
            high = mid-1;
        }
    }while(low<=high);

    return -1;
}

int main(){
    
    return 0;
}