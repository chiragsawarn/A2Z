// Brute Force
// Do a nested loop to do a frequency count.
// Then use the frequency count, to find count of 0 and count of 2
// Time: O(n^2)
// Space: O(n)

// Better
// Do a freq count using an unordered_map.
// Time: O(n)
// Space: O(n)

// Optimal
//  Repeating No : a, Missing No : b
//
//  summation(x) + a + a = actualSum
//  summation(x) + a + b = expectedSum
//(-)_____________________________________________
//                 a - b = actualSum - expectedSum ...(1)

//   summation(x^2) +  a^2 + a^2 = actualSumOfSquares
//   summation(x^2) +  a^2 + b^2 = expectedSumOfSquares
//(-)__________________________________________________
//                  + a^2  - b^2 = actualSumOfSq - expectedSumOfSq

// => (a-b)(a+b) = actualSumOfSq - expectedSumOfSq
// => (a+b) = (actualSumOfSq - expectedSumOfSq)/(actualSum - expectedSum) ...(2)

// Using (1) & (2)
// 2a = (actualSum - expectedSum) + (actualSumOfSq - expectedSumOfSq)/(actualSum - expectedSum)
// 2a = diffS + diffSoS/diffS
//  a = (diffS + diffSoS/diffS)/2

// Time: O(n)
// Space: O(1)
// Mistake: Integer Overflow is likely. So don't do premature divison. Go step by step.

// Optimal Using Xor
// xorr = actualXor ^ expectedXor
// xorr = [4, 3, 6, 2, 1, 1] ^ [1,2,3,4,5,6]
// xorr = [1,1,2,3,4,6] ^ [1,2,3,4,5,6]
// Everything that appears twice vanishes. But Missing and Repeating Numbers remain, as they occur odd times.
// xorr => 1^5 => 101 ^ 001 => 100 => 4
// Now this xorr of missing and repeating no. must have a set bit. As missing and repeating number can't be the same number.
// So, iterate over the [originalArray + naturalNumbers] and push the elements into bucket one that have this bit as set
// Bucket with Bit Set = {4,6 + 4,5,6} => 4^4^5^6^6 => 5 
// Bucket without bit set = {1,1,2,3 + 1,2,3} => 1^1^1^2^2^3^3 => 1
// Next, we xor the elements of each bucket coz the two answers are guaranteed to be in diff buckets because of the difference bit.
//      Secondly, its only the answer elements that occur odd no of times in each bucket.
// Now iterate over the array a third time. To find which element has count 2 and count 0.
// Time: O(3n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int>& arr) {
    long long n = arr.size();

    // Calculate expected sums
    long long expectedSum = (n * (n + 1)) / 2;
    long long expectedSumOfSq = (n * (n + 1) * (2 * n + 1)) / 6;
    
    // Calculate actual sums
    long long actualSum = 0, actualSumOfSq = 0;
    for (int num : arr) {
        actualSum += num;
        actualSumOfSq += (long long)num * num;
    }
    
    // Difference equations
    long long diff = actualSum - expectedSum; // a - b
    long long diffSoS = actualSumOfSq - expectedSumOfSq; // a^2 - b^2
    
    // Derive values of a and b
    long long sum = diffSoS / diff; // a + b
    long long a = (diff + sum) / 2; // Repeating number
    long long b = a - diff;         // Missing number
    
    return {(int)a, (int)b};
}

int main(){
    
    return 0;
}