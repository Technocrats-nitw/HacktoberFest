/*
   find maximum rectangular area in linear time
*/
#include<bits/stdc++.h>
using namespace std;

// Function to find the Maximum rectangular area under given histogram with n bars
int Ans(vector<int>&A)
{
	// Create an empty stack. The stack holds indexes
	// of A[] array. The bars stored in stack are
	// always in increasing order of their heights.
	stack<int> s;
    int n=A.size(); 
	int maximum = 0,i=0; // Initialize maximum area
	while (i < n)
	{
		// If this bar is higher than the bar on top
		// stack, push it to stack
		if (s.empty() || A[s.top()] <= A[i])
			s.push(i++);

		// If this bar is lower than top of stack,
		// then calculate area of rectangle with stack
		// top as the smallest (or minimum height) bar.
		// 'i' is 'right index' for the top and element
		// before top in stack is 'left index'
		else
		{
			int tp = s.top(); // store the top index
			s.pop(); // pop the top

			// Calculate the area with A[tp] stack as smallest bar
			int  temp_area = A[tp] * (s.empty() ? i :i - s.top() - 1);
			// update max area
            	maximum = max(maximum,temp_area);
		}
	}

	// Now pop the remaining bars from stack and calculate
	// area with every popped bar as the smallest bar
	while (!s.empty())
	{
		int tp = s.top(); // store the top index
			s.pop(); // pop the top

			// Calculate the area with A[tp] stack as smallest bar
			int  temp_area = A[tp] * (s.empty() ? i :i - s.top() - 1);
			// update max area
            	maximum = max(maximum,temp_area);
	}

	return maximum;
}

int main()
{
    int i,n; 
    cin>>n; // size of histogram
    vector<int>A(n);
    for(i=0;i<n;i++) cin>>A[i];
	cout << "Maximum Area of this Histogram  is "<<Ans(A);
	return 0;
}
