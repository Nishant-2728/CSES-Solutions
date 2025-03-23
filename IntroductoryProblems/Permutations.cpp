#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,start;
    cin>>n;
    if(n==2 || n==3){
        cout<<"NO SOLUTION"<<endl;
    }
    else{
        if(n%2==0){
            start=n-1;
        }
        else{
            start=n;
        }
        for(int j=start;j>=1;j-=2){
            cout<<j<<" ";
        }
        if(n%2){
           n--;
        }
        for(int j=n;j>=1;j-=2){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}