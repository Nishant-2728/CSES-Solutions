#include<bits/stdc++.h>
using namespace std;
void dfs(int row,int col,vector<vector<int>>&vis,vector<int>&ans){
    vis[row][col]=1;
    int delrow[]={1,-1,1,-1,2,-2,2,-2};
    int delcol[]={2,2,-2,-2,1,1,-1,-1};
    for(int j=0;j<8;j++){
        int row1=row+delrow[j];
        int col1=col+delcol[j];
        if((row1>=1 && row1<=8) && (col1>=1 && col1<=8)){
            if(!vis[row1][col1]){
                dfs(row1,col1,vis,ans);
            }
        }
    }
    ans.push_back((row-1)*8+col);
}
int main(){
    int x,y;
    cin>>x>>y;
    vector<vector<int>>vis(9,vector<int>(9,0));
    vector<int>ans;
    dfs(x,y,vis,ans);
    for(int j=0;j<64;j++){
        cout<<ans[j]<<" ";
        if(j%8==7){
            cout<<endl;
        }
    }
}