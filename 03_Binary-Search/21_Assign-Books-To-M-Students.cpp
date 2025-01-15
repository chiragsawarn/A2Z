// https://www.naukri.com/code360/problems/allocate-books_1090540

// Allocate books in such a way that:
// 1. Each student gets at least one book.
// 2. Each book should be allocated to only one student.
// 3. Book allocation should be in a contiguous manner.
// If allocation of books is not possible return -1

// Brute Force
// for maxPages in range [max_element to sumOfAll]
// check if books can be allotted to M students.
// The first value of maxPage that allows allocation to M students is our answer.

// How to allott books to M students ?
// [25, 46, 28, 49, 24] and m=4
// (5 students)low:49 ------mid:110(2 students)------high:172(1 student) // But I need to do with lesser students (i.e. 4 students) So eleminate right half
// (5 students)low:49 ------mid: 78(3 students)------high:109(2 students) // Same, eliminate right half
// (5 students)low:49 ------mid: 63(5 students)------high:78(3 students)
// (5 students)low:64 ------mid: 71(4 students)------high:78(3 students) => Ans. 71
// Time: O(n^n)
// Space: O(1)

// Optimal
// Use binary search to set maxPages
// Note: low is max_element and not min_element. Coz if we keep max_element each student can hold a book.
// Time: O(nlogn)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

bool canAssignBooksToMStudentsWithAtMaxKPages(vector<int> &arr, int students, int maxPages){
    int studentsCovered = 1, pageCount = 0;
    for(int i=0; i<arr.size(); ++i){
        if(arr[i] > maxPages) return false;
        if(pageCount + arr[i] <= maxPages){
            pageCount += arr[i];
        } else {
            ++studentsCovered;
            pageCount = arr[i];
        }
    }

    return studentsCovered <= students;
}

int findPages(vector<int>& arr, int n, int m) {
    if(n < m) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low<=high){
        int mid = low + (high-low)/2;
        if(canAssignBooksToMStudentsWithAtMaxKPages(arr, m, mid)){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main(){
    
    return 0;
}