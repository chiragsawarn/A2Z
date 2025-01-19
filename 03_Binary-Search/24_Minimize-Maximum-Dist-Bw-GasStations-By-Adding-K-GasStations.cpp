// https://www.naukri.com/code360/problems/minimise-max-distance_7541449
#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Maintain an array previousInsertionsOfGasStationsAtThisIdx => this will help find max dist bw 2 gas stations.
//      We need this array coz if we do a hard insertion :-
//      4, 8 ==Itr1==> 4, "6", 8 ==Itr2==> 4, "5", "6", 8 {THIS IS WRONG!!!}
//      That why don't do a hard insertion. We do soft insertions.
//      4, 8 priorInsertionsAtIdx0:{0} 
//      ==Itr1==> 4, 8  priorInsertionsAtIdx0:{1} SIGNIFIES: [4, "6", 8]
//      ==Itr2==> 4, 8  priorInsertionsAtIdx0:{2} SIGNIFIES: [4, "5.33", "6.66", 8]
// We iterate over the gas stations to place K stations one by one.
//      In a nested loop, we iterate over N items of arr, to find the max distance bw 2 gas stations.
// Time: O(k*n)
// Space: O(n) [For prevInsertionAtIdx array]
double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> prevInsertions(n-1, 0);

	for(int i=0; i<k; ++i){
		double maxDiff = -1;
		int maxDiffIdx = -1;
		for(int j=1; j<n; ++j){
			double diffOriginal = arr[j] - arr[j-1];
			int nSec = prevInsertions[j-1] + 1; // As no of sec are 1 more than the no of insertions
			double diffEff = diffOriginal/nSec;
			if(diffEff > maxDiff){
				maxDiff = diffEff;
				maxDiffIdx = j-1;
			}
		}
		prevInsertions[maxDiffIdx]++;
	}

	double maxDiff = -1;
	for(int j=1; j<n; ++j){
		double diff = double(arr[j]-arr[j-1])/(prevInsertions[j-1]+1);
		maxDiff = max(maxDiff, diff);
	}
	
	return maxDiff;
}

// Better 
// Use a max heap to store all the distances in an ascending order with their index.
// Maintain an array that denotes the no of gasstations we have already installed at i-th index.
// Then iterate over the k gas stations we have to add:-
//      Add the station on to the maximum distance index, at heap.top() => gives the index {heap.top().second} of insertion of new gas station.
//      numOfSectionsAtThisIndex = (noOfPriorInsertions[index]+1)
//      Now the "original distance at this index" is reduced to newDiff = diffInOriginalArray/(numOfSectionsAtThisIndex+1)
//      heap.push({newDiff, index})
// At the end whatever remains at the top of heap is the minimum maximum distance bw 2 gas stations after adding k stations optimally.
// Time: O(nlogn + klogn)
// Space: O(n) [For priorInsertionsAtIndex array] + O(n) [For heap]
double minimiseMaxDistance(vector<int> &arr, int k){
	// lets start placing gas stations one by one.
	int n = arr.size();
	vector<int> insertions(n-1,0);

	priority_queue<pair<double,int>> q;

	for(int i=1; i<n; ++i){
		int diff = arr[i]-arr[i-1];
		q.push({diff, i-1});
	}

	for(int i=0; i<k; ++i){
		auto p = q.top();
		q.pop();
		++insertions[p.second];
		double diff = arr[p.second + 1] - arr[p.second];
		int nSections = insertions[p.second]+1;
		double newDiff = diff/nSections;
		q.push({newDiff, p.second});
	}

	auto p = q.top();

	return p.first;
}

// Optimal
// Use binary search on the answer.
// This binary search on answer is different from the rest to read carefully.
// Time: O(n*log(maxDiff)) + O(n) [To find maxDiff]
// Space: O(1)

int findMaxDiff(vector<int> &arr){
	int maxDiff = -1;
	for(int i=1; i<arr.size(); ++i){
		int diff = arr[i] - arr[i-1];
		maxDiff = max(maxDiff, diff);
	}
	return maxDiff;
}

bool check(vector<int> &arr, int k, double maxDist){
	for(int i=1; i<arr.size(); ++i){
		double diff = arr[i]-arr[i-1];
		int nSec = ceil(diff/maxDist);
		int nGasStn = nSec-1;
		k -= nGasStn;
		if(k < 0) return false;
	}
	return true;
}
double minimiseMaxDistance(vector<int> &arr, int k){
	double low = 0;
	double high = findMaxDiff(arr);

	while(high-low> 0.000001){
		double mid = low + (high-low)/2;
		if(check(arr, k, mid)){
			high = mid; // To reduce maxDist
		}else{
			low = mid; // To increase maxDist
		}
	}

	// Opposite polarity doesn't work here. As there is no high = mid -1 here.
	// We return high here because this is where we saw the last possible answer.

	return high; 
}

int main(){
    
    return 0;
}