#include<bits/stdc++.h>
using namespace std;
const long long int M=1e9+7;
int main(){
    long long int n,j;
    cin>>n;
    string S[n];
    for(j=0;j<n;j++){
        cin>>S[j];
    }
    vector<vector<long long int>>dp(n,vector<long long int>(n,0));
    dp[0][0]=1;
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            if(j-1>=0 && S[j-1][k]!='*'){
                dp[j][k]+=dp[j-1][k];
                dp[j][k]%=M;
            }
            if(k-1>=0 && S[j][k-1]!='*'){
                dp[j][k]+=dp[j][k-1];
                dp[j][k]%=M;
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
}