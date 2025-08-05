#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,u,v,j;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<int>indegree(n+1,0);
    for(j=1;j<=m;j++){
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int>q;
    for(int j=1;j<=n;j++) {
        if(indegree[j]==0)
            q.push(j);
    }
    vector<int>dist(n+1,INT_MIN);
    vector<int>parent(n+1,-1);
    dist[1] = 0;
    while (!q.empty()) {
        int node=q.front();
        q.pop();
        for(auto next:adj[node]) {
            if (dist[next]<dist[node]+1) {
                dist[next]=dist[node]+1;
                parent[next]=node;
            }
            indegree[next]--;
            if(indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if(dist[n]==INT_MIN){
        cout<<"IMPOSSIBLE"<<endl;
    } 
    else{
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
}
