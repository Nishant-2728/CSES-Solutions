#include<bits/stdc++.h>
using namespace std;
void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&parent,string S[],int n,int m){
    queue<pair<int,int>>q;
    q.push({row,col});
    vis[row][col]=1;
    int delrow[]={1,0,-1,0};
    int delcol[]={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        if(S[row][col]=='B'){
            break;
        }
        q.pop();
        for(int j=0;j<4;j++){
            int row1=row+delrow[j];
            int col1=col+delcol[j];
            if((row1>=0 && row1<n) && (col1>=0 && col1<m)){
                if(!vis[row1][col1] && S[row1][col1]!='#'){
                    vis[row1][col1]=1;
                    parent[row1][col1]=j;
                    q.push({row1,col1});
                }
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    string S[n];
    for(int j=0;j<n;j++){
        cin>>S[j];
    }
    int delrow[]={1,0,-1,0};
    int delcol[]={0,1,0,-1};
    int rowA,colA,rowB,colB;
    queue<pair<int,int>>q;
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>par(n,vector<int>(m));
    for(int j=0;j<n;j++){
        for(int k=0;k<m;k++){
            if(S[j][k]=='A'){
                rowA=j;
                colA=k;
            }
            else if(S[j][k]=='B'){
                rowB=j;
                colB=k;
            }
        }
    }
    bfs(rowA,colA,vis,par,S,n,m);
    int minPathLength=0;
    string move="DRUL";
    vector<char>path;
    if(!vis[rowB][colB]){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        int row=rowB,col=colB;
        while(row!=rowA || col!=colA){
            minPathLength++;
            path.push_back(move[par[row][col]]);
            int rowdiff=delrow[par[row][col]];
            int coldiff=delcol[par[row][col]];
            row=row-rowdiff;
            col=col-coldiff;
        }
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for(auto it:path){
            cout<<it;
        }
        cout<<endl;
    }
}