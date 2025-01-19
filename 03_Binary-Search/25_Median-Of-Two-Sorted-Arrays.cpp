// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// Note: Median may not exist in the two arrays. If they sum of to even no of elements.
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000

// Brute Force
// Merge the two sorted arrays into one, like merge sort.
// Then find its median.
// Time: O(n1+n2) [To find the merged array] + O(1) [To find the central element]
// Space: O(n1+n2)

#include <bits/stdc++.h>
using namespace std;

// Brute Force Optimized
// We can optimize the space as we dont need all the elements. We just need the element at (n1+n2)/2 index.
// Time: O((n1+n2)/2)
// Space: O(1)
// NOTE: If you dont want to mess up any conditions for prevNum, you can do:-
//          if(currIdx == size/2) medianIdx2 = currIdx;
//          if(currIdx == size/2 - 1) medianIdx1 == currIdx;
//      Then at the end you can check if the size is even or odd, and according use medianIdx2 or both median indices.

double findMedian(int size, int currNum, int prevNum){
    if(size&1){
        return currNum;
    } else {
        return (currNum+prevNum)/2.0;
    }
}
double merge(vector<int>& nums1, vector<int>& nums2){
    int n1 = nums1.size(), n2 = nums2.size();
    int size = n1 + n2;
    int i=0, j=0, currIdx=0, currNum, prevNum;
    while(i<n1 && j<n2){
        prevNum = currNum;
        if(nums1[i] < nums2[j]){
            currNum = nums1[i];
            ++i;
        }else{
            currNum = nums2[j];
            ++j;
        }
        if(currIdx == size/2) {
            return findMedian(size, currNum, prevNum);
        }
        ++currIdx;
    }

    while(i<n1){
        prevNum = currNum;
        currNum = nums1[i];
        if(currIdx == size/2) {
            return findMedian(size, currNum, prevNum);
        }
        ++currIdx;
        ++i;
    }

    while(j<n2){
        prevNum = currNum;
        currNum = nums2[j];
        if(currIdx == size/2) {
            return findMedian(size, currNum, prevNum);
        }
        ++j;
        ++currIdx;
    }

    return 0;
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    return merge(nums1, nums2);
}

// Optimal
// nums1 = {  1,  3,  4,  7, 10, 12}
// nums2 = {  2,  3,  6, 15}

// No of elements in left half of merged array = (n1 + n2 + 1)/2;
// Which works in case of both even and odd total : -
// Even total => (6 + 4 + 1)/2 => 10+1/2 => 5
// Odd total  => (6 + 3 + 1)/2 => 9+1/2  => 5

// If we try to form the merged array with "even" no of total elements.
// We will have 5 elements on left half and 5 on right half.
// Like : [1,2,3,3,4 | 6,7,10,12,15]
// Now, to form the left half, we may have 0 to all 5 elements from nums1
//      and correspondingly from nums2.
// Lets take 0 elements from nums1 => 4 from nums2. [But this doesnt total upto 5 elements we need in left half]

// So take 1 element from nums1 => 4 from nums2.
// [1        | 3,4,7,10,12]
// [2,3,6,15 | ]
// Here 15 (in LHS) > 3 => This configuration is not possible.

// Lets take 2 elements from nums1 => 3 from nums2.
// [1,3   | 4,7,10,12]
// [2,3,6 | 15]
// Here 6 (in LHS) > 4 => This configuration is not possible.

// Lets take 3 elements from nums1 => 2 from nums2.
// [1,3,4 | 7,10,12]
// [2,3   | 6,15]
// Good! Our Cross Check is valid!
// l1<=r2 && l2<=r1 => 4<6 && 3<7 => This is the only possible configuration.
// Here, the median is : -
// lastElementFromLHS = max(l1,l2)
// firstElementFromRHS = min(r1,r2)
// median = (lastElementFromLHS + firstElementFromRHS)/2.0;

// If we try taking 4 elements from nums1 => 1 from nums2.
// [1,3,4,7 | 10,12]
// [2       | 3,6,15]
// 7(in LHS) > 3 in RHS

double findMedianSortedArrays_optimalApproachWithoutBS(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    int nLHS = (n1+n2+1)/2;

    if(n2 < n1) return findMedianSortedArrays(nums2, nums1);

    for(int i=0; i<=n1; ++i){
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(i != 0) l1 = nums1[i-1];
        if(i != n1) r1 = nums1[i];
        if(nLHS - i != 0) l2 = nums2[nLHS-i-1];
        if(nLHS - i != n2) r2 = nums2[nLHS-i];

        if(l2 <= r1 && l1 <= r2) {
            if((n1+n2)&1){
                return max(l1,l2);
            } else {
                return (min(r1,r2)+max(l1,l2))/2.0;
            }
        }
    }

    return -1;
}

// NOW, HOW DO WE APPLY BINARY SEARCH?
// To eliminate one half : -
// if (l1 > r2) => You are taking too many elements from nums1 => high = mid-1;
// if (l2 > r1) => You are taking too many elements from nums2 => Too few from nums1 => low = mid+1;
// NOTE: If l1 or l2 DNE => l1 = INT_MIN;
//       If r1 or r2 DNE => r1 = INT_MAX;

// To write this, from the linear fn, just replace i with mid;
// Don't use mid1 and mid2 like striver its confusing.
double findMedianSortedArrays_usingBS(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    int nLHS = (n1+n2+1)/2;

    if(n2 < n1) return findMedianSortedArrays(nums2, nums1);

    int low=0, high=n1, mid;

    while(low<=high){
        int mid = low + (high-low)/2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid != 0) l1 = nums1[mid-1];
        if(mid != n1) r1 = nums1[mid];
        if(nLHS - mid != 0) l2 = nums2[nLHS-mid-1];
        if(nLHS - mid != n2) r2 = nums2[nLHS-mid];

        if(l2 <= r1 && l1 <= r2) {
            if((n1+n2)&1){
                return max(l1,l2);
            } else {
                return (min(r1,r2)+max(l1,l2))/2.0;
            }
        } else if(l1 > r2) {
            high = mid-1;
        } else if(l2 > r1) {
            low = mid + 1;
        }
    }

    return -1;
}

int main(){
    
    return 0;
}