#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	ll n,k;
	cin>>n>>k;
	vector<ll>a(n);
	for(ll j=0;j<n;j++){
	    cin>>a[j];
	}
	ll l=0,r=0;
	ll total_cnt=0,unique_cnt=0;
	map<ll,ll>mp;
	while(r<n){
	    mp[a[r]]++;
	    if(mp[a[r]]==1){
	        unique_cnt++;
	    }
	    while(l<=r && unique_cnt>k){
	        mp[a[l]]--;
	        if(mp[a[l]]==0){
	            unique_cnt--;
	        }
	        l++;
	    }
	    total_cnt+=(r-l+1);
	    r++;
	}
	cout<<total_cnt<<"\n";
}
