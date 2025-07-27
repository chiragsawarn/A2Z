// https://leetcode.com/problems/sliding-window-maximum/

// Brute Force
// For each starting point from 0 to n-k-1 => Iterate over the next k points to find the maximum. And store it in an array.
// Time: O(n*k)
// Space: O(1)

// Optimal
// Maintain a sliding window of size k. Store the possible contenders of max element in a deque.
// 1) "Growing window"    : When you find a new element. Start comparing it from the back of the deque and throwing all the elements out until you find an element greater than it or reach the start of deque.
// 2) "Shrinking window"  : When you are moving i. Then compare it with the start of the deque. If it is same. The pop the start of the deque.
// 3) "Answer calculation": Each time you hit window size k. The front of the deque is the maximum answer.
// Time: O(n)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;

    int i=0, j=0, n=nums.size();
    vector<int> res;

    while(j<n){
        while(!q.empty() && nums[q.back()] <= nums[j]) q.pop_back();
        q.push_back(j);
        while(j-i+1 > k){
            if(!q.empty() && q.front() == i){
                q.pop_front();
            }
            ++i;
        }
        if(j-i+1 == k){
            res.push_back(nums[q.front()]);
        }
        ++j;
    }

    return res;
}

int main(){
    
    return 0;
}