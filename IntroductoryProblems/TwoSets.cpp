#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,j;
    cin>>n;
    if((n*(n+1)/2)%2==0){
        cout<<"YES"<<endl;
        long long int reqdsum=n*(n+1)/4;
        long long int cnt=reqdsum/(n+1);
        set<long long int>v;
        for(j=1;j<=cnt;j++){
            v.insert(j);
            v.insert(n-j+1);
            reqdsum-=(n+1);
        }
        if(reqdsum){
            v.insert(reqdsum);
        }
        cout<<v.size()<<endl;
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;
        cout<<n-v.size()<<endl;
        for(j=1;j<=n;j++){
            if(v.find(j)==v.end()){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}