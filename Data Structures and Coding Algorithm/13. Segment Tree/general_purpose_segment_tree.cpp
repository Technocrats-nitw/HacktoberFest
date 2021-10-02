//This is a code for implementing a general puropose segment tree
//The code can be reused as a blackbox by just changing the range funtion and the identity element for that function
//A dummy use is given in the main fucntion for reference
#include<bits/stdc++.h>
using namespace std;
//implementation starts here
const int N = 1e5 + 2;		//maximum no. of elements in the array for range queries
vector<int> segarr(N);		//array to store the array over which range queries will be performed
vector<int> segtree(4 * N);		//array to build segment tree upon
int seg_id = 0;		//identity element of the range function
int segfun(int a, int b)		//defining the range funtion here
{
	int ans = a + b;		//sum function used as an example
	return ans;
}
void build(int index, int left, int right)		//function to build the segment tree
{
	if (left > right)		//out of bound range
	{
		return;
	}
	int mid = left + (right - left) / 2;
	if (left == right)		//single point range
	{
		segtree[index] = segarr[mid];
		return;
	}
	build(2 * index + 1, left, mid);		//build the left segment subtree
	build(2 * index + 2, mid + 1, right);		//build the right segment subtree
	int a = segtree[2 * index + 1];
	int b = segtree[2 * index + 2];
	segtree[index] = segfun(a, b);		//apply the range function over theleft and right segment subtree
}
int query(int index, int left, int right, int l, int r)		//function to query range function from l to r
{
	if (r < left || l > right)		//no overlap
	{
		return seg_id;
	}
	if (l <= left && r >= right)		//complete overlap
	{
		return segtree[index];
	}
	//partial overlap
	int mid = left + (right - left) / 2;
	int a = query(2 * index + 1, left, mid, l, r);		//query the left subtree
	int b = query(2 * index + 2, mid + 1, right, l, r);		//query the right subtree
	return segfun(a, b);
}
void update(int index, int left, int right, int pos, int val)		//funtion to update the value at pos to val
{
	if (pos < left || pos > right)		//out of bound condition
	{
		return;
	}
	int mid = left + (right - left) / 2;
	if (left == right)		//point found to update
	{
		segarr[mid] = val;		//updating in the array
		segtree[index] = val;		//updating in the segment tree
		return;
	}
	if (pos <= mid)		//if point is in the left subtree move to left subtree
	{
		update(2 * index + 1, left, mid, pos, val);
	}
	else		//if point is in the right subtree move to the right subtree
	{
		update(2 * index + 2, mid + 1, right, pos, val);
	}
	int a = segtree[2 * index + 1];
	int b = segtree[2 * index + 2];
	segtree[index] = segfun(a, b);		//updating current node in tree after updating its children
}
//implementation ends here
int main()
{
#ifndef ONLINE_JUDGE                        //using file i/o when not in online judgement
	freopen("input.txt", "r", stdin);       //input file
	freopen("output.txt", "w", stdout);     //output file
	freopen("error.txt", "w", stderr);		//error file
#endif
	int test;
	cin >> test;		//input no. of testcases
	while (test--)		//iterating over the testcases
	{
		int n;
		cin >> n;		//input size of the array
		for (int i = 0; i < n; i++)		//input the array
		{
			cin >> segarr[i];
		}
		build(0, 0, n - 1);		//build the segment tree
		int q;
		cin >> q;		//input the no. of queries to be performed
		while (q--)		//iterating over the queries
		{
			int c;
			cin >> c;		//input the type of query
			if (c == 1)		//type 1 - query over the given range
			{
				int l, r;
				cin >> l >> r;
				cout << query(0, 0, n - 1, l, r) << endl;		//calling the query function
			}
			if (c == 2)		//type 2 - make a point update at given pos
			{
				int x, y;
				cin >> x >> y;
				update(0, 0, n - 1, x, y);		//calling the given function
			}
		}
	}
	return 0;
}

// ABOUT SEGMENT TREE
/*
0.	Segment tree is a data structure which can be used to answer range queries in a very efficient manner.
1.	It is a widely used data structure in competitive programming contests and using this pre written code can save a lot of your time and give an edge over other participants.
2.	Time taken to make a point update - O(log(n))
3.	Time taken to make a range query - O(log(n))
4.	Extra space used - O(n)
5.	n = size of the array over which range queries are performed.
6.	The range function used in segement tree must be associative for the segment tree to funtion properly.
7.	The variables 'left' and 'right' is the scope of the segment tree.
8.	The segtree array has zero based index
9.	The segarr array has zero based index
*/

//HOW TO MODIFY THE CODE FOR YOUR USE
/*
1.	Change the segfun function to the requeiired range function
2.	Change the segid to the suitable identity element of the range function
3.	In a very few cases you may want to change the update part to if the updates are not direct
*/

//SCOPE FOR IMPROVEMENT
/*
1.	Lazy propagation can be implemented for range updates but implementing it for a general purpose is quite a tedious task and not the most intuitive to modify it for various purposes.
	Although if someone is able to do it and provide well documented code to use it, he/ she is most welcome to do that.
2.	The range funtion may also return different data types or even data structure depending on the range function.
3.	If we are able to build this for a real general purpose we may push a C++ library/class out of this.
*/

//sample input
/*
1
8
3 6 4 8 7 1 2 6
5
2 2 4
1 2 3
2 1 4
1 5 7
2 4 6
*/

//expected output
/*
12
9
*/
