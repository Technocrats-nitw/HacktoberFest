/*

given an array, you have to maximize the points by choosing exactly k values
of the array.

the values can be taken either from the leftmost or from the rightmost end of the
array.

print the maximum points you can make.

time complexity - O(n)

*/

#include<bits/stdc++.h>
using namespace std;
int main() {

	// taking input
	int n, k;
	cin>>n>>k;
	int arr[n+1];

	// taking input of the array
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}

	// initializing the currPoints and maxmPoints to zero
	int currPoints = 0, maxmPoints = 0;

	// finding the sum of the first k points of the array
	for(int i=0;i<k;i++)
		currPoints+=arr[i];

	// finding maximum points
	maxmPoints = max(maxmPoints, currPoints);

	for(int i=(n-1);i>=(n-k);i--) {

		// remove the (k-(n-i))th value of the array from the currPoints sum
		currPoints-=arr[k-(n-i)];

		// add the (i)th value of the array to the currPoints sum 
		currPoints+=arr[i];

		// finding maximum points
		maxmPoints = max(maxmPoints, currPoints);
	}

	// printing maximum points
	cout<<maxmPoints<<endl;
	return 0;
}