// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/


// Brute Force [Binary search on Answer]
// Learning : Do the function canShipInDdaysWithCapacityK carefully.
// Time: O(nlogn)
// Space: O(1)
#include <bits/stdc++.h>
using namespace std;

int canShipInDdaysWithCapacityK(vector<int>& weights, int days, int capacity){
    int countOfDays = 0, sum = 0;
    
    for(int i=0; i<weights.size(); ++i){
        if(weights[i] > capacity) return false;
        if(sum + weights[i] <= capacity){
            sum += weights[i];
        } else {
            sum = weights[i];
            ++countOfDays;
        }
    }
    if(sum != 0) ++countOfDays;

    return countOfDays <= days;
}
int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while(low <= high){
        int mid = low + (high-low)/2;
        if(canShipInDdaysWithCapacityK(weights, days, mid)){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main(){
    
    return 0;
}