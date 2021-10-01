//balancing parantheses using stack data structure
/* given a string of { } ,
output should be 1 if parantheses are balanced */

#include <iostream>
#include <stack> //include this header file for using stakcs
#include <cstring> //include this header file for using char array functions
using namespace std;

bool balancing(char b[])
{ int i=0;
int size=strlen(b); //size of char array
 stack<char> s; //declaring stack of data type-char and name s
    while(i<size)
    {
        if(b[i]=='{')       //open bracket will be pushed in stack
            s.push(b[i]);
        else if (b[i]=='}')   //closed bracket will balance one open bracket ,therefore '{' popped out of stack
            s.pop();
        i++;
    }
    if(s.empty())  //in the end if stack is empty, then all brackets will be balanced
        return true;
    else
        return false;
}
int main()
{
char bracket[50];  //char array for input symbol string
cin>>bracket;
cout<<balancing(bracket);
    return 0;
}
