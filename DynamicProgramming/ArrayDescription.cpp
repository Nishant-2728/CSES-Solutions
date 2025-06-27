#include<bits/stdc++.h>
using namespace std;
const long long int M=1e9+7;
long long int Totalways(long long int index,vector<long long int>&a,long long int m,long long int prev,vector<vector<long long int>>&dp){
    if(index<0)
        return 1;
    if(dp[index][prev]!=-1){
        return dp[index][prev];
    }
    long long int total=0;
    if(a[index]!=0){
        if(prev==0 || abs(a[index]-prev)<=1)
            total=Totalways(index-1,a,m,a[index],dp);
    }
    else{
        if(prev==0){
            for(long long int j=1;j<=m;j++){
                total=(total+Totalways(index-1,a,m,j,dp))%M;
            }
        }
        else{
            total=(total+Totalways(index-1,a,m,prev,dp))%M;
            if(prev-1>=1){
                total=(total+Totalways(index-1,a,m,prev-1,dp))%M;
            }
            if(prev+1<=m){
                total=(total+Totalways(index-1,a,m,prev-1,dp))%M;
            }
        }
    }
    return dp[index][prev]=total;
}
int main(){
    long long int n,m,j,index,prev;
    cin>>n>>m;
    vector<long long int>a(n);
    for(j=0;j<n;j++){
        cin>>a[j];
    }
    vector<long long int>prevarr(m+1,0);
    if(a[0]!=0){
        prevarr[a[0]]=1;
    }
    else{
        for(j=1;j<=m;j++){
            prevarr[j]=1;
        }
    }
    for(index=1;index<n;index++){
        vector<long long int>currarr(m+1,0);
        for(prev=1;prev<=m;prev++){
            if(a[index]!=0){
                if(abs(a[index]-prev)<=1){
                    currarr[a[index]]=(currarr[a[index]]+prevarr[prev])%M;
                }
            }
            else{
                currarr[prev]=(currarr[prev]+prevarr[prev])%M;
                if(prev-1>=1){
                    currarr[prev]=(currarr[prev]+prevarr[prev-1])%M;
                }
                if(prev+1<=m){
                   currarr[prev]=(currarr[prev]+prevarr[prev+1])%M;
                }
            }
        }
        prevarr=currarr;
    }
    long long int ans=0;
    for(j=1;j<=m;j++){
        ans=(ans+prevarr[j])%M;
    }
    cout<<ans<<endl;
}