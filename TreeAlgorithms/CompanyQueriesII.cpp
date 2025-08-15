#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],vector<int>&level,int par){
    for(auto it:adj[node]){
        if(it!=par){
            level[it]=level[node]+1;
            dfs(it,adj,level,node);
        }
    }
}
void binary_lifting(int node,vector<int>adj[],vector<vector<int>>&up,int par){
    up[node][0]=par;
    for(int j=1;j<20;j++){
        if(up[node][j-1]!=-1){
            up[node][j]=up[up[node][j-1]][j-1];
        }
    }
    for(auto it:adj[node]){
        if(it!=par)
            binary_lifting(it,adj,up,node);
    }
}
int findnode(int node,vector<vector<int>>&up,int k){
    if(node==-1 || k==0){
        return node;
    }
    for(int j=19;j>=0;j--){
        if((k>>j)&1){
            return findnode(up[node][j],up,k-(1<<j));
        }
    }
    return 0;
}
int findLCA(int u,int v,vector<int>&level,vector<vector<int>>&up){
    if(level[u]<level[v]){
        swap(u,v);
    }
    u=findnode(u,up,level[u]-level[v]);
    int start=0,end=level[u],ans;
    while(start<=end){
        int mid=start+(end-start)/2;
        int node1=findnode(u,up,mid);
        int node2=findnode(v,up,mid);
        if(node1==node2){
            ans=node1;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
int findLCA2(int u,int v,vector<int>&level,vector<vector<int>>&up){
    if(level[u]<level[v]){
        swap(u,v);
    }
    u=findnode(u,up,level[u]-level[v]);
    if(u==v){
        return u;
    }
    for(int j=19;j>=0;j--){
        if(up[u][j]!=up[v][j]){
            u=up[u][j];
            v=up[v][j];
        }
    }
    return up[u][0];
}
int main(){
    int N,Q;
    cin>>N>>Q;
    vector<int>adj[N+1];
    for(int j=2;j<=N;j++){
        int u;
        cin>>u;
        adj[u].push_back(j);
    }
    vector<int>level(N+1,0);
    dfs(1,adj,level,-1);
    vector<vector<int>>up(N+1,vector<int>(20,-1));
    binary_lifting(1,adj,up,-1);
    while(Q--){
        int u,v;
        cin>>u>>v;
        cout<<findLCA2(u,v,level,up)<<endl;
    }
}