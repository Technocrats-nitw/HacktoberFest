// Get XOR of a range using segment tree in log(n) time
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define vc vector
#define mapll map<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define loopf(i,a,b) for(ll i=a;i<b;i++)
#define loopb(i,b,a) for(ll i=a-1;i>=b;i--)
typedef vector<ll> vll;
typedef pair<ll,ll> pl;
#define read(v) for(int i=0;i<(int)v.size();++i) cin>>v[i]
#define read1(v) for(int i=1;i<(int)v.size();++i) cin>>v[i]
#define print(v) for(int i=0;i<(int)v.size();++i)cout<<v[i]<<" ";cout<<endl;
#define all(v) v.begin(),v.end()
//const ll M=ll(1e9+7);

ll buildST(vll &arr, ll ss, ll se, vll &st, ll si){
    if(ss==se){
        st[si]=arr[ss];
        return arr[ss];
    }
    ll mid=(ss+se)/2;
    st[si] = (buildST(arr,ss,mid,st,2*si+1) ^ buildST(arr,mid+1,se,st,2*si+2));
    return st[si];
}

ll getXOR_ST(vll &st, ll ss, ll se, ll l, ll r, ll si){
    if(ss>=l && se<=r)return st[si];
    if(ss>r || se<l) return 0;
    ll mid=(ss+se)/2;
    return (getXOR_ST(st,ss,mid,l,r,2*si+1) ^ getXOR_ST(st,mid+1,se,l,r,2*si+2));
}

void updateST(vll &st, ll ss, ll se, ll i, ll old_val, ll val, ll si){
    if(i<ss || i>se) return;
    st[si]=(st[si]^val^old_val);
    if(ss==se){st[si]=val; return;}
    ll mid=(ss+se)/2;
    updateST(st,ss,mid,i,old_val,val,2*si+1);
    updateST(st,mid+1,se,i,old_val,val,2*si+2);
}



int main() {
cin.tie(NULL);
cout.tie(NULL);
ios_base::sync_with_stdio(false);


ll t=1;
//cin>>t;
while(t--){
    ll n; cin>>n;
    vll arr(n); read(arr);
    vll st(2*(ll)pow(2,(ll)(ceil(log2(n))))-1);
    buildST(arr,0,n-1,st,0);
    ll l,r; cin>>l>>r; l--; r--;
    cout<<getXOR_ST(st,0,n-1,l,r,0)<<endl;
    ll x,val; cin>>x>>val; x--;
    ll old_val=arr[x];
    updateST(st,0,n-1,x,old_val,val,0);
    cout<<getXOR_ST(st,0,n-1,0,n-1,0)<<endl;
}
return 0;
}
