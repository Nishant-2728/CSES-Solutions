#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,p=5;
    cin>>n;
    long long int cnt=0;
    while(n/p){
        cnt+=n/p;
        p*=5;
    }
    cout<<cnt<<endl;
}