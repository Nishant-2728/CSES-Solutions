#include<bits/stdc++.h>
using namespace std;
void dfs(int node,set<int>adj[],vector<int>&ans){
    while(adj[node].size()){
        auto it=adj[node].begin();
        int adjNode=*it;
        adj[node].erase(it);
        dfs(adjNode,adj,ans);
    }
    ans.push_back(node);
}
int main(){
    int n,m;
    cin>>n>>m;
    set<int>adj[n+1];
    vector<int>indegree(n+1,0);
    for(int j=0;j<m;j++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        indegree[v]++;
    }
    int count=0;
    int flag=1;
    for(int j=1;j<=n;j++){
        if(abs(indegree[j]-(int)adj[j].size())==1){
            count++;
        }
        else if(abs(indegree[j]-(int)adj[j].size())>1){
            flag=0;
            break;
        }
    }
    if(count!=2 && count!=0){
        flag=0;
    }
    if(flag==0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else if(adj[1].size()-indegree[1]!=1 && indegree[n]-adj[n].size()!=1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int>ans;
        dfs(1,adj,ans);
        for(int j=1;j<=n;j++){
            if(adj[j].size()>0){
                flag=0;
                break;
            }
        }
        if(flag==0){
            cout<<"IMPOSSIBLE"<<endl;
        }
        else{
            reverse(ans.begin(),ans.end());
            for(auto it:ans){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
}