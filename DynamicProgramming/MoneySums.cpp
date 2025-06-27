#include<bits/stdc++.h>
using namespace std;
bool Countways(long long int index,vector<long long int>&a,long long int sum,vector<vector<int>>&dp){
    if(sum==0)
        return true;
    if(index==0)
        return a[index]==sum;
    if(dp[index][sum]!=-1)
        return dp[index][sum];
    bool pick=false;
    if(sum>=a[index]){
        pick=Countways(index-1,a,sum-a[index],dp);
    }
    bool notpick=Countways(index-1,a,sum,dp);
    return dp[index][sum]=pick || notpick;
}
int main(){
    long long int n,count=0;
    cin>>n;
    vector<long long int>a(n);
    long long int j,k,sum=0;
    for(j=0;j<n;j++){
        cin>>a[j];
        sum+=a[j];
    }
    vector<bool>prev(sum+1,false);
    prev[a[0]]=true;
    prev[0]=true;
    for(j=1;j<n;j++){
        count=0;
        vector<bool>curr(sum+1,false);
        curr[0]=true;
        for(k=1;k<=sum;k++){
            bool pick=false;
            if(k>=a[j]){
                pick=prev[k-a[j]];
            }
            bool notpick=prev[k];
            curr[k]=pick || notpick;
            if(curr[k])
                count++;
        }
        prev=curr;
    }
    cout<<count<<endl;
    for(j=1;j<=sum;j++){
        if(prev[j])
            cout<<j<<" ";
    }
    cout<<endl;
}