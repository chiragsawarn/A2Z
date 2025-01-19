// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

// Optimal
// Time: O(nRows*log(nCols))
#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &arr) {
    // code here
    int maxCountOf1s = -1, maxCountIdx = -1;
    for(int i=0; i<arr.size(); ++i){
        auto itr = lower_bound(arr[i].begin(), arr[i].end(), 1);
        if(itr != arr[i].end()){
            int countOf1s = arr[i].end() - itr;
            if(countOf1s > maxCountOf1s){
                maxCountOf1s = countOf1s;
                maxCountIdx = i;
            }
        }
    }
    return maxCountIdx;
}

int main(){
    
    return 0;
}