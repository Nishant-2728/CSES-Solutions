#include<bits/stdc++.h>
using namespace std;
void bfs(int row,int col,int n,int m,vector<vector<int>>&vis,string S[]){
    queue<pair<int,int>>q;
    q.push({row,col});
    vis[row][col]=1;
    int delrow[]={1,0,-1,0};
    int delcol[]={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int j=0;j<4;j++){
            int row1=row+delrow[j];
            int col1=col+delcol[j];
            if((row1>=0 && row1<n) && (col1>=0 && col1<m)){
                if(!vis[row1][col1] && S[row1][col1]=='.'){
                    vis[row1][col1]=1;
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
    int countRooms=0;
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(!vis[row][col] && S[row][col]=='.'){
                countRooms++;
                bfs(row,col,n,m,vis,S);
            }
        }
    }
    cout<<countRooms<<endl;
}