// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// Learning: What does q.front() return when queue is empty? 
// Ans. Program could crash!
// Hence, always call !q.empty() before calling q.front();
#include <bits/stdc++.h>
using namespace std;

// Optimal Approach:-
// Maintain a queue of negative elements' indices. 
// Remove these indices, if they are passed over by the window.
// Add indices to the queue, as window size is increasing.
// Time: O(n)
// Space: O(n) [size of queue]

vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
    queue<int> q;
    vector<int> res;
    int i=0,j=0,n=arr.size();
    
    while(j<n){
        if(arr[j] < 0) q.push(j); // Step 1: Expansion
        while(j-i+1 > k){ // Step 2: Shrinking
            if(!q.empty() && q.front() == i){
                q.pop();
            }
            ++i;
        }
        if(j-i+1 == k){ // Step 3: Answer Calculation
            if(!q.empty()){
                res.push_back(arr[q.front()]);
            } else {
                res.push_back(0);
            }
        }
        ++j; // Step 1: Expansion
    }
    
    return res;
}

int main(){
    
    return 0;
}