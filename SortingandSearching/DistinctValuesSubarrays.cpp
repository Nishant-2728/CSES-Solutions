#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll j=0;j<n;j++){
        cin>>a[j];
    }
    ll l=0,r=0,ans=0;
    map<ll,ll>mp;
    while(r<n){
        mp[a[r]]++;
        while(l<=r && mp[a[r]]>1){
            mp[a[l]]--;
            l++;
        }
        ans+=(r-l+1);
        r++;
    }
    cout<<ans<<"\n";
}
