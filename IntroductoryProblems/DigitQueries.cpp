#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll powi(ll x,ll y){
    ll ans=1;
    while(y){
        if(y%2==0){
            x=(x*x);
            y/=2;
        }
        else{
            ans=(ans*x);
            y--;
        }
    }
    return ans;
}
int main() {
    ll T;
    cin>>T;
    while(T--){
        ll k;
        cin>>k;
        ll start=1,end=17,ans=0;
        while(start<=end){
            ll mid=start+(end-start)/2;
            if(powi(10,mid)*mid-(powi(10,mid)-1)/9<k){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        k-=powi(10,ans)*ans-(powi(10,ans)-1)/9;
        ll num=powi(10,ans)-1;
        if(k%(ans+1)==0){
            num+=k/(ans+1);
            cout<<num%10<<"\n";
        }
        else{
            num+=k/(ans+1)+1;
            ll cnt=ans+2-k%(ans+1);
            ll res;
            while(cnt--){
                res=num%10;
                num/=10;
            }
            cout<<res<<"\n";
        }
    }
}
