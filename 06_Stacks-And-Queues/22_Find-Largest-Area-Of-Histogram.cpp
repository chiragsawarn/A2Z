// Question: Find the largest rectangle in terms of area in a histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/

// Brute Force
// iterate over each element in heights array.
//    for each height[i] expand outwards in each direction as long as you can maintain height[i] as the minimum height.
// Time: O(n^2)
// Space: O(1)

// Better
// Example: heights = [ 2, 1, 5, 6, 2, 3]
//           pseIdx = [-1,-1, 1, 2, 1, 4]
//           nseIdx = [ 1, 6, 4, 4, 6, 6]
// Max Width With Height[i] => nseIdx - i + i - pseIdx - 1 => nseIdx - pseIdx - 1
// Area of each rectangle   => height[i] x (nseIdx - pseIdx - 1)
// Time: O(2n) [To find nse] + O(n) [clear stack] + O(2n) [To find pse] => O(5n)
// Space: O(2n) [stack + answer array that stores nse for each element]

// Optimal
// You traverse heights[] from 0->n, and compute pse for each element using the stack.
// The problem is how do you compute nse for each element on the fly?
// Then you will only need one loop and zero answer storage space.
// Time: O(n) [To process heights array] + O(n) [To empty stack] => O(2n)
// Space: O(n) [stack]

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea_better(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    vector<int> ans(n,0);

    // previous smaller element
    for(int i=0; i<n; ++i){
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // clear stack
    while(!st.empty()) st.pop();
    long long maxArea = 0;

    // next smaller element
    for(int i=n-1; i>=0; --i){
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        int ns = st.empty() ? n : st.top();
        long long width = ns - ans[i] - 1;
        long long area = heights[i]*width;
        maxArea = max(area, maxArea);
        st.push(i);
    }

    return maxArea;
}

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int n = heights.size();
    int maxArea = 0;

    for(int i=0; i<n; ++i){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            int nse = i;
            int height = heights[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int width = nse - pse - 1;
            int area = height*width;
            maxArea = max(maxArea, area);
        }

        st.push(i);
    }

    while(!st.empty()){
        int nse = n;
        int height = heights[st.top()];
        st.pop();
        int pse = st.empty() ? -1 : st.top();

        int width = nse - pse - 1;
        int area = height*width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main(){
    
    return 0;
}