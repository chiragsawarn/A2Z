// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?category%5B%5D=Hash&company%5B%5D=Amazon&page=1&query=category%5B%5DHashcompany%5B%5DAmazonpage1company%5B%5DAmazoncategory%5B%5DHash&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-subarray-with-0-sum

// Optimal
// Same concepts as 13_longest subarray with sum K, including negatives.
// Time: O(n)
// Space: O(n)
#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int>& arr) {
    unordered_map<int,int> mp = {{0,-1}};
    int sum = 0, ans = 0;
    
    for(int i=0; i<arr.size(); ++i){
        sum += arr[i];
        if(mp.find(sum) != mp.end()){
            int len = i - mp[sum];
            ans = max(ans, len);
        } else {
            mp[sum] = i;
        }
    }
    
    return ans;
}

int main(){
    
    return 0;
}