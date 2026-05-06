#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	ll n;
	cin>>n;
	for(ll j=0;j<(1LL<<n);j++){
	    ll num=j^(j>>1);
	    for(ll k=n-1;k>=0;k--){
	        if((num>>k)&1LL){
	            cout<<1;
	        }
	        else{
	            cout<<0;
	        }
	    }
	    cout<<"\n";
	}
}
