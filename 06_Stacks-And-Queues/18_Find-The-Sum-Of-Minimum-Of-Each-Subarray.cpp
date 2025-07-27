// Question: Create all possible subarrays of an array.
//           Then find the minimum element in each subarray.
//           Return the sum of these minimums. 
//           Use modulo 10^9 + 7.  
// https://leetcode.com/problems/sum-of-subarray-minimums/

#include <bits/stdc++.h>
using namespace std;

vector<int> findNextSmallerThanEqualToElement(vector<int>& arr){
    stack<int> st;
    int n = arr.size();
    vector<int> nse(n);
    for(int i=n-1; i>=0; --i){
        while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if(st.empty()){
            nse[i] = n;
        } else {
            nse[i] = st.top();
        }
        st.push(i);
    }

    return nse;
}
vector<int> findPrevSmallerElement(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> ps(n);

    for(int i=0; i<n; ++i){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if(st.empty()){
            ps[i] = -1;
        } else {
            ps[i] = st.top();
        }
        st.push(i);
    }

    return ps;
}
vector<int> findNoOfSubarraysIndexIsMinimumIn(vector<int> &nse, vector<int> &ps){
    int n = nse.size();
    long long m = 1e9+7;
    vector<int> noOfSubarraysIdxIsMinimumIn(n);

    for(int i=0; i<n; ++i){
        noOfSubarraysIdxIsMinimumIn[i] = ((nse[i]-i)%m*(i-ps[i])%m)%m;
    }

    return noOfSubarraysIdxIsMinimumIn;
}
void print(vector<int>& arr, string desc){
    cout<<desc<<" : ";
    for(int i=0; i<arr.size(); ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int sumSubarrayMins(vector<int>& arr) {
    vector<int> nse = findNextSmallerThanEqualToElement(arr);
    vector<int> ps = findPrevSmallerElement(arr);
    vector<int> noOfSubarraysIdxIsMinimumIn = findNoOfSubarraysIndexIsMinimumIn(nse, ps);
    long long m = 1e9+7;

    long long ans = 0;
    for(int i=0; i<arr.size(); ++i){
        ans = ((ans%m) + (arr[i]%m*noOfSubarraysIdxIsMinimumIn[i]%m)%m)%m;
    }

    return ans;
}

int main(){
    
    return 0;
}