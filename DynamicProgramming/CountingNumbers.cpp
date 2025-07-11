#include<bits/stdc++.h>
using namespace std;
long long int Count(string &number,int N,int X,bool leading_zeros,bool tight,vector<vector<vector<vector<long long int>>>>&dp){
    if(N==0){
        return 1LL;
    }
    if(dp[N][X][leading_zeros][tight]!=-1){
        return dp[N][X][leading_zeros][tight];
    }
    int lb=0;
    int ub=tight?(number[number.size()-N]-'0'):9;
    long long int ans=0;
    for(int dig=lb;dig<=ub;dig++){
        if(dig==X && (!leading_zeros)){
            continue;
        }
        ans+=Count(number,N-1,dig,(leading_zeros & (dig==0)),(tight&(dig==ub)),dp);
    }
    return dp[N][X][leading_zeros][tight]=ans;
}
int main(){
    long long int a,b;
    cin>>a>>b;
    string A=to_string(a-1);
    string B=to_string(b);
    vector<vector<vector<vector<long long int>>>>dp1(20,vector<vector<vector<long long int>>>(11,vector<vector<long long int>>(2,vector<long long int>(2,-1))));
    vector<vector<vector<vector<long long int>>>>dp2(20,vector<vector<vector<long long int>>>(11,vector<vector<long long int>>(2,vector<long long int>(2,-1))));
    cout<<Count(B,B.size(),10,1,1,dp1)-Count(A,A.size(),10,1,1,dp2)<<endl;
}