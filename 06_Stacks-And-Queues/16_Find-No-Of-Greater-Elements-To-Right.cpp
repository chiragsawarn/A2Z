// Question: Count the number of strictly greater elements to the right
// https://www.naukri.com/code360/problems/count-of-greater-elements-to-the-right_8365436?leftPanelTabValue=PROBLEM
// Note: Stack not needed.

#include <bits/stdc++.h>
using namespace std;

vector<int> countGreater(vector<int>&arr, vector<int>&query) {
    vector<int> ans;
    for(int i=0; i<query.size(); ++i){
        int count = 0;
        for(int j=query[i]+1; j<arr.size(); ++j){
            if(arr[j] > arr[query[i]]){
                ++count;
            }
        }
        ans.push_back(count);
    }
    return ans;
}

int main(){
    
    return 0;
}