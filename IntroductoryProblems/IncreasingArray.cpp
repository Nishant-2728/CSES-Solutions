#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int a[n],j,ans=0;
    for(j=0;j<n;j++){
        cin>>a[j];
    }
    for(j=1;j<n;j++){
        if(a[j]>=a[j-1])
            continue;
        else{
            ans+=a[j-1]-a[j];
            a[j]=a[j-1];
        }
    }
    cout<<ans<<endl;
}