#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll f(ll n,ll k){
    if(n==1){ 
        return 1;
    }
    if(k<=(n+1)/2) 
    {
        if(2*k>n) 
            return (2*k)%n;
        return 2*k;
    }
    ll temp=f(n/2,k-(n+1)/2);
    if(n%2==1){
        return 2*temp+1;
    }
    return 2*temp-1;
}
int main() {
    ll T;
    cin>>T;
    while(T--){
        ll n,k;
        cin>>n>>k;
        cout<<f(n,k)<<"\n";
    }
}
