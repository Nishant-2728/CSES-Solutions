#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,m,u,v,y,j,k,q,flag=1;
    cin>>n>>m>>q;
    vector<vector<long long int>>adj(n+1,vector<long long int>(n+1,1e18));
    for(j=0;j<m;j++){
        cin>>u>>v>>y;
        adj[u][v]=min(adj[u][v],y);
        adj[v][u]=min(adj[u][v],y);
    }
    for(j=1;j<=n;j++){
        adj[j][j]=0;
    }
    for(int via=1;via<=n;via++){
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                adj[j][k]=min(adj[j][k],adj[j][via]+adj[via][k]);
            }
        }
    }
    for(j=1;j<=n;j++){
        for(k=1;k<=n;k++){
            if(adj[j][k]==1e18)
                adj[j][k]=-1;
        }
    }
    for(j=1;j<=q;j++){
        cin>>u>>v;
        cout<<adj[u][v]<<endl;
    }
}