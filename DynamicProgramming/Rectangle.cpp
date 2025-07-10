#include<bits/stdc++.h>
using namespace std;
int Minsteps(int length,int width,vector<vector<int>>&dp){
    if(length==width){
        return 0;
    }
    if(dp[length][width]!=-1){
        return dp[length][width];
    }
    int mini=1e9;
    for(int j=1;j<width;j++){
        mini=min(mini,1+Minsteps(length,j,dp)+Minsteps(length,width-j,dp));
    }
    for(int j=1;j<length;j++){
        mini=min(mini,1+Minsteps(j,width,dp)+Minsteps(length-j,width,dp));
    }
    return dp[length][width]=mini;
}
int main(){
    int a,b;//counter TC to greedy : 6 7
    cin>>a>>b;
    vector<vector<int>>dp(a+1,vector<int>(b+1,0));
    for(int length=1;length<=a;length++){
        for(int width=1;width<=b;width++){
            if(length!=width){
                int mini=1e9;
                for(int j=1;j<width;j++){
                    mini=min(mini,1+dp[length][j]+dp[length][width-j]);
                }
                for(int j=1;j<length;j++){
                    mini=min(mini,1+dp[j][width]+dp[length-j][width]);
                }
                dp[length][width]=mini;
            }
        }
    }
    cout<<dp[a][b]<<endl;
}