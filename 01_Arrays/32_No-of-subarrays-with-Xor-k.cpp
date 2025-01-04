// https://www.interviewbit.com/problems/subarray-with-given-xor/

// Optimal
// Same concept at 14_count of subarrays with sum k
// Time: O(n)
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int b) {
    unordered_map<int,int> mp = {{0,1}}; // {prefixXor, noOfTimesItOccurs}
    int xorr = 0, numOfSubarraysWithXorB = 0;
    int mask = b;

    for(int i=0; i<a.size(); ++i){
        xorr ^= a[i];
        int x = xorr^mask; // flips second bit from LSB
        // if x^xorr => 0010 => 2 => b
        // Now we only need to check if we have seen x before
        if(mp.find(x) != mp.end()){
            numOfSubarraysWithXorB += mp[x];
        }
        mp[xorr] += 1;
    }

    return numOfSubarraysWithXorB;
}


int main(){
    
    return 0;
}