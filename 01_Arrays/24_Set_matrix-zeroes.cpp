// https://leetcode.com/problems/set-matrix-zeroes/
// If an element is zero, set it entire row and col to zero.

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Create an empty matrix of same dimensions, initialized with -1.
// Iterate over original array. If an element is zero. Mark it row and col to zero in the other matrix.
// Then iterate over the copy matrix, and if an element is -1, then copy over its value from original matrix.
// Time: O(n^2) [Just to iterate] x O(2n) [To set zeros] + O(n^2) [To fill in non zero values] => O(2n^3 + n^2)
// Extra Space: O(n^2)

// Better
// Make 2 arrays, one for marking zero rows, and another for marking zero columns.
// Iterate over original array, when you find a zero update the above arrays.
// Then run a loop over your 1D zeroRows to overwrite zeroes. Same for 1D zeroColumns.
// Time : O(n^2) + O(2*n^2) => O(3*n^2)
// Extra Space : O(2n)

// Optimal
// Use the first row and first column as the zeroRows and zeroColumns. 
// Edge Case: Maintain 2 varibles to find zeros if firstRow or firstCol were initially zero.
// Time: O(3*n^2)
// Extra Space: O(1)

void setZeroes(vector<vector<int>>& matrix) {
    int nrows = matrix.size(); 
    int ncols = matrix[0].size();
    bool isRowZero = false, isColZero = false; 

    // Step 1: Finding existing zeros and marking them.
    // Edge Case: First check if first row or col has a zero. 
    // Second, Mark the zeros in first row and col 
    for(int i=0; i<nrows; ++i){
        for(int j=0; j<ncols; ++j){
            if(matrix[i][j] == 0){
                if(i > 0 && j > 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                } else {
                    if(matrix[i][0] == 0) isColZero = true;
                    if(matrix[0][j] == 0) isRowZero = true;
                }
            }
        }
    }

    // Step 2: Use the marked zeros from first row to mark columns zero
    //         And use the marked zeros from first col to mark rows zero
    for(int i=1; i<nrows; ++i){
        if(matrix[i][0] == 0){
            for(int j=1; j<ncols; ++j){
                matrix[i][j] = 0;
            }
        }
    }
    for(int j=1; j<ncols; ++j){
        if(matrix[0][j] == 0){
            for(int i=0; i<nrows; ++i){
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: If first row or col was initially zero. Mark it zero.
    if(isRowZero) {
        for(int j=0; j<ncols; ++j){
            matrix[0][j] = 0;
        }
    }
    if(isColZero) {
        for(int i=0; i<nrows; ++i){
            matrix[i][0] = 0;
        }
    }
}

int main(){
    
    return 0;
}