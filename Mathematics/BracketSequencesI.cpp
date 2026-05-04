#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll M=1e9+7;
vector<ll>fact(2000001);
void calc(){
    fact[0]=1;
    for(ll j=1;j<=2000000;j++){
        fact[j]=(fact[j-1]*j)%M;
    }
}
ll powi(ll x,ll y){
    ll ans=1;
    x%=M;
    while(y){
        if(y%2==0){
            x=(x*x)%M;
            y/=2;
        }
        else{
            ans=(ans*x)%M;
            y--;
        }
    }
    return ans;
}
ll modinverse(ll a){
    return powi(a,M-2)%M;
}
ll nCr(ll n,ll r){
    return ((fact[n]*modinverse(fact[r]))%M*modinverse(fact[n-r]))%M;
}
int main(){
    calc();
    ll n;
    cin>>n;
    if(n%2==1){
        cout<<0<<"\n";
    }
    else{
        ll ans=nCr(n,n/2);
        ans=(ans*modinverse(n/2+1))%M;
        cout<<ans<<"\n";
    }
}

 
