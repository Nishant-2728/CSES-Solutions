#include<bits/stdc++.h>
using namespace std;
const long long int M=1e9+7;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<int>indegree(n+1,0);
    for(int j=0;j<m;j++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int>q;
    for(int j=1;j<=n;j++) {
        if(indegree[j]==0){
            q.push(j);
        }
    }
    vector<int>topo;
    while(!q.empty()) {
        int node=q.front(); 
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]) {
            indegree[it]--;
            if (indegree[it]==0) {
                q.push(it);
            }
        }
    }
    vector<long long>paths(n+1,0);
    paths[1]=1LL;
    for(auto node:topo) {
        for(auto it: adj[node]) {
            paths[it]=(paths[it]+paths[node]) % M;
        }
    }
    cout<<paths[n]<<endl;
}