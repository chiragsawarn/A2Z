// https://leetcode.com/problems/majority-element/solutions/
// Find the element that occurs greater than n/2 times

// Brute Force
// We pick each element from the array and count it.
// If any time count > n/2 => Then we have found our answer.
// Time: O(n^2)
// Space: O(1)

// Better
// Make a frequency hashmap and any time count exceeds n/2 then we have found our answer.
// Time: O(n)
// Space: O(n)

// Optimal
// Moore's Voting Algo
// The element in majority's count > 0 at the end of iterating the array.
// When count == 0 => Choose nums[i] as the new majority element.
// Note : In the array {7,7,7,5,2,2} => 7 occurs more than any other number but it is still not the majority element. 
//        As the majority element must occur more than n/2 times. {4 times atleast, in this example}

#include <bits/stdc++.h>
using namespace std;

 int majorityElement(vector<int>& nums) {
    int count = 0;
    int majority = nums[0];

    for(int i=0; i<nums.size(); ++i){
        if(count == 0){
            majority = nums[i];
        }
        if(nums[i] == majority){
            ++count;
        } else {
            --count;
        }
    }

    return majority;
}

int main(){
    
    return 0;
}