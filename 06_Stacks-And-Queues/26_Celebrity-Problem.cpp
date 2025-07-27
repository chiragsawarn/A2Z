// Question: Given a 2D matrix with mat[i][j] == 1 => i knows j
//           We need to find a celecrity such that
//            (1) Everyone knows the celebrity (except itself)
//            (2) The celecrity knows no one.

// https://www.naukri.com/code360/problems/the-celebrity-problem_10728328

// Brute Force
// Time: O(n^2)
// Start from row i=0, iterate over all columns. 
//    if (mat[i][j] == 1) => i is not a celebrity.
//    for all j (mat[i][j] != 1) => This is possibly a celebrity.
//       To confirm, iterate over all the rows for this fixed column, to make sure everyone (except itself) knows it.

// Optimal
// Follow a binary search like 2 pointer style: start and end. (No halving though!)
// if(knows(start, end)) => start is not a celeb
// if(knows(end, start)) => end is not a celeb
// if(!knows(start, end) and !knows(end, start)) => Both are not celebs
// Ultimately, start == end => A candidate for celebrity.
// We verify it, same as brute force verification.
// Time: O(2n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

bool knows(int a, int b){
	// predefined in the problem link
	return true;
}

int findCelebrity(int n) {
 	int start = 0, end = n-1;
	
	while(start<end){
		if(knows(start, end) && !knows(end, start)){
			++start;
		} else if(knows(end, start) && !knows(start, end)){
			--end;
		} else {
			++start;
			--end;
		}
	}

	for(int i=0; i<n; ++i){
		if(i == start) continue;
		if(knows(start, i) || !knows(i, start)) return -1;
	}

	return start;
}

int main(){
    
    return 0;
}