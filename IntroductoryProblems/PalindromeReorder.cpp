#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin>>S;
    int n=S.size(),total=0;
    vector<int>cnt(26,0);
    for(int j=0;j<n;j++){
        cnt[S[j]-'A']++;
    }
    for(int j=0;j<26;j++){
        if(cnt[j]%2==1){
            total++;
        }
    }
    if(total>1){
        cout<<"NO SOLUTION"<<endl;
    }
    else{
        vector<char>ans(n);
        int start=0;
        for(int j=0;j<26;j++){
            if(cnt[j]%2){
                ans[n/2]=(char)(j+65);
            }
            for(int k=1;k<=cnt[j]/2;k++){
                ans[start]=(char)(j+65);
                ans[n-1-start]=(char)(j+65);
                start++;
            }
        }
        for(auto it:ans)
            cout<<it;
    }
}