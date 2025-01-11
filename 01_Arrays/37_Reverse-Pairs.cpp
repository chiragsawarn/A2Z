// Count the number of pairs in nums such that index i<j and nums[i] > 2*nums[j]
// https://leetcode.com/problems/reverse-pairs/

// Brute Force
// For each number in the array, find numbers to the right that it is more than twice larger to.
// [2, 4, 3, 5, 1] => [[4,1], [3,1], [5,1]]
// Time: O(n^2)
// Space: O(1)

// Optimal
// Use the same concept of counting inversions.
// There is a twist tho.
// In count inversions: The sorting and inversion logic is the same. 
// When left > right => right element is processed. Inversions are counted as well as sortedArr.push_back(right)
// But not in reverse pairs!
// Important
// Why calculate solution here? And not inside while loop?
// Ans. [2,3,4] & [1,5]
// if(nums[i] > nums[j]) => res.push_back(nums[j]); ++j;
// processing 1 from right array by doing ++j was fine for calculating inversion
// => as inversion processing was exact same as sorting processing. 
// But here, in this question. 
// We are practically merging [2,3,4] & double([1,5]) => [2,3,4] & [2,10] {for counting inversion}
//                And merging [2,4,5] & [1,5] {for sorting}
// That is why we need a seperate loop for answer calculation. Before the arrays are merged.
// Mistake: DO NOT USE A FOR LOOP IN MERGE Fn. YOU WILL MISS ELEMENTS.

// Time: O((n [to count pairs] + n [merging]) x logn) => (2n*logn)
// Space: O(n+ logn)

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high, int &ans){
    int i=low;
    int j=mid+1;
    vector<int> res;

    // ANSWER CALCULATION - START
    int J = mid+1;
    int I = low;
    while(I <= mid && J <= high){
        if(nums[I] > 2L*nums[J]) {
            ans += mid - I + 1;
            ++J;
        } else {
            ++I;
        }
    }
    // ANSWER CALCULATION - END

    while(i<=mid && j<=high){
        if(nums[i] <= nums[j]){
            res.push_back(nums[i]);
            ++i;
        } else {
            res.push_back(nums[j]);
            ++j;
        }
    }

    while(i<=mid){
        res.push_back(nums[i]);
        ++i;
    }
    while(j<=high){
        res.push_back(nums[j]);
        ++j;
    }

    for(int i=low; i<=high; ++i){
        nums[i] = res[i-low];
    }
}
void mergeSort(vector<int> &nums, int low, int high, int &ans){
    if(low < high){
        int mid = (low+high)/2;
        mergeSort(nums, low, mid, ans);
        mergeSort(nums, mid+1, high, ans);
        merge(nums, low, mid, high, ans);
    }
}
int reversePairs(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    mergeSort(nums,0,n-1, ans);

    return ans;
}

int main(){
    
    return 0;
}