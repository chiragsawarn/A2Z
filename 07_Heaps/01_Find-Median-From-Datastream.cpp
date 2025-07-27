// QUESTION : Find the meadian from a datastream.
// You will receive a number or queries 10^4. You may have to add an element, or find the median.
// https://leetcode.com/problems/find-median-from-data-stream/

// Optimal
// Consider 2 heaps.
// leftSide is a maxHeap, rightSide is a minHeap.
// [[1,2,3,4] [5,6,7,8]]
// 4 -> top of maxHeap
// 5 -> top of minHeap
// Median = (n%2 == 0) ? (minHeap.top() + maxHeap.top())/2.0 : maxHeap.top();
// Note: We are assuming leftSide will have equal or one more element in case of odd no. of total elements.

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top() > num){
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int n = maxHeap.size() + minHeap.size();

        if(n&1){
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top())/2.0;
        }
    }
};

int main(){
    
    return 0;
}