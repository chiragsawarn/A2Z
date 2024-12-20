// https://leetcode.com/problems/intersection-of-two-arrays/
// NOTE: This is not an array question as arrays are not sorted, so we use unordered set.
#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> vis;

    for(int i=0; i<nums1.size(); ++i){
        vis.insert(nums1[i]);
    }

    vector<int> res;
    for(auto val:nums2){
        if(vis.find(val) != vis.end()){
            vis.erase(val); // To eliminate duplicates being pushed into res array
            res.push_back(val);
        }
    }

    return res;
}

int main(){
    
    return 0;
}