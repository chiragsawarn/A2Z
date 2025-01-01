// Given n, generate n rows of pascal's triangles.
// Each element of next row is sum of 2 elements of previous row 
// i.e arr[row][j] = arr[row-1][j-1] + arr[row-1][j]
// https://leetcode.com/problems/pascals-triangle/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans = {{1}};
    for(int i=2; i<=numRows; ++i){
        vector<int> arr(i);
        for(int j=0; j<i; ++j){
            int left = (j-1 == -1) ? 0 : ans[i-2][j-1];
            int right = (j == i-1) ? 0 : ans[i-2][j];
            arr[j] = left + right;
        }
        ans.push_back(arr);
    }
    return ans;
}

int main(){
    
    return 0;
}