#include<bits/stdc++.h>
using namespace std;
long long int MaxPages(long long int index,vector<long long int>&price,vector<long long int>&pages,long long int maxprice,vector<vector<long long int>>&dp){
    if(index==0){
        if(maxprice>=price[0])
            return pages[0];
        return 0;
    }
    if(dp[index][maxprice]!=-1){
        return dp[index][maxprice];
    }
    long long int pick=0;
    if(maxprice>=price[index]){
        pick=pages[index]+MaxPages(index-1,price,pages,maxprice-price[index],dp);
    }
    long long int notpick=MaxPages(index-1,price,pages,maxprice,dp);
    return dp[index][maxprice]=max(pick,notpick);
}
int main(){
    long long int n,x,j,k;
    cin>>n>>x;
    vector<long long int>price(n),pages(n);
    for(j=0;j<n;j++){
        cin>>price[j];
    }
    for(j=0;j<n;j++){
        cin>>pages[j];
    }
    vector<long long int>prev(x+1,0);
    for(j=price[0];j<=x;j++){
        prev[j]=pages[0];
    }
    for(j=1;j<n;j++){
        vector<long long int>curr(x+1,0);
        for(k=1;k<=x;k++){
            long long int pick=0;
            if(k>=price[j]){
                pick=pages[j]+prev[k-price[j]];
            }
            long long int notpick=prev[k];
            curr[k]=max(pick,notpick);
        }
        prev=curr;
    }
    cout<<prev[x]<<endl;
}