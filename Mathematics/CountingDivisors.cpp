#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[1000001]={0};
void calc(){
    for(ll j=1;j<=1000000;j++){
        for(ll k=j;k<=1000000;k+=j){
            a[k]++;
        }
    }
}
int main(){
calc();
ll T;
cin>>T;
while(T--){
    int n;
    cin>>n;
    cout<<a[n]<<endl;
}
}

 
