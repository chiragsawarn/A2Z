// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

// Brute Force
// for days in 1 to max(daysToBloom):
//      Iterate over [ 👍 👍 👍 👎 👎 👍 ] to find how many bouquets are possible.
// Time: O(n^2)
// Space: O(1)

// Optimal
// Use a binary search for outer loop. Rest is same as brute force.
// Time: O(log(maxInArray-minInArray)*n)
// Space: O(1)
// Learning: areMbouquetsPossibleInXdays() this is thinking part of the question.
//           Use a counter for consecutiveElements.
//            => Mark counter = 0; // When continuity breaks
//              OR
//            => Mark counter = 0; // When (counter == k) => You cash out this bouquet.

#include <bits/stdc++.h>
using namespace std;

// VERY VERY IMPORTANT fn()
bool areMbouquetsPossibleInXdays(vector<int>& bloomDay, int m, int k, int x){
    int n = bloomDay.size();
    int bouquetsFormed=0, consecutiveElementsCount=0;
    
    for(int i=0; i<n; ++i){
        if(bloomDay[i] <= x){
            ++consecutiveElementsCount;
        } else {
            consecutiveElementsCount = 0;
        }

        if(consecutiveElementsCount == k){
            ++bouquetsFormed;
            consecutiveElementsCount = 0;
        }
    }

    return bouquetsFormed >= m;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    if(long(m)*k > bloomDay.size()) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    while(low <= high){
        int mid = (low+high)/2;
        if(areMbouquetsPossibleInXdays(bloomDay, m, k, mid)){
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