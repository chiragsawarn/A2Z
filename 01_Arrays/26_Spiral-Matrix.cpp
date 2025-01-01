// https://leetcode.com/problems/spiral-matrix/
#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int nrows = matrix.size();
    int ncols = matrix[0].size();
    int top = 0, left = 0, bottom = nrows - 1, right = ncols - 1;
    vector<int> res;

    while(left <= right && top <=bottom){
        for(int i=left; i<=right; ++i){
            res.push_back(matrix[top][i]);
        }
        ++top;

        for(int i=top; i<=bottom; ++i){
            res.push_back(matrix[i][right]);
        }
        --right;

        // This condition added later to handle the edge case of having a single row
        // <--------------->
        if (top <=bottom) {
            for(int i=right; i>=left; --i){
                res.push_back(matrix[bottom][i]);
            }
            --bottom;
        }

        // This condition is also added later to handle the edge case of having a single column
        if (left <= right) {
            for(int i=bottom; i>=top; --i){
                res.push_back(matrix[i][left]);
            }
            ++left;
        }
    }

    return res;
}

int main(){
    
    return 0;
}