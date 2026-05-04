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
	map<ll,ll>mp;
	mp[0]=1;
	ll curr_sum=0;
	ll subarray_cnt=0;
	for(ll j=0;j<n;j++){
	    curr_sum+=a[j];
	    subarray_cnt+=mp[(curr_sum%n+n)%n];
	    mp[(curr_sum%n+n)%n]++;
	}
	cout<<subarray_cnt<<"\n";
}
