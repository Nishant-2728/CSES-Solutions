#include<bits/stdc++.h>
using namespace std;
void bfs(int node,vector<int>adj[],vector<int>&vis){
    queue<int>q;
    q.push(node);
    vis[node]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto adjacentNodes:adj[node]){
            if(!vis[adjacentNodes]){
                vis[adjacentNodes]=1;
                q.push(adjacentNodes);
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
    vector<int>endsofnewRoads;
    for(int j=1;j<=n;j++){
        if(!vis[j]){
            endsofnewRoads.push_back(j);
            bfs(j,adj,vis);
        }
    }
    int sz=endsofnewRoads.size();
    cout<<sz-1<<endl;
    for(int j=0;j<sz-1;j++){
        cout<<endsofnewRoads[j]<<" "<<endsofnewRoads[j+1]<<endl;
    }
}