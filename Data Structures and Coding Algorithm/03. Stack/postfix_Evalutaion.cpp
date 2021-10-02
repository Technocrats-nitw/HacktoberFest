//Postfix Evaluation using stack data structure

/* 
Input   : given a valid postfix expression as an string where every operand contains sinlge digit and operators are {+ , - , *}.
output : Evaluation of postfix expression 
*/ 

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;  // input postfix expression
	cin>>str;
	
	stack<int> s; // declare a stack to store operands
	
	for(int i=0; i<str.size(); i++) // traverse the string 
	{
		if(str[i] >= '0' && str[i] <= '9')  // if current character is a digit 
		{
			int digit = str[i] - '0';
			s.push(digit); // push into the stack
		}
		
		else  // if current character is an operator
		{
			// pop top 2 operands from the stack and evaluate the operator and push result back to the stack 
			int a = s.top(); s.pop();
			int b = s.top(); s.pop();
			
			if(str[i] == '+') {
				s.push(b+a);
			}
			
			else if(str[i] == '-') {
				s.push(b-a);
			}
			
			else {
				s.push(b*a);
			}
		}
	}
	
	int ans = s.top(); // at last only one element will be present in stack which will be the evaluted value of given postfix expression.
	
	cout<<ans<<endl;
	
	return 0;
}
