#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,k;
    cin>>n;
    for(k=1;k<=n;k++){
        cout<<(k*k)*((k*k)-1)/2-4*(k-1)*(k-2)<<endl;
    }
}