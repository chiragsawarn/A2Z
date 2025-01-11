// https://www.naukri.com/code360/problems/implement-upper-bound_8165383

// Definition of Upper Bound
// The lowest-index of the number which is just greater than x.
// If there is no such number, upper bound is the size of the array.

// NOTE: Lower bound aur upper bound mein difference bas >= aur > ka hai.

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n){
	int low = 0, high = n-1, ansIdx = n;
	do {
		int mid = (high+low)/2;
		if(arr[mid] > x){
			ansIdx = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}while(low<=high);

	return ansIdx;
}

int upperBound_stl(vector<int> &arr, int x, int n){
	auto itr = upper_bound(arr.begin(), arr.end(), x);
	return itr - arr.begin();
}

int main(){
    
    return 0;
}