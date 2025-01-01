// https://leetcode.com/problems/rotate-image/
#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Use an auxillary result matrix of same dimensions.
// Copy each row over to the result matrix. Starting from the last column to the first.
// Time: O(n^2)
// Space: O(n^2)

// Optimal [Inplace]
// Rotation = Transpose + Reversal [Only this order works, try with a 3x3 matrix]
// 1 2 3                      1 4 7                     7 4 1
// 4 5 6    -- transpose -->  2 5 8   -- reversal -->   8 5 2
// 7 8 9                      3 6 9                     9 6 3
// Time: O(n^2)
// Space: O(1)

void rotate(vector<vector<int>>& matrix) {
    int nrows = matrix.size();
    int ncols = matrix[0].size();

    // transpose matrix
    for(int i=0; i<nrows; ++i){
        for(int j=i; j<ncols; ++j){
            swap(matrix[j][i], matrix[i][j]);
        }
    }
    // reverse each row
    for(int i=0; i<nrows; ++i){
        reverse(matrix[i].begin(), matrix[i].end());
    }

}

int main(){
    
    return 0;
}