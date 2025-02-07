#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<int>&vis,vector<int>&par,vector<int>adj[],vector<int>&cyclepath){
    vis[node]=1;
    for(auto adjacentNode:adj[node]){
        if(!vis[adjacentNode]){
            par[adjacentNode]=node;
            if(dfs(adjacentNode,vis,par,adj,cyclepath)==true)
                return true;
        }
        else if(adjacentNode!=par[node]){
            cyclepath.push_back(node);
            int x=node;
            while(x!=adjacentNode){
                cyclepath.push_back(par[x]);
                x=par[x];
            }
            cyclepath.push_back(node);
            return true;
        }
    }
    return false;
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
    vector<int>vis(n+1,0);
    vector<int>par(n+1);
    vector<int>cyclepath;
    for(int j=1;j<=n;j++){
        if(!vis[j]){
            par[j]=-1;
            if(dfs(j,vis,par,adj,cyclepath)==true){
                break;
            }
        }
    }
    if(cyclepath.size()==0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<cyclepath.size()<<endl;
        for(auto it:cyclepath){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}