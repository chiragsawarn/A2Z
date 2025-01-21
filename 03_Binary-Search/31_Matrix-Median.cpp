// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

// Brute Force
// Merge all rows into a merged sorted array, then return the element on middle index.
// Time: O(nRows*nCols)
// Space: O(nRows*nCols)

// Optimal
// If we can't iterate over each element, we will have to skip some elements, so lets think in the direction of binary search.
// Lets take low and high from the constraints of elements in matrix[i][j]
// ...And do a binary search on answer.
// We need find the lowest element that has findCountLessThanEqualToIt > (nRows*nCols)/2
// Time: O(nRows*log(nCols)) [findCountLessThanEqualToX] x O(log(range(matrix[i][j])))
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int findCountLessThanEqualToX(vector<vector<int>> &matrix, int x){
    int count = 0;
    for(int i=0; i<matrix.size(); ++i){
        auto itr = upper_bound(matrix[i].begin(), matrix[i].end(), x);
        count += itr - matrix[i].begin();
    }
    return count;
}

int median(vector<vector<int>> &mat) {
    int nRows = mat.size(), nCols = mat[0].size();
    int halfOfTotal = (nRows*nCols)/2;
    
    int low = 1, high = 2000; // Constrains of the question: range of mat[i][j]
    
    while(low<=high){
        int mid = low + (high-low)/2;
        int count = findCountLessThanEqualToX(mat, mid);

        if(count > halfOfTotal) {
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