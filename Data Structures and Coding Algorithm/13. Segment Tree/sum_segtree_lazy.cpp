// Sum of a range using segment- tree lazy propagation

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
    st[si] = buildST(arr,ss,mid,st,2*si+1) + buildST(arr,mid+1,se,st,2*si+2);
    return st[si];
}

ll getSumST(vll &st, vll &lazy, ll ss, ll se, ll l, ll r, ll si){
    if(ss>r || se<l || ss>se) return 0;
    if(lazy[si]!=0){
        st[si]+=(se-ss+1)*lazy[si];
        if(ss!=se){
            lazy[2*si+1]+=lazy[si];
            lazy[2*si+2]+=lazy[si];
        }
        lazy[si]=0;
    }
    if(l<=ss && r>=ss) return st[si];
    
    ll mid=(ss+se)/2;
    return getSumST(st,lazy,ss,mid,l,r,2*si+1) + getSumST(st,lazy,mid+1,se,l,r,2*si+2);
}
//Not really needed since you can update a single point using range update too!:
void updateST(vll &st, ll ss, ll se, ll i, ll diff, ll si){
    if(i<ss || i>se) return;
    //lazy
    if(lazy[si]!=0){
        st[si]+=(se-ss+1)*lazy[si];
        if(ss!=se){
            lazy[2*si+1]+=lazy[si];
            lazy[2*si+2]+=lazy[si];
        }
        lazy[si]=0;
    }
    ///lazy
    st[si]+=diff;
    if(ss==se)return;
    ll mid=(ss+se)/2;
    updateST(st,ss,mid,i,diff,2*si+1);
    updateST(st,mid+1,se,i,diff,2*si+2);
}

void updateRangeST(vll &st, vll &lazy, ll ss, ll se, ll l, ll r, ll diff, ll si){
    if(lazy[si]!=0){
        st[si]+=(se-ss+1)*lazy[si];
        if(ss!=se){
            lazy[2*si+1]+=lazy[si];
            lazy[2*si+2]+=lazy[si];
        }
        lazy[si]=0;
    }
    if(ss>se || r<ss || l>se) return;
    if(ss>=l && se<=r){
        st[si]+=(se-ss+1)*diff;
        if(ss!=se){
            lazy[2*si+1]+=diff;
            lazy[2*si+2]+=diff;
        }
        return;
    }
    ll mid=(ss+se)/2;
    updateRangeST(st,lazy, ss,mid,l,r,diff,2*si+1);
    updateRangeST(st,lazy,mid+1,se,l,r,diff,2*si+2);
    st[si]=st[2*si+1]+st[2*si+2];
}



int main() {
cin.tie(NULL);
cout.tie(NULL);
ios_base::sync_with_stdio(false);


ll t=1;
cin>>t;
while(t--){
    ll n; cin>>n;
    vll arr(n); read(arr);
    vll st(2*(ll)pow(2,(ll)(ceil(log2(n))))-1);
    vll lazy(2*(ll)pow(2,(ll)(ceil(log2(n))))-1);
    fill(all(lazy),0);
    buildST(arr,0,n-1,st,0);
    ll l,r; cin>>l>>r; l--; r--;
    cout<<getSumST(st,lazy,0,n-1,l,r,0)<<endl;
    l=0, r=4;
    ll diff=5;
    updateRangeST(st,lazy,0,n-1,l,r,diff,0);
    l=0, r=n-1;
    cout<<getSumST(st,lazy,0,n-1,1,n-1,0)<<endl;
}
return 0;
}
