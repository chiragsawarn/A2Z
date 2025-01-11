// https://www.naukri.com/code360/problems/lower-bound_8165382

// DEFINITION of Lower_bound
// For a sorted array 'arr', 'lower_bound' of a number 'x' is defined as the "smallest index" 'idx' such that the value 'arr[idx]' is not less than 'x'.
// If all numbers are smaller than 'x', then 'n' should be the 'lower_bound' of 'x', where 'n' is the size of array.

// To find lower bound:
// We don't return mid, when arr[mid] == x
// Why? Because lower bound is the "lowest index"
// 1 1 1 1 1 and x = 1
// Ans. ansIdx = 2 => If you return directly. Which is wrong! 
// The least index of the lower_bound is 0.

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
	int low = 0, high = n-1, ansIdx = n;

	do{
		int mid = (low+high)/2;
		if(arr[mid] < x){
			low = mid + 1;
		} else {
			ansIdx = mid;
			high = mid-1;
		}
	}while(low<=high);

	return ansIdx;
}

int lowerBound_stl(vector<int> arr, int n, int x) {
	auto itr = lower_bound(arr.begin(), arr.end(), x);
	return itr - arr.begin();
}

int main(){
    
    return 0;
}