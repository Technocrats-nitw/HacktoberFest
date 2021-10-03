/* Find length of longest Arithmetic Progression in an integer array A of size n. */

/*
Input : An integer array A of size n is given .
Output : Find length of longest Arithmetic Progression in given array.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

// Function returns the length of longest Arithmetic Sequence in given integer sequence of length n.
ll longest_arithmatic_seq(vector<ll> &A) {
    ll n = A.size();
    
    // if given sequence is empty then length of AP is 0. 
    if(n == 0) return 0;
    
    vector<map<ll,ll> > dp(n);
    
    // dp[i] is an unordered map where dp[i][d] stores the length of arithmetic progression where A.P ends at index j and have common difference equals to d.
    
    ll ans = 1;
    
    for(ll i=1; i<n; i++) 
    {
        for(ll j=0; j<i; j++)
        {
            ll d = A[i] - A[j];
            if(dp[j].find(d) != dp[j].end()) {
                dp[i][d] = dp[j][d] + 1; 
            }
            else {
                dp[i][d] = 2;
            }
            
            ans = max(ans , dp[i][d]);
        }
    }
    
    return ans;
}

int main()
{
    ll n; cin>>n;  // length of the given sequence 
    vector<ll> A(n);
    
    for(ll i=0; i<n; i++) cin>>A[i]; // A sequence of integers taking as input 
    
    ll ans = longest_arithmatic_seq(A); // length of longest AP sequence 
    
    cout<<ans<<endl;
    
    return 0;
}
