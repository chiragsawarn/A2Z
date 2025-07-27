// Question : Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// https://leetcode.com/problems/maximal-rectangle/description/

// Optimal
// Step 1: Convert each column into a prefix sum of all above values in the same column.
//         Note: if current value of a cell is 0, then it can't add above values in the same column. Cummulative prefix value in this case becomes 0.
// Step 2: Iterate over each row of prefixSumMatrix and apply the largestAreaOfHistogram function.
// Step 3: return the maximumArea found from all rows.

// Time: O(nrows*ncols) [to find prefixSumMatrix] + O(ncols*nrows) [to find maxArea of each row] => O(2*ncols*nrows)
// Space: O(ncols*nrows) [to find prefixSum Matrix] + O(ncols) [for stack] => O(ncols*nrows + ncols)


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> prefixColSum(vector<vector<char>>& matrix){
    int nrows = matrix.size();
    int ncols = matrix[0].size();
    vector<vector<int>> ans(nrows, vector<int>(ncols, 0));

    for(int j=0; j<ncols; ++j){
        for(int i=0; i<nrows; ++i){
            if(matrix[i][j] == '1'){
                int prevSum = (i == 0) ? 0 : ans[i-1][j];
                ans[i][j] = prevSum + 1;
            }
        }
    }

    return ans;
}
int findMaxAreaOfHistogram(vector<int> &heights){
    stack<int> st;
    int n = heights.size();
    int maxArea = 0;

    for(int i=0; i<n; ++i){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            int nseIdx = i;
            int height = heights[st.top()];
            st.pop();
            int pseIdx = st.empty() ? -1 : st.top();
            int width = nseIdx - pseIdx - 1;
            int area = height*width;
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }

    while(!st.empty()){
        int nseIdx = n;
        int height = heights[st.top()];
        st.pop();
        int pseIdx = st.empty() ? -1 : st.top();
        int width = nseIdx - pseIdx - 1;
        int area = height*width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int nrows = matrix.size();
    int ncols = matrix[0].size();

    vector<vector<int>> mat = prefixColSum(matrix);
    int maxArea = 0;

    for(int i=0; i<nrows; ++i){
        int maxAreaOfMatrixTillIthRow = findMaxAreaOfHistogram(mat[i]);
        maxArea = max(maxArea, maxAreaOfMatrixTillIthRow);
    }

    return maxArea;
}

int main(){
    
    return 0;
}