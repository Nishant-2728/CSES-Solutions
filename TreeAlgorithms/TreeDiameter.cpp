#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],vector<int>&dist,int par){
    for(auto it:adj[node]){
        if(it!=par){
            dist[it]=dist[node]+1;
            dfs(it,adj,dist,node);
        }
    }
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
    vector<int>dist1(N+1,0);
    dfs(1,adj,dist1,-1);
    int node=1,d=0;
    for(int j=1;j<=N;j++){
        if(dist1[j]>d){
            d=dist1[j];
            node=j;
        }
    }
    vector<int>dist2(N+1,0);
    dfs(node,adj,dist2,-1);
    int dia=0;
    for(int j=1;j<=N;j++){
        dia=max(dia,dist2[j]);
    }
    cout<<dia<<endl;
}