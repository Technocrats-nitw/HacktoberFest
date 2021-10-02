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
	int n = str.size();
	stack<int> stk;
	int last = -1;
	stk.push(-1);
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
		{
			stk.push(i);
		}
		else
		{
			stk.pop();
			if (stk.empty())
			{
				stk.push(i);
			}
			else
			{
				if (i - stk.top() > max)
				{
					max = i - stk.top();
				}
			}
		}
	}
	return max;
}

void solve()
{
	string s;
	cin >> s;
	cout << longestValidParentheses(s) << endl;
}

int32_t main()
{
	int ntc = 1;
	cin >> ntc;
	while (ntc--)
	{
		solve();
	}
	return 0;
}