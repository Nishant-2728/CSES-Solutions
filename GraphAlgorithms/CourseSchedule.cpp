#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<int>indegree(n+1,0);
    for(int j=1;j<=m;j++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    vector<int>vis(n+1,0);
    queue<int>q;
    for(int j=1;j<=n;j++){
        if(indegree[j]==0){
            q.push(j);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(topo.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(auto it:topo){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
