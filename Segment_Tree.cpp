#include <bits/stdc++.h>
using namespace std;
#define ll long long 

struct segTree{
    ll size;
    vector<long long> sums;
    void init(ll n){
        size=1;
        while(size<n){
            size*=2;
        }
        sums.assign(2*size,0ll);
    }
    void build(vector<ll> &a,ll x,ll lx,ll rx){
        if(rx-lx == 1){
            if(lx<(ll)a.size()){
                sums[x]=a[lx];
            }
            return;
        }
        ll m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    void build(vector<ll> &a){
        build(a,0,0,size);
    }

    void set(ll i,ll v,ll x,ll lx,ll rx){
        if(rx-lx==1){
            sums[x]=v;
            return;
        }
        ll m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    void set(ll i,ll v){
        set(i,v,0,0,size);
    }
    long long sum(ll l,ll r,ll x,ll lx,ll rx){
        if(lx>=r || l>rx) return 0;
        if(lx>=l && rx<=r) return sums[x];
        ll m=(lx+rx)/2;
        long long s1=sum(l,r,2*x+1,lx,m);
        long long s2=sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }
    long long sum(ll l,ll r){
        return sum(l,r,0,0,size);
    }
};

int main(){
    ll n,m;
    cin>>n>>m;

    segTree st;
    st.init(n);
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    st.build(a);
    while(m--){
        ll op;
        cin>>op;
        if(op==1){
            ll i,v;
            cin>>i>>v;
            st.set(i-1,v);
        }else{
            ll l,r;
            cin>>l>>r;
            cout<<st.sum(l-1,r)<<"\n";
        }
    }

    return 0;
}