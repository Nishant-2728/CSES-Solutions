#include<bits/stdc++.h>
using namespace std;
long long int Maxscore(vector<int>&a,int start,int end,int turn,vector<vector<vector<long long int>>>&dp){
    if(start==end){
        if(turn==0){
            return a[start];
        }
        return 0LL;
    }
    if(dp[start][end][turn]!=-1){
        return dp[start][end][turn];
    }
    long long int first=0,last=0;
    if(turn==0){
        first=a[start]+Maxscore(a,start+1,end,1,dp);
        last=a[end]+Maxscore(a,start,end-1,1,dp);
        return dp[start][end][turn]=max(first,last);
    }
    else if(turn==1){
        first=Maxscore(a,start+1,end,0,dp);
        last=Maxscore(a,start,end-1,0,dp);
        return dp[start][end][turn]=min(first,last);
    }
    return 0LL;
}
int main(){
    int N;
    cin>>N;
    vector<int>a(N);
    for(int j=0;j<N;j++){
        cin>>a[j];
    }
    vector<vector<vector<long long int>>>dp(N,vector<vector<long long int>>(N,vector<long long int>(2,0)));
    for(int j=0;j<N;j++){
        dp[j][j][0]=a[j];
    }
    for(int start=N-2;start>=0;start--){
        for(int end=1;end<N;end++){
            for(int turn=0;turn<2;turn++){
                long long int first=0,last=0;
                if(turn==0){
                    first=a[start]+dp[start+1][end][1];
                    last=a[end]+dp[start][end-1][1];
                    return dp[start][end][turn]=max(first,last);
                }
            else if(turn==1){
                first=Maxscore(a,start+1,end,0,dp);
                last=Maxscore(a,start,end-1,0,dp);
                return dp[start][end][turn]=min(first,last);
            }
            }
        }
    }
}