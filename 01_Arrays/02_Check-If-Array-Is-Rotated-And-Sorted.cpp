// Question link
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

// Optimal
// We identify bumps.
// A bump is when left <= right property of a sorted array doesn't hold because of the rotation. 
// Example : 4 5 1 2 3 => Here 5->1 is a bump
// In a rotated sorted array, at max there can be one bump. If we find more than one bump, then the array is not sorted properly.
// Now this approach is perfect, excpt we will miss the bump that is "spread out by rotation"
// Example : 2 4 1 3 
// Here if we only read left to right, there is only 1 bump .i.e. 4->1
// To identify the "spread out bump" check if leftMost < rightMost, this can not be true if the array is rotated ans sorted.
// Which means if it is true, either array is completely sorted and this false "spread out bump" is the only bump and wont cause issues.
//  Or, the array is not sorted and this is an actual spread out bump, and will aid us to find if array is not sorted and rotated.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int bumps = 0;
        // leftEnd < rightEnd is odd in a rotated sorted array => count it as a bump
        if(nums[0] < nums[nums.size()-1]) ++bumps; 
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]<nums[i-1]){
                if(bumps==1) return false;
                ++bumps;
            }
        }
        return true;
    }
};

int main(){
    
    return 0;
}