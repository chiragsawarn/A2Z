// https://leetcode.com/problems/sort-colors/

// Brute
// Use bubble sort
// Time: O(n^2)
// Space: O(1)

// Better
// Use quicksort
// Time: O(nlogn)
// Extra Space: O(1)

// Optimal
// Use 2 variables and one pass to count no of zeros and ones. 
// Use a second pass to fill the array up with 0,1 and remaining spaces with 2
// Time: O(2n)
// Space: O(1)

// Optimal - Single Pass
// Use a low flag and a high flag.
// low points to -> last 0
// high points to-> last 2
// Between : mid to high -1  -> We have unsorted array
// Time: O(n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int i=-1, j=nums.size(), k=0;

    while(k<j){
        if(nums[k] == 0){
            ++i;
            swap(nums[i], nums[k]);
            ++k;
        } else if (nums[k] == 1){
            ++k;
        } else {
            --j;
            swap(nums[k], nums[j]);
        }
    }
}

int main(){
    
    return 0;
}