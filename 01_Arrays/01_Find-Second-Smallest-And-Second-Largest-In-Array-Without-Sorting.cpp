// Question Link
// https://www.naukri.com/code360/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse

// Brute Force
// Find maximum using brute force from previous question. 
// Then eliminate maximum from the array. 
// Then find the maximum in the array again, and call it the second maximum.
// Time: O(2*n^2)

// Better
// Sort the array and return second last element as secondLargest.
// Time: O(nlogn)

// Optimal
// Approach 1 : Use a heap of size 2
// To find the second-maximum. 
// In the heap we want the k-th maximum at top, so we will use a min heap. So that the real maximum goes down the heap.
// We push k elements into the heap first to fix its size.
// Then we iterate over the rest of the array starting k to n-1, to push the elements that defeat the top element of the heap. In this process we pop the top element whenever there is a new insertion, thereby maintaining the size of the heap.
// O(nlogk) => O(nlog2) => O(n*1) => O(n)

// Optimal
// Approach 2 : You can also use 2 variables like firstMax and secondMax.
// We use the same heap concept of competing with the secondMax and defeating it, to find place in on of the two variables.
// Note: If firstMax is defeated, then secondMax becomes firstMax.


#include <bits/stdc++.h>
using namespace std;

int find2ndLargest(int &n, vector<int> &a){
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(a[0]);
    pq.push(a[1]);

    for(int i=2; i<n; ++i){
        if(a[i] > pq.top()){
            pq.pop();
            pq.push(a[i]);
        }
    }

    return pq.top();
}

int find2ndSmallest(int &n, vector<int> &a){
    priority_queue<int> pq;
    pq.push(a[0]);
    pq.push(a[1]);

    for(int i=2; i<n; ++i){
        if(a[i] < pq.top()){
            pq.pop();
            pq.push(a[i]);
        }
    }

    return pq.top();
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int secondLargest = find2ndLargest(n,a);
    int secondSmallest = find2ndSmallest(n,a);
    return {secondLargest, secondSmallest};
}


int main(){
    
    return 0;
}