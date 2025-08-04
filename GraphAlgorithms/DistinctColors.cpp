#include<bits/stdc++.h>
using namespace std;
set<int>dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&colors,vector<int>&distinctcount){
    vis[node]=1;
    set<int>st;
    for(auto it:adj[node]){
        if(!vis[it]){
            set<int>x=dfs(it,adj,vis,colors,distinctcount);
            for(auto it:x){
                st.insert(it);
            }
        }
    }
    st.insert(colors[node]);
    distinctcount[node]=st.size();
    return st;
}
int main(){
    int n;
    cin>>n;
    vector<int>colors(n+1);
    for(int j=1;j<=n;j++){
        cin>>colors[j];
    }
    vector<int>adj[n+1];
    for(int j=0;j<n-1;j++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>distinctcount(n+1,0);
    vector<int>vis(n+1,0);
    dfs(1,adj,vis,colors,distinctcount);
    for(int j=1;j<=n;j++){
        cout<<distinctcount[j]<<" ";
    }
    cout<<endl;
}