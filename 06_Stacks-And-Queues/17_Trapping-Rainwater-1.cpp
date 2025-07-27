// https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

// Better : Preprocess leftMax in an array. Overwrite this array to compare with rightMax.
// Time: O(2n)
// Space: O(n)

int trap_better(vector<int>& height) {
    vector<int> x;
    int ans = 0;

    int leftMax = 0;
    for(int i=0; i<height.size(); ++i){
        leftMax = max(leftMax, height[i]);
        x.push_back(leftMax);
    }

    int rightMax = 0;
    for(int i=height.size()-1; i>=0; --i){
        rightMax = max(rightMax, height[i]);
        ans += min(x[i], rightMax) - height[i];
    }

    return ans;
}

// Optimal : Use two pointers for leftMax and rightMax simultaneously.
// Time: O(n)
// Space: O(1)



int main(){
    
    return 0;
}