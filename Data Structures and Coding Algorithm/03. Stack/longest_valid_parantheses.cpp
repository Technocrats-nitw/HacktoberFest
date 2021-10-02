//LONGEST VALID PARNATHESES
/*
Problem Statement -
Given a string containing opening and closing parantheses, find the length of the longest substring which represents a valid parantheses.
A valid parantheses is a a set which can form a mathematically correct expression when inserted some operators and operands in it.
*/
#include<bits/stdc++.h>
using namespace std;

int longestValidParentheses(string str)
{
	int n = str.size();		//size of the string
	stack<int> stk;
	stk.push(-1);		//last index till which the expression was balanced
	int max = 0;		//initialising the max with 0
	for (int i = 0; i < n; i++)		//iterate the string
	{
		if (str[i] == '(')		//opening paranthesis can be directly pushed into the stack
		{
			stk.push(i);
		}
		else		//if it is a closing paranthesis
		{
			stk.pop();		//pop out an index for starting bracket
			if (stk.empty())		//empty stack means the corresponding sarting bracket was not present so the expression became inmbalanced
			{
				stk.push(i);		//last index till which the expression was balanced
			}
			else		
			{
				if (i - stk.top() > max)		//the brackets are balanced from the top index in the stack to the current index so compare it with the max we have found till now
				{
					max = i - stk.top();
				}
			}
		}
	}
	return max;		//longest substring found til now
}

void solve()
{
	string s;		//input the paranthesis expression
	cin >> s;
	cout << longestValidParentheses(s) << endl;
}

int32_t main()
{
	int ntc = 1;
	cin >> ntc;		//input no. of testcases
	while (ntc--)
	{
		solve();
	}
	return 0;
}

/*
Given above is an O(n) solution to the problem
*/
