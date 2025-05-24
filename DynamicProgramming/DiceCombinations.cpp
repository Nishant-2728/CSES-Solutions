#include<bits/stdc++.h>
using namespace std;
const long long int M=1e9+7;
int main(){
    long long int n;
    cin>>n;
    long long int prev3=1,prev2=1,prev=2,prev4=0,prev5=0,prev6=0;
    for(int j=3;j<=n;j++){
        long long int curr=(((prev%M)+(prev2%M))%M+(prev3%M))%M;
        curr=(curr+prev4)%M;
        curr=(curr+prev5)%M;
        curr=(curr+prev6)%M;
        prev6=prev5;
        prev5=prev4;
        prev4=prev3;
        prev3=prev2;
        prev2=prev;
        prev=curr;
    }
    cout<<(n==1?prev2:prev)<<endl;
}