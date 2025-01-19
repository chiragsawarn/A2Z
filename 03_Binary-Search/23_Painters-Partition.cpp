// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557

// 21, 22, 23 are ditto same problems.
#include <bits/stdc++.h>
using namespace std;

int canDivideArrayIntoKSubarraysWithGivenCapacity(vector<int> &boards, int k, int capacity){
    int countOfSubarrays=1, sum = 0;

    for(int i=0; i<boards.size(); ++i){
        if(boards[i]+sum <= capacity){
            sum += boards[i];
        } else {
            sum = boards[i];
            ++countOfSubarrays;
        }
    }

    return countOfSubarrays <= k; // capacity was enough
}
int findLargestMinDistance(vector<int> &boards, int k){
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    while(low<=high){
        int mid = low + (high-low)/2;
        if(canDivideArrayIntoKSubarraysWithGivenCapacity(boards, k, mid)){
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