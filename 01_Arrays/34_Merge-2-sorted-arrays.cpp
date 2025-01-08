// You have to merge two sorted arrays into the first array. Wihout using extra space.

// There are 2 versions of this problem :-
// Version1 : nums1 has the length n1+n2, but only has n1 elements.
// https://leetcode.com/problems/merge-sorted-array/description/

// V1: Optimal Solution
// In this version. DON"T USE GAP METHOD.
// Use three pointers 
// i: points to nums1's last element's index
// j: points to nums2's last index
// k: points to nums1's last index of the array.
// Now iterate over nums2, from end to beginning. Push the largest element at k's index. And decrement k.
// Time: O(n1+n2)
// Space: O(1)

// Version2 : nums1 has n1 length only. 
// https://www.naukri.com/code360/problems/merge-two-sorted-arrays-without-extra-space_6898839?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse
// In this version you must use mentioned optimal approaches like gap method OR Greedy Swapping to move large element to nums2.

// V2: Brute Force
// Find the minimum element in both arrays and place it at the front. Then reduce search space.
// Time: O(n^2)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

// V2: Better
// nums1 = {1, 4, 5, 7} nums2 = {2, 3, 6}
// Swap all the element from nums2.begin() with nums1.end() so that nums2 eventually ends up with all big elements at the cost of its smallest elements.
// While nums1 ends up looking like a mountain with first ascending, then descending elements from nums2.
// After Swap1 : {1,4,5,2} & {7,3,6}
// After Swap2 : {1,4,3,2} & {7,5,6}
// Swap3 : Not possible as 4 < 6
// Then sort(nums1) & sort(nums2)
// Time: O(min(n1,n2)) [To swap elements] + O(n1logn1) [To sort nums1] + O(n2logn2) [To sort nums2] => O(min(n1,n2) + n1logn1 + n2logn2)
// Space: O(1)

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=0, j=m-1;

    while(i<n && j>=0 && nums1[j]>nums2[i]){
        swap(nums1[j], nums2[i]);
        ++i;
        --j;
    }
    sort(nums1.begin(), nums1.begin()+m);
    sort(nums2.begin(), nums2.end());

    for(int i=0; i<n; ++i){
        nums1[m+i] = nums2[i];
    }
}

// V2: Better - Gap Method
// Use two pointers seperated by gap indices.
// After each iteration gap reduces to ceil(gap/2)
// When gap becomes 1, stop after one iteration.
// Time: O((n1+n2)log(n1+n2))
// Space: O(1)

int findGap(int prevGap){
    return ceil(prevGap/2.0);
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i=0; i<n; ++i){
        nums1[m+i] = nums2[i];
    }

    int gap = m+n;

    do {
        gap = findGap(gap);
        int i=0;
        int j=i+gap;

        while(j<m+n){
            if(nums1[i] > nums1[j]){
                swap(nums1[i], nums1[j]);
            }
            ++i;
            ++j;
        }
    }while(gap != 1);
}

int main(){
    
    return 0;
}