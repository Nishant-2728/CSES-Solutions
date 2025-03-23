#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,T;
    cin>>T;
    for(i=1;i<=T;i++){
        long long int x,y;
        cin>>x>>y;
        if(y<=x){
            if(x%2==0)
                cout<<x*x-y+1<<endl;
            else
                cout<<(x-1)*(x-1)+y<<endl;
        }
        else{
            if(y%2==0){
                cout<<(y-1)*(y-1)+x<<endl;
            }
            else{
                cout<<y*y-(x-1)<<endl;
            }
        }
    }
}
