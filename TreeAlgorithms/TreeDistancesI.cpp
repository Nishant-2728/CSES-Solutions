#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],vector<int>&maxdist,vector<int>&downpath,int par){
    for(auto it:adj[node]){
        if(it!=par){
            dfs(it,adj,maxdist,downpath,node);
            downpath[node]=max(downpath[node],1+downpath[it]);
            maxdist[node]=downpath[node];
        }
    }
}
void solve(int node,vector<int>adj[],vector<int>&maxdist,vector<int>&downpath,int par,int par_ans){
    vector<int>prefixmax,suffixmax;
    for(auto it:adj[node]){
        if(it!=par){
            prefixmax.push_back(downpath[it]);
            suffixmax.push_back(downpath[it]);
        }
    }
    for(int j=1;j<prefixmax.size();j++){
        prefixmax[j]=max(prefixmax[j],prefixmax[j-1]);
    }
    for(int j=(int)suffixmax.size()-1;j>=0;j--){
        suffixmax[j]=max(suffixmax[j],suffixmax[j+1]);
    }
    int childcount=0;
    for(auto it:adj[node]){
        if(it!=par){
            int op1=(childcount==0?INT_MIN:prefixmax[childcount-1]);
            int op2=(childcount==(int)suffixmax.size()-1?INT_MIN:suffixmax[childcount+1]);
            int partial_ans=1+max({par_ans,op1,op2});
            solve(it,adj,maxdist,downpath,node,partial_ans);
            childcount++;
        }
    }
    maxdist[node]=1+max(par_ans,(prefixmax.size()?prefixmax.back():-1));
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
    vector<int>maxdist(N+1,0);
    vector<int>downpath(N+1,0);
    dfs(1,adj,maxdist,downpath,-1);
    solve(1,adj,maxdist,downpath,-1,-1);
    for(int j=1;j<=N;j++){
        cout<<maxdist[j]<<" ";
    }
    cout<<endl;
}