#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll n;
	cin>>n;
	vector<pair<pair<ll,ll>,ll>>a(n);
	for(ll j=0;j<n;j++){
	    ll u,v;
	    cin>>u>>v;
	    a[j].first.first=v;
	    a[j].first.second=u;
	    a[j].second=j;
	}
	sort(a.begin(),a.end());
	vector<ll>ans(n);
	set<pair<ll,ll>>st;
	ll cnt=1;
	for(ll j=0;j<n;j++){
	    if(j==0){
	        ans[a[j].second]=cnt;
	        st.insert({a[j].first.first,cnt});
	        cnt++;
	    }
	    else{
	        auto it=st.lower_bound({a[j].first.second,-1});
	        if(it!=st.begin()){
	            it--;
	            ans[a[j].second]=(*it).second;
	            st.erase(it);
	            st.insert({a[j].first.first,ans[a[j].second]});
	        }
	        else{
	            ans[a[j].second]=cnt;
	            st.insert({a[j].first.first,cnt});
	            cnt++;
	        }
	    }
	}
	cout<<cnt-1<<"\n";
	for(ll j=0;j<n;j++){
	    cout<<ans[j]<<" ";
	}
}
