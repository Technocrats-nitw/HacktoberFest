/* Find shortest Subarray with Sum at Least K where array can contain negative values also*/

/*
Input : Two integer n and K and An array of integers of size n are given
Output : return length of shortest Subarray with Sum at Least K . If no such subarray is present , return -1.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

// function returns length of shortest Subarray with Sum at Least K . In case of no subarray returns -1.
ll shortest_subarray_with_sum_atleast_k(vector<ll> &A, ll k) 
{
    ll n = A.size(); // size of the given sequence 
    
    ll ans = n+1;
    deque<ll> d; // declare an empty deque to store the index of prefix sum
    
    ll B[n+1]; 
    for(ll i=0; i<=n; i++) B[i] = 0;
    
    for(ll i=0; i<n; i++) B[i+1] = B[i] + A[i]; // creating prefix sum array 
    
    for(ll i=0; i<n+1; i++)
    {
        // if current window (from index d.front() to i) is more than K , we update the length of subaray and move the sliding window from left as we have to find shortest length of subaaray
        while(d.size() >  0 && B[i] - B[d.front()] >= k)
        {
            ans = min(ans , i - d.front());
            d.pop_front();
        }
        
        /*
        deque maintains a queue in the ascending order of both the index and the value of prefix sum, because whenever 
        we see a new B, any B that is before it and larger than it will be a worse candidate 
        than the current B in terms of forming a shorter subarray that has a larger value.
        */
        
        while(d.size() > 0 && B[i] <= B[d.back()])
            d.pop_back();
        
        d.push_back(i);
    }
    
    if(ans == n+1) return -1;
    return ans;
}

int main()
{
    ll n; cin>>n; // length of the sequence 
    ll k; cin>>k; // sum value
    
    vector<ll> A(n);
    for(ll i=0; i<n; i++) cin>>A[i]; // sequence of size n taking as input 
    
    ll ans = shortest_subarray_with_sum_atleast_k(A , k); 
    
    cout<<ans<<endl;
}
