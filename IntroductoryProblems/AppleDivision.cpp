#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int a[n],j,k,mindiff=1e18;
    for(j=0;j<n;j++){
        cin>>a[j];
    }
    for(j=0;j<(1LL<<n);j++){
        long long int sum1=0,sum2=0;
        for(k=0;k<n;k++){
            if((j>>k)&1LL){
                sum1+=a[k];
            }
            else{
                sum2+=a[k];
            }
        }
        mindiff=min(mindiff,abs(sum1-sum2));
    }
    cout<<mindiff<<endl;

}