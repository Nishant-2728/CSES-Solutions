#include<bits/stdc++.h>
using namespace std;
long long int Minways(long long int n,vector<long long int>&dp){
    if(n==0)
        return 0;
    if(dp[n]!=-1){
        return dp[n];
    }
    long long int minmoves=1e18;
    long long int y=n;
    while(y){
        if(y%10!=0)
            minmoves=min(minmoves,1+Minways(n-y%10,dp));
        y/=10;
    }
    return dp[n]=minmoves;
}
int main(){
    long long int n,j;
    cin>>n;
    vector<long long int>dp(n+1,1e18);
    dp[0]=0;
    for(j=1;j<=n;j++){
        long long int y=j;
        while(y){
            if(y%10!=0)
                dp[j]=min(dp[j],1+dp[j-y%10]);
            y/=10;
        }
    }
    cout<<dp[n]<<endl;
}