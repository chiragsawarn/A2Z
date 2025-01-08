// Given an array of intervals. Return an array of merged overlapping subintervals.
// https://leetcode.com/problems/merge-intervals/description/

// Brute Force
// Sort it.
// Iterate left to right: if intervals overlap, then update the res array's last interval. else: push the next interval, break the loop. And start over from the beginning.
// Time: O(n^2 + nlogn)
// ExtraSpace: O(n) [To return answer]

// Optimal
// Time: O(n + nlogn)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res = {{intervals[0]}};

    for(int i=1; i<intervals.size(); ++i){
        int lastIdx = res.size()-1;
        if(intervals[i][0] <= res[lastIdx][1]){
            res[lastIdx][1] = max(intervals[i][1], res[lastIdx][1]);
        } else {
            res.push_back(intervals[i]);
        }
    }

    return res;
}

int main(){
    
    return 0;
}