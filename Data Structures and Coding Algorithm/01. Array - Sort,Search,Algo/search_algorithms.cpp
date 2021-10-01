#include <bits/stdc++.h>
using namespace std;

/*
    Some search algoritms :)
*/

int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}

// O(sqrt(N))
// should be a sorted array
int jumpSearch(int L[], int length, int key) {
  int left = 0;
  int right = sqrt(length);

  while (right < length && L[right] <= key) {
    left = right;
    right += sqrt(length);
    if (right > length - 1) right = length;
  }
  for (int i = left; i < right; i++)
    if (L[i] == key) return i;
  return -1;
}

/*
	Interpolation search works better than Binary Search 
	for a sorted and uniformly distributed array.
	On average the interpolation search makes about 
	log(log(n)) comparisons **(if the elements are uniformly distributed)**
	In the worst case (for instance where the numerical values of the keys 
	increase exponentially) it can make up to O(n) comparisons. 
*/
int interpolationSearch(int arr[], int n, int x) {
  int lo = 0, hi = (n - 1);
  while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
    if (lo == hi) {
      if (arr[lo] == x) return lo;
      return -1;
    }
    int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
    if (arr[pos] == x) return pos;
    if (arr[pos] < x) lo = pos + 1;
    else hi = pos - 1;
  }
  return -1;
}

int interpolationSearchRecurssive(int arr[], int lo, int hi, int x) {
  int pos;
  if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
    pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
    if (arr[pos] == x) return pos;
    if (arr[pos] < x) return interpolationSearchRecurssive(arr, pos + 1, hi, x);
    if (arr[pos] > x) return interpolationSearchRecurssive(arr, lo, pos - 1, x);
  }
  return -1;
}

/*
	Exponential search involves two steps:  
		1. Find range where element is present
		2. Do Binary Search in above found range.
	TC : O(Log n)
*/
int exponentialSearch(int arr[], int n, int x) {
  if (arr[0] == x) return 0;
  int i = 1;
  while (i < n && arr[i] <= x) i = i * 2;
  return binarySearch(arr, i / 2, min(i, n), x);
}

int ternarysearch(int arr[], int key, int low, int high) {
  if (high - low > 0) {
    int mid1 = low + (high - low) / 3;
    int mid2 = mid1 + (high - low) / 3;
    if (key == arr[mid1]) return mid1;
    if (key == arr[mid2]) return mid2;
    if (key < arr[mid1]) return ternarysearch(arr, key, low, mid1);
    if (key > arr[mid2]) return ternarysearch(arr, key, mid2 + 1, high);
    return ternarysearch(arr, key, mid1, mid2);
  }
  return -1;
}

int fibbonaccSearch(int arr[], int x, int n) {
  int fibMMm2 = 0;
  int fibMMm1 = 1;
  int fibM = fibMMm2 + fibMMm1;
  while (fibM < n) {
    fibMMm2 = fibMMm1;
    fibMMm1 = fibM;
    fibM = fibMMm2 + fibMMm1;
  }
  int offset = -1;
  while (fibM > 1) {
    int i = min(offset + fibMMm2, n - 1);
    if (arr[i] < x) {
      fibM = fibMMm1;
      fibMMm1 = fibMMm2;
      fibMMm2 = fibM - fibMMm1;
      offset = i;
    } else if (arr[i] > x) {
      fibM = fibMMm2;
      fibMMm1 = fibMMm1 - fibMMm2;
      fibMMm2 = fibM - fibMMm1;
    } else return i;
  }
  if (fibMMm1 && arr[offset + 1] == x) return offset + 1;
  return -1;
}

int main() {}