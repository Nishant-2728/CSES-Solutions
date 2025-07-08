#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<vector<int>>v(N,vector<int>(3));
    vector<int>startTime(N);
    for(int j=0;j<N;j++){
        cin>>v[j][0]>>v[j][1]>>v[j][2];
        startTime[j]=v[j][0];
    }
    sort(v.begin(),v.end());
    sort(startTime.begin(),startTime.end());
    vector<long long int>dp(N+1,0);
    for(int index=N-1;index>=0;index--){
        long long int nottake=dp[index+1];
        long long int take=1LL*v[index][2];
        int idx=lower_bound(startTime.begin()+index+1,startTime.end(),v[index][1]+1)-startTime.begin();
        take+=dp[idx];
        dp[index]=max(take,nottake);
    }
    cout<<dp[0]<<endl;
}