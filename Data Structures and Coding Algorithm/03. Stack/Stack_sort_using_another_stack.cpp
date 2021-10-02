/* 
     Sort a stack using a temporary stack
*/

/*
  Algo:--

    Create a temporary stack say temp.
    While input stack is NOT empty do this: 
        Pop an element from input stack call it temp
        while temporary stack is NOT empty and top of temporary stack is greater than temp, 
        pop from temporary stack and push it to the input stack
        push temp in temporary stack
    The sorted numbers are in temp
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int>s,temp;
    int n,i,x; 
    cin>>n; // size of stack
    for(i=0;i<n;i++){
        cin>>x; // input
        s.push(x);
    }
    while(!s.empty()){
        x=s.top();
        s.pop(); // pop out the first element
        if(temp.empty() || temp.top() <x) temp.push(x);
        else{
 
            // while temporary stack is not empty and top
            // of stack is greater than temp
            while(!temp.empty() && temp.top() >x){
                // pop from temporary stack and push
               // it to the input stack
                s.push(temp.top());
                temp.pop();
            }
            
        // push temp in temporary of stack
         temp.push(x);
        }
    }
   // print the sorted stack
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
}
