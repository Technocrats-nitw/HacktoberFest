#include<bits/stdc++.h>
using namespace std;

/*
	Use various sorting algorithms to sort an array.
*/

void print(int a[], int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << '\n';
}

void bubbleSort(int a[], int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
      }
    }
  }
}

void selectionSort(int a[], int n) {
  for (int i = 0; i < n; ++i) {
    int min = i;
    for (int j = i + 1; j < n; ++j) {
      if (a[min] > a[j]) {
        min = j;
      }
    }
    swap(a[i], a[min]);
  }
}

void insertionSort(int a[], int n) {
  for (int i = 1; i < n; ++i) {
    int min = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > min) {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = min;
  }
}

/* 
  1. For best case TC, lets consider pivot at the median.
   so TC will be O(nlogn)
  2. For worst case TC, O(n^n)
*/
int divide(int a[], int l, int r) {
  int i = l - 1;
  for (int j = l; j < r; ++j) {
    if (a[j] < a[r]) swap(a[++i], a[j]);
  }
  swap(a[i + 1], a[r]);
  return i + 1;
}
void quickSort(int a[], int l, int r) {
  if (l < r) {
    int pi = divide(a, l, r);
    quickSort(a, l, pi - 1);
    quickSort(a, pi + 1, r);
  }
}

int getMax(int a[], int n) {
  int max = a[0];
  for (int i = 1; i < n; ++i)
    if (a[i] > max) max = a[i];
  return max;
}
void countSort(int arr[], int n, int exp) {
  int i, count[10] = {
    0
  }, output[n];
  for (i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
  for (i = 1; i < 10; i++) count[i] += count[i - 1];
  for (i = n - 1; i >= 0; i--) output[--count[(arr[i] / exp) % 10]] = arr[i];
  for (i = 0; i < n; i++) arr[i] = output[i];
}
void radixSort(int a[], int n) {
  int max = getMax(a, n);
  for (int i = 1; max / i > 0; i *= 10) countSort(a, n, i);
}

// TC: max(a[i], n)
void countSort(int a[], int n) {
  int k = a[0], output[n], count[10] = {
    0
  };
  for (int i = 0; i < n; ++i) k = max(k, a[i]);
  for (int i = 0; i < n; ++i) count[a[i]]++;
  for (int i = 1; i <= k; ++i) count[i] += count[i - 1];
  for (int i = n - 1; i >= 0; --i) output[--count[a[i]]] = a[i];
  for (int i = 0; i < n; ++i) a[i] = output[i];
}

void heapify(int H[], int n, int i) {
  int k = i;
  int lc = 2 * i + 1;
  int rc = 2 * i + 2;
  if (lc < n && H[lc] > H[k]) k = lc;
  if (rc < n && H[rc] > H[k]) k = rc;
  if (k != i) {
    swap(H[i], H[k]);
    heapify(H, n, k);
  }
}
void heapSort(int H[], int n) {
  for (int i = n / 2 - 1; i >= 0; --i)
    heapify(H, n, i);
  for (int i = n - 1; i > 0; --i) {
    swap(H[0], H[i]);
    heapify(H, i, 0);
  }
}

void merge(int a[], int m, int l, int r) {
  int i = l, j = m + 1, k = 0;
  int b[r - l + 1];
  while (i <= m || j <= r) {
    if (j > r) b[k++] = a[i++];
    else if (i > m) b[k++] = a[j++];
    else if (a[i] < a[j]) b[k++] = a[i++];
    else b[k++] = a[j++];
  }
  i = 0;
  while (l <= r) a[l++] = b[i++];
}
void mergeSort(int a[], int l, int r) {
  if (l >= r) return;
  mergeSort(a, l, (l + r) / 2);
  mergeSort(a, (l + r) / 2 + 1, r);
  merge(a, (l + r) / 2, l, r);
}

// 012 sort
void dnfSort(int a[], int n) {
  int low = 0, mid = 0, high = n - 1;

  while (mid <= high) {
    if (a[mid] == 0) swap(a[low++], a[mid++]);
    else if (a[mid] == 1) mid++;
    else swap(a[mid], a[high--]);
  }
}

// arr[i-1] >= arr[i] <= arr[i+1]
void wavesort(int a[], int n) {
  for (int i = 0; i < n; i += 2) {
    if (a[i] > a[i - 1]) swap(a[i], a[i - 1]);
    if (a[i] > a[i + 1] && i < n - 2) swap(a[i], a[i + 1]);
  }
}

// improved version of straight insertion sort
// Start with a big gap, then reduce the gap
void shellSort(int arr[], int n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i += 1) {
      int tmp = arr[i], j;

      for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
        arr[j] = arr[j - gap];
      arr[j] = temp;
    }
  }
}

// https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/

int main() {
  int a[] = {5, 1, 1, 2, 0, 0};
  int n = sizeof(a) / sizeof(a[0]);
  // mergeSort(a, 0, n-1);
  // quickSort(a, 0, n-1);
  print(a, n);
}