// Find *ALL* Majority elements that occur more than n/3 times.
// https://leetcode.com/problems/majority-element-ii/description/

// Maximum no of integers that can occur more than n/3 times is: floor(n/3)
// So in an array of 8, at max we may have 2 answers.

// Brute Force
// Iterate from left to right. Assume each element as the answer.
// Count how many times it appears in the array.
// If any element appears more than n/3 times then push it in the res array.
// Time: O(n^2)
// Space: O(1)

// Better
// Use a hashmap to store the count of unique elements. Whenever a count hits more than n/3. Push it in res array.
// Time: O(n)
// Space: O(n)

// Optimal
// Extended version of voting algo.
// Note: No of elements that may occur more than n/3 times can be a maximum of 2.
// But there may be a single element or no element at all. Hence we must run one verification iteration over the array and count the freqency of our contest winners x and y.
// If the count1 and count2 both come out to be more than n/3 then push them in the res array.
// Time: O(2n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int count1 = 0, count2 = 0, n = nums.size();
    int x, y;

    for(int i=0; i<n; ++i){
        if(count1 == 0 && y != nums[i]){
            x = nums[i];
        } else if(count2 == 0 && x != nums[i]){
            y = nums[i];
        }
        
        if(nums[i] == x){
            ++count1;
        }else if(nums[i] == y){
            ++count2;
        }else {
            --count1;
            --count2;
        }
    }

    // verification of majority
    count1 = 0;
    count2 = 0;
    for(int i=0; i<n; ++i){
        if(nums[i] == x){
            ++count1;
        } else if(nums[i] == y){
            ++count2;
        }
    }

    vector<int> res;
    if(count1 > n/3){
        res.push_back(x);
    }
    if(count2 > n/3){
        res.push_back(y);
    }

    return res;
}

int main(){
    
    return 0;
}