// https://leetcode.com/problems/koko-eating-bananas/description/

// Brute Force
// Find Max no of bananas in a pile. That will be the maximum speed of eating.
// k: 1 -> maxNoOfBananasInAPile : We try out all the answers one by one.
// And in a nested loop, for each possible answer, we iterate over the piles array and find the hours needed to eat all bananas.
// If (hours <= h) => Return K 
// Logic: As K if moving from low to high linearly, the first k you find will be the answer.
// Time: O(maxNoOfBananasInAPile*noOfPiles) => O(n^2)
// Space: O(1)

// Optimal
// Instead of going linearly K:1 -> maxNoOfBananasInAPile, use binary search
// If hours are not enough, increase K
// If hours are excess, decrease K.
// Time: O(noOfPiles*log(maxNoOfBananasInAPile))
// Space: O(1)

// Learning 1 : Ceil(a/b) <==> (a + b - 1)/2;

// Learning 2 : Change in polarity!
// Before BS : low (impossible answer) <----------------------> high (possible answer)
// After BS  : <------high(impossible answer)  -  low (possible answer) --------->
// This is why we dont need to maintain a possible answer variable. We can direcly return low.

#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed_bruteForce(vector<int>& piles, int h) {
    int maxEle = *max_element(piles.begin(), piles.end());
    for(int k=1; k<=maxEle; ++k){
        long hours = 0;
        for(int i=0; i<piles.size(); ++i){
            hours += ceil((long)piles[i]/float(k));
        }
        if(hours <= h){
            return k;
        }
    }

    return -1;
}

long long findHoursNeeded(vector<int> &piles, int k){
    long long hours = 0;
    for(int i=0; i<piles.size(); ++i){
        // Avoid overflow by using division first
        hours += (piles[i] + k - 1) / k;
    }
    return hours;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int maxNoOfBananasInAPile = *max_element(piles.begin(), piles.end());
    int low = 1, high = maxNoOfBananasInAPile;
    // int minK = maxNoOfBananasInAPile;
    while(low<=high){
        int k = low + (high - low)/2;
        long long hours = findHoursNeeded(piles, k);
        if(hours <= h){
            // minK = min(minK, k);
            high = k-1;
        } else {
            low = k + 1;
        }
    }

    return low;
    // return minK;
}

int main(){
    
    return 0;
}