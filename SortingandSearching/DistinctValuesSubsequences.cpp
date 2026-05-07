#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll M=1e9+7;
int main() {
    ll n;
    cin>>n;
    vector<ll>a(n);
    map<ll,ll>mp;
    for(ll j=0;j<n;j++){
        cin>>a[j];
        mp[a[j]]++;
    }
    ll ans=1;
    for(auto it:mp){
        ans=(ans*(it.second+1))%M;
    }
    ans=(ans-1+M)%M;
    cout<<ans<<"\n";
}
