#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll Maxlen(ll index1,ll index2,ll n,ll m,vector<ll>&a,vector<ll>&b,vector<vector<ll>>&dp){
    if(index1==n || index2==m){
        return 0LL;
    }
    if(dp[index1][index2]!=-1){
        return dp[index1][index2];
    }
    ll ans=0;
    if(a[index1]==b[index2]){
        ans=max(ans,1+Maxlen(index1+1,index2+1,n,m,a,b,dp));
    }
    else{
        ans=max(ans,Maxlen(index1+1,index2,n,m,a,b,dp));
        ans=max(ans,Maxlen(index1,index2+1,n,m,a,b,dp));
    }
    return dp[index1][index2]=ans;
}
int main() {
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n),b(m);
	for(ll j=0;j<n;j++){
	    cin>>a[j];
	}
	for(ll j=0;j<m;j++){
	    cin>>b[j];
	}
	vector<vector<ll>>dp(n+1,vector<ll>(m+1,-1));
	cout<<Maxlen(0,0,n,m,a,b,dp)<<"\n";
	vector<ll>res;
	ll j=0,k=0;
	while(j<n && k<m){
	    if(a[j]==b[k]){
	        res.push_back(a[j]);
	        j++;
	        k++;
	    }
	    else{
	        if(dp[j+1][k]>dp[j][k+1]){
	            j++;
	        }
	        else{
	            k++;
	        }
	    }
	}
	for(auto it:res){
	    cout<<it<<" ";
	}
	cout<<"\n";
}
