#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll M=1e9+7;
int main() {
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll j=0;j<n;j++){
        cin>>a[j];
    }
    sort(a.begin(),a.end());
    ll total=0;
    for(ll j=0;j<n;j++){
        total+=abs(a[j]-a[n/2]);
    }
    cout<<total<<"\n";
}
