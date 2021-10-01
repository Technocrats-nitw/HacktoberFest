// Given an unsorted integer array, find the first missing positive integer.

#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for (auto &x : A) {
        if (x < 1) {
            x = n+1;
        }
    }
    for (int i=0; i<n; i++) {
        if(abs(A[i]) <= n) {
            A[abs(A[i])-1] = -abs(A[abs(A[i])-1]);
        }
    }
    for (int i=0; i<n; i++) {
        if(A[i] > 0) {
            return i+1;
        }
    }
    return n+1;
}

// TIME COMPLEXITY - O(n)
// SPACE COMPLEXITY - O(1)
