#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,u,v,j;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(j=1;j<=m;j++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>dist(n+1,0);
    vector<int>parent(n+1,0);
    dist[1]=0;
    parent[1]=-1;
    priority_queue<pair<int,int>>q;
    q.push({0,1});
    while(!q.empty()){
        int node=q.top().second;
        int dis=q.top().first;
        q.pop();
        for(auto it:adj[node]){
            if(dist[it]<dis+1){
                dist[it]=dis+1;
                parent[it]=node;
                q.push({dist[it],it});
            }
        }
    }
    if(dist[n]!=0){
        cout<<dist[n]+1<<endl;
        vector<int>ans;
        ans.push_back(n);
        while(n!=1){
            ans.push_back(parent[n]);
            n=parent[n];
        }
        reverse(ans.begin(),ans.end());
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}