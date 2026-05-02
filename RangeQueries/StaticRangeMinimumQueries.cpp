#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class SegmentTree{
private:
    vector<ll>seg;
public:
    SegmentTree(int n){
        seg.resize(4*n+1);
    }
    void build(ll index,ll low,ll high,vector<ll>&a){
        if(low==high){
            seg[index]=a[low];
            return ;
        }
        ll mid=low+(high-low)/2;
        build(2*index+1,low,mid,a);
        build(2*index+2,mid+1,high,a);
        seg[index]=min(seg[2*index+1],seg[2*index+2]);
    }
    ll query(ll index,ll low,ll high,ll l,ll r){
        if(high<l || r<low){
            return 1e18;
        }
        if(low>=l && high<=r){
            return seg[index];
        }
        ll mid=low+(high-low)/2;
        ll left=query(2*index+1,low,mid,l,r);
        ll right=query(2*index+2,mid+1,high,l,r);
        return min(left,right);
    }
};
int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll>a(n);
    for(ll j=0;j<n;j++){
        cin>>a[j];
    }
    SegmentTree sg1(n);
    sg1.build(0,0,n-1,a);
    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<sg1.query(0,0,n-1,l,r)<<"\n";
    }
}
