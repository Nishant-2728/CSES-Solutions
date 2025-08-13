#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],vector<int>&dia,vector<int>&downpath,int par){
    int maxi1=0,maxi2=0,cnt=0;
    for(auto it:adj[node]){
        if(it!=par){
           cnt++;
           dfs(it,adj,dia,downpath,node);
           downpath[node]=max(downpath[node],downpath[it]+1);
           dia[node]=max(dia[node],dia[it]);
           if(downpath[it]>maxi1){
                maxi2=maxi1;
                maxi1=downpath[it];
           }
           else if(downpath[it]>maxi2){
                maxi2=downpath[it];
           }
        }
    }
    if(cnt==1){
        dia[node]=max(dia[node],1+maxi1);
    }
    else if(cnt>=2){
        dia[node]=max(dia[node],2+maxi1+maxi2);
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
    vector<int>dia(N+1,0);
    vector<int>downpath(N+1,0);
    dfs(1,adj,dia,downpath,-1);
    cout<<dia[1]<<endl;
}