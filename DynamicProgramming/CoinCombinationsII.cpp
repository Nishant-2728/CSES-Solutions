#include<bits/stdc++.h>
using namespace std;
const long long int M=1e9+7;
long long int Totalways(long long int n,long long int x,long long int index,long long int c[],vector<vector<long long int>>&dp){
    if(x<0 || index==n){
        return 0;
    }
    if(x==0){
     return 1;
    }
    if(dp[index][x]!=-1){
        return dp[index][x];
    }
    long long int orderedways=0;
    orderedways+=Totalways(n,x-c[index],index,c,dp);
    orderedways%=M;
    orderedways+=Totalways(n,x,index+1,c,dp);
    orderedways%=M;
    return dp[index][x]=orderedways;
}
int main(){
    long long int n,x;
    cin>>n>>x;
    long long int c[n],j,k;
    for(j=0;j<n;j++){
        cin>>c[j];
    }
    vector<vector<long long int>>dp(n+1,vector<long long int>(x+1,0));
    for(j=0;j<n;j++){
        dp[j][0]=1;
    }
    for(j=n-1;j>=0;j--){
        for(k=1;k<=x;k++){
            dp[j][k]+=(dp[j+1][k])%M;
            if(k-c[j]>=0){
                dp[j][k]+=(dp[j][k-c[j]]);
                dp[j][k]%=M;
            }
        }
    }
    cout<<dp[0][x]<<endl;
}