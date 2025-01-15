// https://www.naukri.com/code360/problems/aggressive-cows_1082559

// Brute Force
// Do a linear search in the cowGapRange [max-min to 1]
// For each cowGap check if placing k cows is possible or not.
// The first cowGap that comes out as possible is your answer for maximumCowGap that can place k cows.
// Time: O(nlogn) [To sort array] + O((max-min)*k*logn)

// Optimal
// Use binary search for outer loop. Rest is same.
// Note: We dont "return low" at the end. Coz in this question high has the correct opposite polarity.
// Time: O(nlogn) [To sort array] + O(log(max-min)*k*logn) [k*log(n) is for canStorekCowsAtGivenDist] => O(nlogn + (max-min)*k*logn)
#include <bits/stdc++.h>
using namespace std;

bool canStorekCowsAtGivenDist(vector<int> &stalls, int k, int dist){
    int lastStoredCowPos = stalls[0];
    while(--k){
        int nestCowStorePos = lastStoredCowPos + dist;
        auto itr = lower_bound(stalls.begin(), stalls.end(), nestCowStorePos);
        if(itr == stalls.end()){
            return false;
        } else {
            lastStoredCowPos = *itr;
        }
    }
    return true;
}
int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end());

    while(low<=high){
        int mid = low + (high-low)/2;
        if(canStorekCowsAtGivenDist(stalls, k, mid)){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return high; 
    // Why high and not low?
    // Coz High started off as impossible! 
    // But now it has gained opposite polarity so its possible!
    // Note: high is same as low - 1. So you can also return that.
}
int main(){
    
    return 0;
}