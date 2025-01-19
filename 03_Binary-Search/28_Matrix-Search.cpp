// https://leetcode.com/problems/search-a-2d-matrix/

// Brute Force
// Iterate over each element of the 2D array to search target.
// Time: O(nRows*nCols)
// Space: O(1)

// Better
// Iterate over the rows
// If target is in range of first and last element of a row.
// Then apply binary search on that row.
// Time: O(nRows + log(nCols))
// Space: O(1)

// Optimal 1 [Imagine the 2D array as a 1D sorted array]
// Now, how to get the 2D index of this 1D sorted array?
// rowIdx = i/nCols; => WE DIVIDE BY nCols BECAUSE: FIRST COL ELEMENTS OF 2D MATRIX HAVE 1D INDEX OF 0 => 4 => 8 {If there are 4 cols}
// colIdx = i%nCols;
// Using this you can iterate over nRows*nCols elements using binary search.
// Time: O(log(nRows*nCols))

// Optimal 2 [Implemented below]
// In the last column find the row that may have the element using binary search
// Then apply binary search on that row if its a valid row.
// Time: O(log(nRows) + log(nCols))

#include <bits/stdc++.h>
using namespace std;

int lowerBoundIdx(vector<vector<int>> &matrix, int target){
    int nRows = matrix.size(), nCols = matrix[0].size();

    int low = 0, high = nRows-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(matrix[mid][nCols-1] < target){
            low = mid+1;
        } else {
            high = mid-1;
        }
    }

    return low;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rowIdx = lowerBoundIdx(matrix, target);
    bool isValidRowIdx = rowIdx >= 0 && rowIdx <= matrix.size()-1;
    if(isValidRowIdx) {
        auto itr = lower_bound(matrix[rowIdx].begin(), matrix[rowIdx].end(), target);
        return *itr == target;
    }
        
    return false;
}

int main(){
    
    return 0;
}