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
   vector<long long int>prev1(N,0),prev2(N,0);
    prev1[N-1]=a[N-1];
    for(int start=N-2;start>=0;start--){
        vector<long long int>curr1(N,0),curr2(N,0);
        curr1[start]=a[start];
        for(int end=start+1;end<N;end++){
            long long int first=0,last=0;
            first=1LL*a[start]+prev2[end];
            last=1LL*a[end]+curr2[end-1];
            curr1[end]=max(first,last);
            first=prev1[end];
            last=curr1[end-1];
            curr2[end]=min(first,last);    
        }
        prev1=curr1;
        prev2=curr2;
    }
    cout<<prev1[N-1]<<endl;
}
