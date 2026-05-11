#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll x,n;
	cin>>x>>n;
	vector<ll>p(n);
	multiset<ll>dist;
	set<ll>pos;
	pos.insert(0);
	pos.insert(x);
	dist.insert(x);
	for(ll j=0;j<n;j++){
	    cin>>p[j];
	    auto it=pos.upper_bound(p[j]);
        auto it1=it;
        it1--;
        dist.erase(dist.find(*(it)-*(it1)));
        dist.insert(*(it)-p[j]);
        dist.insert(p[j]-*(it1));
	    pos.insert(p[j]);
        cout<<*(dist.rbegin())<<" ";
	}
}
