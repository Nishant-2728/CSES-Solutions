#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin>>S;
    int n=S.size();
    sort(S.begin(),S.end());
    vector<string>ans;
    do{
        ans.push_back(S);
    }while(next_permutation(S.begin(),S.end()));
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<endl;
    }
}