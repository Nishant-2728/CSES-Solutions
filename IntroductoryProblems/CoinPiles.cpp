#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,T;
    cin>>T;
    for(i=1;i<=T;i++){
        long long int a,b;
        cin>>a>>b;
        if((2*b-a)%3==0 && (2*b-a)/3>=0 && (2*a-b)%3==0 && (2*a-b)/3>=0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}