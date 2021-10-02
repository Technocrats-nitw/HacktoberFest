/*

code to evaluate postfix expression using stacks
eg- input string  = 345*+2-
output = 21  ((5*4)+3-2)

*/

#include <iostream>
#include <cstring>
#include <stack>     //include this header file for using stack
using namespace std;

void postfix_eval(char exp[])
{  stack <char> s;                         // declaring a stack with char data type and name s
   int size=strlen(exp);
  int i=0;
  while(i < size)
  {
    if(exp[i]>47 && exp[i] <58)   //if it is operand i-e digit then simply pushing in stack
        s.push(exp[i]);
    /* if it is operator then pop out top 2 elements of stack one by one
   and store them in different variables */
     else
    {
      int n1 = s.top()-'0'; s.pop();  // -'0' for converting char to int
      int n2 = s.top()-'0';s.pop();

      /* perform operation on previously popped operands
      and push them back in stack*/

         switch(exp[i])
    {
        case '+' :s.push((n1+n2)+'0');break;    // +'0' for converting int to char because stack is of char data type
        case '-' : s.push((n2-n1)+'0');break;   //note n2-n1 i-e second pop - first pop
        case '*' :s.push((n1*n2)+'0');break;
        case '/' : s.push((n2/n1)+'0');break;
    }}

     i++;
     }
//when all the operations are performed the only element in stack is result
cout<<s.top()-'0';  
}


int main()
{
   char expression[20]; //char array for storing input
   cin>>expression;
    postfix_eval(expression);

}
