#include<bits/stdc++.h>
using namespace std;
void Djikstra(int startnode,vector<pair<int,int>>adj[],vector<long long int>&dist){
    set<pair<long long int,int>>st;
    st.insert({0LL,startnode});
    dist[startnode]=0;
    while(!st.empty()){
        auto it=st.begin();
        int node=it->second;
        long long int distance=it->first;
        st.erase(it);
        for(auto it1:adj[node]){
            int adjNode=it1.first;
            int edgewt=it1.second;
            if(dist[adjNode]>distance+1LL*edgewt){
                if(dist[adjNode]!=1e18){
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode]=distance+edgewt;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    vector<pair<int,int>>adj1[n+1];
    vector<int>u(m),v(m),w(m);
    for(int j=0;j<m;j++){
        cin>>u[j]>>v[j]>>w[j];
        adj[u[j]].push_back({v[j],w[j]});
        adj1[v[j]].push_back({u[j],w[j]});
    }
    vector<long long int>dist1(n+1,1e18);
    vector<long long int>dist2(n+1,1e18);
    Djikstra(1,adj,dist1);
    Djikstra(n,adj1,dist2);
    long long int mindist=1e18;
    for(int j=0;j<m;j++){
        mindist=min(mindist,dist1[u[j]]+w[j]/2+dist2[v[j]]);
    }
    cout<<mindist<<endl;
}