#include<bits/stdc++.h>
using namespace std;
int dfs(int node,vector<int>adj[],vector<vector<int>>&dp,int par){
    int sum=0;
    for(auto it:adj[node]){
        if(it!=par){
            sum+=dfs(it,adj,dp,node);
        }
    }
    dp[node][0]=sum;
    for(auto it:adj[node]){
        if(it!=par){
            dp[node][1]=max(dp[node][1],1+sum-max(dp[it][0],dp[it][1])+dp[it][0]);
        }
    }
    return max(dp[node][0],dp[node][1]);
}
int main(){
    int N;
    cin>>N;
    vector<int>adj[N+1];
    for(int j=0;j<N-1;j++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>dp(N+1,vector<int>(2,0));
    cout<<dfs(1,adj,dp,-1)<<endl;
}