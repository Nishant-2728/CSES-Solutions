#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n);
	vector<ll>pos(n+1);
	for(ll j=0;j<n;j++){
	    cin>>a[j];
	    pos[a[j]]=j;
	}
	ll cnt=0;
	for(ll j=2;j<=n;j++){
	    if(pos[j]<pos[j-1]){
	        cnt++;
	    }
	}
	while(m--){
	    ll x,y;
	    cin>>x>>y;
	    x--;
	    y--;
	    if(a[x]>1 && pos[a[x]]<pos[a[x]-1]){
	        cnt--;
	    }
	    if(a[x]<n && pos[a[x]]>pos[a[x]+1]){
	        cnt--;
	    }
	    if(a[y]>1 && pos[a[y]]<pos[a[y]-1]){
	        cnt--;
	    }
	    if(a[y]<n && pos[a[y]]>pos[a[y]+1]){
	        cnt--;
	    }
	    if(a[x]==a[y]+1 && pos[a[x]]<pos[a[x]-1]){
	        cnt++;
	    }
	    else if(a[y]==a[x]+1 && pos[a[y]]<pos[a[y]-1]){
	        cnt++;
	    }
	    pos[a[x]]=y;
	    pos[a[y]]=x;
	    swap(a[x],a[y]);
	    if(a[x]>1 && pos[a[x]]<pos[a[x]-1]){
	        cnt++;
	    }
	    if(a[x]<n && pos[a[x]]>pos[a[x]+1]){
	        cnt++;
	    }
	    if(a[y]>1 && pos[a[y]]<pos[a[y]-1]){
	        cnt++;
	    }
	    if(a[y]<n && pos[a[y]]>pos[a[y]+1]){
	        cnt++;
	    }
	    if(a[x]==a[y]+1 && pos[a[x]]<pos[a[x]-1]){
	        cnt--;
	    }
	    else if(a[y]==a[x]+1 && pos[a[y]]<pos[a[y]-1]){
	        cnt--;
	    }
	    cout<<cnt+1<<"\n";
	}
}
