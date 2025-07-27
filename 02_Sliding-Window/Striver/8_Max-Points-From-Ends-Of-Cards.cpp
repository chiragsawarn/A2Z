// Question: Given an array of cards with some numbers on them. You have to pick exactly `k` cards.
//           Constraint: You can only pick cards from left or right end. And in a continuous manner.
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// Optimal
// Pick all k cards from left first.
// Then lose the inner most card, and in its place pick one from the right.
// Time: O(2k)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int j=n-1, currSum=0, maxSum=0;

    for(int i=0; i<k; ++i){
        currSum += cardPoints[i];
    }
    maxSum = currSum;

    for(int i=0; i<k; ++i){
        currSum -= cardPoints[k-1-i];
        currSum += cardPoints[n-1-i];
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main(){
    
    return 0;
}