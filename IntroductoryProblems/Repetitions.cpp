#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin>>S;
    int n=S.size(),maxi=0;
    for(int j=0;j<n;){
        int count=0;
        char c=S[j];
        while(j<n && S[j]==c){
            count++;
            j++;
        }
        maxi=max(maxi,count);
    }
    cout<<maxi<<endl;
}