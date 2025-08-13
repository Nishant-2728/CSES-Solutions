#include<bits/stdc++.h>
using namespace std;
int dfs(int node,vector<int>adj[],vector<int>&subordinatescount){
    int cnt=0;
    for(auto it:adj[node]){
        cnt+=dfs(it,adj,subordinatescount);
    }
    subordinatescount[node]=cnt;
    return cnt+1;
}
int main(){
   int N;
   cin>>N;
   vector<int>adj[N+1];
   for(int j=2;j<=N;j++){
        int u;
        cin>>u;
        adj[u].push_back(j);
   }
   vector<int>subordinatescount(N+1,0);
   dfs(1,adj,subordinatescount);
   for(int j=1;j<=N;j++){
        cout<<subordinatescount[j]<<" ";
   }
   cout<<endl;
}
