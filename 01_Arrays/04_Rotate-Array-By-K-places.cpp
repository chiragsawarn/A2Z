// Question : Rotate array from right to left, by K places.
// https://leetcode.com/problems/rotate-array/
// NOTE : Anyone can do it using extra space. You are expected to do it without extra space or time.

// Brute Force
// Repeat the approach to shift one item to the right, K times.
// Following is the approach to shift one item :-
// Store last item, Shift the rest to the right. Then put the stored item in front of array.
// Time : O(k*n)
// NOTE : k might be greater than n. In that case we can rotate by k%n times.
// So, our worst case time : O(n^2)

// Better
// Use some extra space to store k elements from the end.
// Move rest of the element at (i+k) index.
// From the extra space put the k-elements at the start.
// Time: O(k+n-k+k) => O(n+k)
// Space: O(k)

// Optimal
// reverse n-k elements in place. reverse k elements in place. then reverse the array whole.
// Time : O(n/2 + n/2) => O(n)
// ExtraSpace: O(1)

#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &nums, int start, int end){
    int mid = (start+end)/2;
    int k=0;
    for(int i=start; i<=mid; ++i){
        swap(nums[i], nums[end-k]);
        ++k;
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k%n;
    // NOTE : You can also use the STL's reverse function
    // reverse(nums.begin(), nums.begin() + (n - k));
    // reverse(nums.begin() + (n - k), nums.end());
    // reverse(nums.begin(), nums.end());
    reverse(nums,0, n-k-1);
    reverse(nums,n-k, n-1);
    reverse(nums,0,n-1);
}

int main(){
    
    return 0;
}