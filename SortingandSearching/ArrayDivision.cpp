#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll isPossible(vector<ll>&a,ll n,ll mid){
    ll sum=0,count=1;
    for(ll j=0;j<n;j++){
        if(sum+a[j]<=mid){
            sum+=a[j];
        }
        else{
            count++;
            sum=a[j];
        }
    }
    return count;
}
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    ll maxi=0,sum=0;
    for(ll j=0;j<n;j++){
        cin>>a[j];
        maxi=max(maxi,a[j]);
        sum+=a[j];
    }
    ll start=maxi,end=sum;
    while(start<=end){
        ll mid=start+(end-start)/2;
        if(isPossible(a,n,mid)>k){
            start=mid+1;
        }
        else
            end=mid-1;
    }
    cout<<start<<endl;
}
