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
    string S;
    cin>>S;
    ll k=S.size();
    if(n%2==1){
        cout<<0<<"\n";
    }
    else{
        ll sum=0,flag=1;
        for(ll j=0;j<k;j++){
            sum+=(S[j]=='('?1:-1);
            if(sum<0 || sum>n/2){
                flag=0;
            }
        }
        if(flag){
            ll cnt1=n/2-(k+sum)/2;
            ll cnt2=n/2-(k-sum)/2;
            ll total=nCr(cnt1+cnt2,cnt1);
            if(cnt2>=sum+1){
                total=(total-nCr(cnt1+cnt2,sum+1+cnt1)+M)%M;
            }
            cout<<total<<"\n";
        }
        else{
            cout<<0<<"\n";
        }
    }
}
