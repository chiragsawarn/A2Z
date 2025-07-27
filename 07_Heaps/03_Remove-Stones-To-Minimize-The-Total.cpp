// https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

// Learning
// There is only 1 way to build a heap from an array.
// Time: O(n)
// priority_queue<int> pq(arr.begin(), arr.end());
// this uses make_heap() internally.

// Optimal
// Time: O(n + klogn)

#include <bits/stdc++.h>
using namespace std;

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq(piles.begin(), piles.end());

    int sum = accumulate(piles.begin(), piles.end(), 0);
    int shaved = 0;

    while(k--){
        int top = pq.top();
        int x = ceil(top/2.0);
        shaved += top-x;
        pq.pop();
        pq.push(x);
    }

    return sum - shaved;
}

int main(){
    
    return 0;
}