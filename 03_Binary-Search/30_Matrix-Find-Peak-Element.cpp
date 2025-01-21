// https://leetcode.com/problems/find-a-peak-element-ii/

// Please study the concept in this question, before proceeding.
// https://leetcode.com/problems/find-peak-element/description/

// Brute Force
// Search the entire space to find the element greater than all its adjacent elements.
// Time: O(nRows*nCols)
// Space: O(1)

// Optimal
// Use binary search to find the row with peak element.
//      Using a linear iteration, find the max element of that row as it already is greater than its left and right.
//      Now to make sure it is also greater than its top and bottom, decrease the search space of rows in the binary search.
//      if(up < mat[row][col] && down < mat[row][col]){
//          return {row, col};
//      } else if(up < mat[row][col]) {
//          // search in the bottom rows, as (down > mat[row][col]) => either downEle is the peak, or there is someone even greater than downEle. Which means down is leading to the peak.
//          low = row + 1; 
//      } else {
//          high = row - 1;
//      }
// Time: O(nCols*log(nRows))
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int low = 0, high = mat.size()-1;

    while(low <= high){
        int row = (low+high)/2;
        auto itr = max_element(mat[row].begin(), mat[row].end());
        int col = itr - mat[row].begin();

        int up = (row == 0) ? -1 : mat[row-1][col];
        int down = (row == mat.size()-1) ? -1 : mat[row+1][col];

        if(up < mat[row][col] && down < mat[row][col]){
            return {row, col};
        } else if(up < mat[row][col]) {
            low = row + 1;
        } else {
            high = row - 1;
        }
    }

    return {};
}

int main(){
    
    return 0;
}