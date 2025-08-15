#include<bits/stdc++.h>
using namespace std;
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
int Queryans(int node,int k,vector<vector<int>>&up){
    if(node==-1 || k==0){
        return node;
    }
    for(int j=19;j>=0;j--){
        if((k>>j)&1){
            return Queryans(up[node][j],k-(1<<j),up);
        }
    }
    return 0;
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
    vector<vector<int>>up(N+1,vector<int>(20,-1));
    binary_lifting(1,adj,up,-1);
    while(Q--){
        int node,k;
        cin>>node>>k;
        cout<<Queryans(node,k,up)<<endl;
    }
}