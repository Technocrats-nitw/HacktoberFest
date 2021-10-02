/* Find kth missing positive integer from array*/

/*
Input : an array of size n and an integer K is given.
Output : find kth missing number from array
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

// function returns the Kth missing number from array

ll kth_missing_number(vector<ll> &A, ll k)
{
    int l = 0; int r = A.size()-1;
        
    while(l <= r)
    {
        int mid = (l + r) / 2;
        
        if(A[mid] - (mid+1) < k) l = mid+1;
        else r = mid-1;
    }
    
    return l+k;
}

int main()
{
    ll n,k; cin>>n>>k;
    vector<ll> A(n);
    
    for(ll i=0; i<n; i++) cin>>A[i];
    
    ll ans = kth_missing_number(A , k);
    
    cout<<ans<<endl;
    
    return 0;
}

// Time complexity : O(n)
// Space complexity : O(1)
