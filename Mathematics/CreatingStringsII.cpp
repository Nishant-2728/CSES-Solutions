#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll M=1e9+7;
vector<ll>fact(1000001);
void calc(){
    fact[0]=1;
    for(ll j=1;j<=1000000;j++){
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
int main(){
calc();
string S;
cin>>S;
ll n=S.size();
vector<ll>freq(26,0);
for(ll j=0;j<n;j++){
    freq[S[j]-'a']++;
}
ll totalans=fact[n];
for(ll j=0;j<26;j++){
    totalans=(totalans*modinverse(fact[freq[j]]))%M;
}
cout<<totalans<<"\n";
}
