#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll n;
	cin>>n;
	vector<ll>a(n);
	ll total_sum=0;
	for(ll j=0;j<n;j++){
	    cin>>a[j];
	    total_sum+=a[j];
	}
	sort(a.begin(),a.end());
	if(total_sum<2*a[n-1]){
	    cout<<2*a[n-1]<<"\n";
	}
	else{
	    cout<<total_sum<<"\n";
	}
}
