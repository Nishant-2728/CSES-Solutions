#include<bits/stdc++.h>
using namespace std;
void dfs(int node,set<int>adj[],vector<int>&ans){
    while(adj[node].size()>0){
        auto it=adj[node].begin();
        int adjNode=*it;
        adj[node].erase(adjNode);
        adj[adjNode].erase(node);
        dfs(adjNode,adj,ans);
    }
    ans.push_back(node);
}
int main(){
    int n,m;
    cin>>n>>m;
    set<int>adj[n+1];
    for(int j=0;j<m;j++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int count=0;
    for(int j=1;j<=n;j++){
        if(adj[j].size()%2 || adj[j].size()==0){
            count++;
        }
    }
    if(count>0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int>ans;
        dfs(1,adj,ans);
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}