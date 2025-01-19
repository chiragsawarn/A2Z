// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Merge the two arrays. And return the k-th element.
// Time: O(n1+n2)
// Space: O(1)

// Better
// Time: O(min(n1,n2))
// Space: O(1)
int kthElement(vector<int>& a, vector<int>& b, int k) {
    int n1 = a.size(), n2 = b.size();
    
    if(n2 < n1) return kthElement(b,a,k);
    // we can't start nums1 with 0 elements.
    // As k might be so large all of nums2 can't cover it.
    // Ex: nums1 = [4,5,5,6,10,11,13]
    //     nums2 = [6,6,9,10,10,11,12]
    //         k = 10
    int startingNumsNeededFromA = (k > n2) ? k-n2 : 0;
    for(int i=startingNumsNeededFromA; i<=n1; ++i){
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        
        if(i != 0) l1 = a[i-1];
        if(i != n1) r1 = a[i];
        if(k-i != 0) l2 = b[k-i-1];
        if(k-i != n2) r2 = b[k-i];

        if((l1 <= r2) && (l2 <= r1)){
            return max(l1,l2);
        }
    }
    
    return -1;
}

// Optimal
// Applying Binary search to above technique.
// The high low is very critical in this question.
// Time: O(log(min(n1,k) - max(k-n2,0)))
// Space: O(1)
int kthElement(vector<int>& a, vector<int>& b, int k) {
    int n1 = a.size(), n2 = b.size();
    
    if(n2 < n1) return kthElement(b,a,k);
    int low = max(k-n2,0); // IMP
    int high = min(n1,k);  // IMP
    while(low <= high){
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        
        int mid = low + (high-low)/2;
        
        if(mid != 0) l1 = a[mid-1];
        if(mid != n1) r1 = a[mid];
        if(k-mid != 0) l2 = b[k-mid-1];
        if(k-mid != n2) r2 = b[k-mid];

        if((l1 <= r2) && (l2 <= r1)){
            return max(l1,l2);
        } else if(l1 > r2) {
            // Too many elements from nums1
            high = mid - 1;
        } else if(l2 > r1) {
            // Too few elements from nums1
            low = mid + 1;
        }
    }
    
    return -1;
}

int main(){
    
    return 0;
}