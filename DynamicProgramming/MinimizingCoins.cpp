#include<bits/stdc++.h>
using namespace std;
long long int Totalways(long long int x,long long int c[],long long int n,vector<long long int>&dp){
    if(x<0)
        return 1e17;
    if(x==0)
        return 0;
    if(dp[x]!=-1){
        return dp[x];
    }
    long long int minways=1e18;
    for(long long int j=0;j<n;j++){
        minways=min(minways,Totalways(x-c[j],c,n,dp)+1LL);
    }
    return dp[x]=minways;
}
int main(){
    long long int n,x;
    cin>>n>>x;
    long long int c[n],j,k;
    for(j=0;j<n;j++){
        cin>>c[j];
    }
    vector<long long int>dp(x+1,1e17);
    dp[0]=0;
    for(j=1;j<=x;j++){
        for(k=0;k<n;k++){
            dp[j]=min(dp[j],(j-c[k]>=0?dp[j-c[k]]+1:(long long int)1e17));
        }
    }
    cout<<(dp[x]>=1e17?-1:dp[x])<<endl;
}