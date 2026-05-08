#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll j=0;j<n;j++){
        cin>>a[j];
    }
    multiset<ll>st;
    st.insert(a[0]);
    for(ll j=1;j<n;j++){
        auto it=st.upper_bound(a[j]);
        if(it!=st.end()){
            st.erase(it);
            st.insert(a[j]);
        }
        else{
            st.insert(a[j]);
        }
    }
    cout<<st.size()<<"\n";
}
