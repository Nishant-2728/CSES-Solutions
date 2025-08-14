#include<bits/stdc++.h>
using namespace std;
int dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&down,vector<int>&sumofdistances){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            down[node]+=dfs(it,adj,vis,down,sumofdistances);
            sumofdistances[node]+=1LL*sumofdistances[it]+1LL*down[it];
        }
    }
    down[node]++;
    return down[node];
}
void dfs1(int node,vector<int>adj[],vector<int>&vis,vector<int>&down,vector<int>&sumofdistances,int n){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            sumofdistances[it]=1LL*sumofdistances[node]-1LL*down[it]+1LL*n-1LL*down[it];
            dfs1(it,adj,vis,down,sumofdistances,n);
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
    vector<long long int>sumofdistances(N+1,0);
    vector<int>down(N+1,0);
    vector<int>vis(N+1,0);
    vector<int>vis1(N+1,0);
    dfs(1,adj,vis,down,sumofdistances);
    dfs1(1,adj,vis1,down,sumofdistances,N);
    for(int j=1;j<=N;j++){
        cout<<sumofdistances[j]<<" ";
    }
    cout<<endl;
}
