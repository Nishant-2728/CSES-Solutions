#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
   ll n,k;
   cin>>n>>k;
   vector<ll>a(n,-1);
   if(k<=n-1){
       a[n-1-k]=n;
   }
   else{
      ll start=n;
      for(ll j=n-1;j>=1;j--){
          if(j<=k){
              a[n-1-j]=start--;
              k-=j;
          }
      }
   }
   ll start=1;
   for(ll j=0;j<n;j++){
       if(a[j]==-1){
           a[j]=start++;
       }
   }
   for(ll j=0;j<n;j++){
       cout<<a[j]<<" ";
   }
   cout<<"\n";
}
