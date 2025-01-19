// Search in a matrix sorted in a ripple wave manner.
// https://leetcode.com/problems/search-a-2d-matrix-ii/description/
// Example : -
// Input: matrix = [[ 1, 4, 7,11,15],
//                  [ 2, 5, 8,12,19],
//                  [ 3, 6, 9,16,22],
//                  [10,13,14,17,24],
//                  [18,21,23,26,30]]
//       target = 5
// Output: true

// Brute Force
// Iterate over each element of the 2D array to search target.
// Time: O(nRows*nCols)
// Space: O(1)

// Better
// Iterate over the rows
// If target is in range of first and last element of a row.
// Then apply binary search on that row.
// NOTE : You will have to apply binary search on multiple rows in this question.
// Time: O(nRows*log(nCols))
// Space: O(1)

// Optimal
// If you start from the top right corner. 
// Then you can see that LHS is decreasing in sorted manner.
//                       DOWNSIDE is increasing in sorted manner.
// Time: O(nRows + nCols)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int nRows = matrix.size(), nCols = matrix[0].size();

    int i=0, j=nCols-1;

    while(i<nRows && j>-1){
        if(matrix[i][j] == target){
            return true;
        } else if(matrix[i][j] < target){
            ++i;
        } else {
            --j;
        }
    }

    return false;
}

int main(){
    
    return 0;
}