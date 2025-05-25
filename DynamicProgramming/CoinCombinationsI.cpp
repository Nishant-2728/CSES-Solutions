#include<bits/stdc++.h>
using namespace std;
const long long int M=1e9+7;
long long int Totalways(long long int n,long long int x,long long int c[],vector<long long int>&dp){
    if(x<0)
        return 0;
    if(x==0)
        return 1;
    if(dp[x]!=-1)
        return dp[x];
    long long int ways=0;
    for(long long int j=0;j<n;j++){
        ways+=Totalways(n,x-c[j],c,dp);
        ways%=M;
    }
    return dp[x]=ways;
}
int main(){
    long long int n,x;
    cin>>n>>x;
    long long int c[n],j,k;
    for(j=0;j<n;j++){
        cin>>c[j];
    }
    vector<long long int>dp(x+1,0);
    dp[0]=1;
    for(j=1;j<=x;j++){
        for(k=0;k<n;k++){
            dp[j]+=(j-c[k]>=0?dp[j-c[k]]:0);
            dp[j]%=M;
        }
    }
    cout<<dp[x]<<endl;
}