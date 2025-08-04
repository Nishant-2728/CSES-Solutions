#include<bits/stdc++.h>
using namespace std;
int dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&down){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            down[node]+=dfs(it,adj,vis,down);
        }
    }
    down[node]++;
    return down[node];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int j=0;j<m;j++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>down(n+1,0);
    vector<int>up(n+1,0);
    vector<int>vis(n+1,0);
    vector<int>vis1(n+1,0);
    dfs(1,adj,vis,down);
    queue<int>q;
    q.push(1);
    vis1[1]=1;
    up[1]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(!vis1[it]){
                vis1[it]=1;
                up[it]=up[node]+down[node]-down[it]-1;
                q.push(it);
            }
        }
    }
    for(int j=1;j<=n;j++){
        cout<<up[j]*down[j]<<" ";
    }
    cout<<endl;
}