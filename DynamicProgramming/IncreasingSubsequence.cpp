#include<bits/stdc++.h>
using namespace std;
int LIS(int index,vector<int>&a,int prev_index,vector<vector<int>>&dp){
    if(index==a.size()){
        return 0;
    }
    if(dp[index][prev_index]!=-1){
        return dp[index][prev_index];
    }
    int take=0,nottake=0;
    if(prev_index==a.size()){
        take=1+LIS(index+1,a,index,dp);
        nottake=0+LIS(index+1,a,prev_index,dp);
    }
    else{
        nottake=0+LIS(index+1,a,prev_index,dp);
        if(a[index]>a[prev_index]){
            take=1+LIS(index+1,a,index,dp);
        }
    }
    return dp[index][prev_index]=max(take,nottake);
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int j=0;j<n;j++){
        cin>>a[j];
    }
    vector<int>temp;
    temp.push_back(a[0]);
    int len=1;
    for(int j=1;j<n;j++){
        if(a[j]>temp.back()){
            len++;
            temp.push_back(a[j]);
        }
        else{
            int idx=lower_bound(temp.begin(),temp.end(),a[j])-temp.begin();
            temp[idx]=a[j];
        }
    }
    cout<<len<<endl;
}