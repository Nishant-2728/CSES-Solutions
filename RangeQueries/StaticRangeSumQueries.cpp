#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,q;
    cin>>n>>q;
    long long int a[n],j;
    for(j=0;j<n;j++){
        cin>>a[j];
        if(j)
            a[j]+=a[j-1];
    }
    for(j=0;j<q;j++){
        int x,b;
        cin>>x>>b;
        x--;
        b--;
        cout<<a[b]-(x-1>=0?a[x-1]:0)<<"\n";
    }
}
