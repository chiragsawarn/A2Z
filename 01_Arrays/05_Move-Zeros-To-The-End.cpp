// Link : https://leetcode.com/problems/move-zeroes/
// Move zeros to the end, without replace the order of other elements.
// NOTE : You can't use extra space.

// Brute Force
// Iterate over the array, if you find a zero => shift it "one by one" to the end of the array.
// Time: O(n^2)
// Space: O(1)

// Better
// Put all non zero elements in a new array. 
// Then replace the original array with this array. Also push zeros in the remaining places in original array.
// Time: O(n) + O(n-x) + O(x) => O(2n)
// Space: O(n - no_of_zeros)

// Optimal
// Use dutchNationalFlag technique: Ek nonZeroFlag hoga, ek iterator hoga. 
// NonZero elements ko flag+1 pe fenk do. Aur flag++ kardo.
// End mein nonZeroFlag -> n zeros push kardo

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int nonZeroIdx = -1;
    for(int i=0; i<nums.size(); ++i){
        if(nums[i] != 0){
            ++nonZeroIdx;
            swap(nums[nonZeroIdx], nums[i]);
        }
    }
}
    
int main(){
    
    return 0;
}