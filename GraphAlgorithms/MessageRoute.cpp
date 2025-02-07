#include<bits/stdc++.h>
using namespace std;
void bfs(int node,vector<int>&vis,vector<int>&parent,vector<int>adj[],int n){
    queue<int>q;
    q.push(node);
    parent[node]=-1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(node==n){
            break;
        }
        for(auto adjacentNode:adj[node]){
            if(!vis[adjacentNode]){
                vis[adjacentNode]=1;
                parent[adjacentNode]=node;
                q.push(adjacentNode);
            }
        }
    }
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
    vector<int>parent(n+1);
    bfs(1,vis,parent,adj,n);
    if(!vis[n]){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int>path;
        path.push_back(n);
        int currnode=n;
        while(currnode!=1){
            path.push_back(parent[currnode]);
            currnode=parent[currnode];
        }
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for(auto it:path){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}