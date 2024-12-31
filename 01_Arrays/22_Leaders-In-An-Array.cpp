// Find the elements that are greater than all elements to their right.
// The result is expected in sorted order.
// https://www.naukri.com/code360/problems/superior-elements_6783446

// Brute Force
// Iterate from left to right
// For each element find elements greater than it towards the right. If no element is found greater than it, then push it into the result array.
// Then return the result array after sorting it. As the result is expected in sorted order.
// Time : O(n^2) + O(nlogn)

// Optimal
// Iterate from right to left.
// If an element is greater than the last pushed element in the result array. Then push this element in the result array as well as its the current greatest.
// This approach pushes element in the sorted order by default so need need to sort result array.
// Time : O(n)
// Space: O(n)
#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int>&a) {
    int n = a.size();
    vector<int> res;
    res.push_back(a[n-1]);

    for(int i=n-1; i>=0; i--){
        if(a[i]>res[res.size()-1]){
            res.push_back(a[i]);
        }
    }

    return res;
}

int main(){
    
    return 0;
}