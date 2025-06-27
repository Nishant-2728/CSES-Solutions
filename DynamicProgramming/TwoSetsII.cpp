#include<bits/stdc++.h>
using namespace std;
const long long int M=1e9+7;
long long int Countways(long long int val,long long int sum,vector<vector<long long int>>&dp){
    if(sum==0)
        return 1;
    if(val==1)
        return (sum==1LL?1:0);
    if(dp[val][sum]!=-1)
        return dp[val][sum];
    long long int total=0;
    if(sum>=val){
        total=(total+Countways(val-1,sum-val,dp))%M;
    }
    total=(total+Countways(val-1,sum,dp))%M;
    return dp[val][sum]=total;
}
long long int powi(long long int x,long long int n){
    long long int ans=1;
    x%=M;
    while(n){
        if(n%2){
            ans=(ans*x)%M;
            n--;
        }
        else{
            x=(x*x)%M;
            n/=2;
        }
    }
    return ans;
}
long long int modinverse(long long int m){
    return powi(m,M-2);
}
int main(){
    long long int n;
    cin>>n;
    long long int sum=n*(n+1)/2;
    if(sum%2){
        cout<<0<<endl;
    }
    else{
        vector<long long int>prev(sum/2+1,0);
        long long int j,k;
        prev[0]=prev[1]=1;
        for(j=2;j<=n;j++){
            vector<long long int>curr(sum/2+1,0);
            curr[0]=1;
            for(k=1;k<=sum/2;k++){
                long long int total=0;
                if(k>=j){
                    total=(total+prev[k-j])%M;
                }
                total=(total+prev[k])%M;
                curr[k]=total;
            }
            prev=curr;
        }
        cout<<(prev[sum/2]*modinverse(2))%M<<endl;
    }
    
}