#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll n;
	cin>>n;
	vector<pair<ll,ll>>a(n);
	for(ll j=0;j<n;j++){
	    cin>>a[j].first>>a[j].second;
	}
	sort(a.begin(),a.end());
	ll total=0,sum=0;
	for(ll j=0;j<n;j++){
	    total+=a[j].second;
	    sum+=a[j].first;
	    total-=sum;
	}
	cout<<total<<"\n";
}
