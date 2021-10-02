/* No of Different ways to construct a max heap from n distinct integers. */

/*
Input : An integer n (Total no of distinct integers).
Output : Find the number of distinct Max Heap can be made from given n distinct integers with modulo 10^9 + 7.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

const ll mod = 1e9 + 7;
const ll mn = 105; // assuming max no of distinct elements are 100
 
ll fact[mn]; // fact[i] stores the value of i! with modulo 1e9 + 7
ll dp[mn];  // dp[i] stores the total no of ways to contruct unique heaps with n distinct keys
 
// Function calculate the factorial of each number form 1 to mn with modulo 1e9 + 7
void factorial()
{
    fact[0] = 1;
    for(ll i=1; i<mn; i++)
        fact[i] = (fact[i-1]%mod * i%mod) % mod;
}
 
// function returns value of (a^b)%mod 
ll power(ll a, ll b)
{
    if(a <= 0) return a;
    if(b == 0) return 1;
    
    ll d = power(a , b/2)%mod;
    d = (d%mod * d%mod) % mod;
    if(b%2) d = (d%mod * a%mod) % mod;
    
    return d%mod;
}
 
// function finds the value of ncr (n r) with modulo 1e9 + 7
ll ncr(ll n, ll r)
{
    if(r > n) return 0;
    if(n < 2 || r == 0 || r == n) return 1;
    
    ll d = (fact[r]%mod * fact[n-r]%mod) % mod;
    ll x = (fact[n]%mod * power(d , mod-2)%mod) % mod;
    return x;
}

// funciton returns the total no of nodes present in left subtree of heap with n distinct nodes
ll left(ll n)
{
    if(n == 1) return 1;
    
    ll h = log2(n);
    ll last_level = (1 << h); // max non of nodes , can be present in last level
    ll last = n - ((1 << h) - 1); // no of nodes in last level if heap contains total n nodes 
        
    if(last >= last_level / 2) 
        return (1 << h) - 1; // in left subtree , last level is completely filled
    
    else 
        return (1 <<  h) - 1 - ((last_level)/2 - last); // in left subtree , last level is not filled completely 
}

// function returns the total no of ways to contruct unique heaps with n distinct keys
ll cal(ll n)
{
    if(n <= 2) return 1;
    
    if(dp[n] != -1) return dp[n]; // if dp[n] or distinct ways of heap with n distinct keys is already evvaluated 
    
    ll l = left(n); // no of nodes in left subtree
    ll r = n - 1 - l; // no of nodes in right subrtree
    
    ll ways = ncr(n-1 , l)%mod; // non of ways for chosing l (no of nodes in left subtree) elements form n-1 elements as one element (maximum one) is already used as root of the heap.
    ll cntl = cal(l); // no of ways to create left subtree
    ll cntr = cal(r); // no of ways to create right subtree
    
    // total ways = (ways to chosing l keys in left subtree) * (ways to form left subtree) * (ways to create right subtree) with modulo 1e9 + 7
    
    dp[n] = ((ways%mod * cntl%mod)%mod * cntr%mod) % mod;
    
    return dp[n];
}

// function to find total unique heaps with n distinct keys
ll ways_to_form_max_heap(ll A) {
    ll n = A;
    factorial();
    memset(dp , -1 , sizeof(dp));
    return cal(n);
}

int main()
{
    // total no of distinct integers.
    ll n; cin>>n; 
    
    ll ans = ways_to_form_max_heap(n);
    
    cout<<ans<<endl;
    
    return 0;
}
