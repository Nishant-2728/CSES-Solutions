#include<bits/stdc++.h>
using namespace std;
const long long int M=1e9+7;
long long int binexp(long long int x,long long int y){
    x%=M;
    long long int ans=1;
    while(y>0){
        if(y%2==0){
            x=(x*x)%M;
            y/=2;
        }
        else{
            ans=(ans*x)%M;
            y--;
        }
    }
    return ans;
}
int main(){
    long long int n;
    cin>>n;
    cout<<binexp(2LL,n)<<endl;
}