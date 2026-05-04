#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    vector<ll>a(k);
    for(ll j=0;j<k;j++){
        cin>>a[j];
    }
    ll total_cnt=0;
    for(ll j=1;j<(1LL<<k);j++){
        ll num=1;
        ll cnt=__builtin_popcount(j);
        for(ll m=0;m<k;m++){
            if((j>>m)&1LL){
                if(num>n/a[m]){
                    num=n+1;
                    break;
                }
                else{
                    num*=a[m];
                }
            }
        }
        if(cnt%2){
            total_cnt+=n/num;
        }
        else{
            total_cnt-=n/num;
        }
    }
    cout<<total_cnt<<"\n";
}

 
