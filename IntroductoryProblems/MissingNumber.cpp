#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int a[n-1],j,sum=0;
    for(j=0;j<n-1;j++){
        cin>>a[j];
        sum+=a[j];
    }
    cout<<n*(n+1)/2-sum<<endl;
}
