#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for(int j=0;j<m;j++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<>>pq;
    vector<long long int>dist(n+1,1e18);
    vector<int>vis(n+1,0);
    pq.push({0LL,1});
    dist[1]=0LL;
    while(!pq.empty()){
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        for(auto it:adj[node]){
            int node=it.first;
            int edgeweight=it.second;
            if(dist[node]>dis+edgeweight){
                dist[node]=dis+edgeweight;
                pq.push({dist[node],node});
            }
        }
    }
    for(int j=1;j<=n;j++){
        cout<<dist[j]<<" ";
    }
    cout<<endl;
}