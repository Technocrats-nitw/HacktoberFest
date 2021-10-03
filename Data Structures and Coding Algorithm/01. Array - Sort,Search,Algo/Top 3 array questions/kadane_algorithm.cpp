/* Find the contiguous subarray within an array, A of length N which has the largest sum. */

#include <bits/stdc++.h>
using namespace std;

// Kadane's Algorithm
int maxSubArray(const vector<int> &A) {
    int max_ending_here = 0;
    int max_so_far = INT_MIN;
    for(int i=0; i<A.size(); i++) {
        max_ending_here += A[i];
        if(max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        if(max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

// TIME COMPLEXITY - O(n)
// SPACE COMPLEXITY - O(1)