// Question: https://leetcode.com/problems/fruit-into-baskets/
#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    unordered_map<int,int> mp;
    int i=0,j=0,n=fruits.size(),ans=0;

    while(j<n){
        mp[fruits[j]]++;
        while(mp.size() > 2){
            --mp[fruits[i]];
            if(mp[fruits[i]] == 0){
                mp.erase(fruits[i]);
            }
            ++i;
        }

        ans = max(ans, j-i+1);

        ++j;
    }

    return ans;
}

int main(){
    
    return 0;
}