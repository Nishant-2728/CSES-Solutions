#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void dfs(string node,set<string>&st,string &res){
    for(ll j=0;j<2;j++){
        string new_node=node+(char)(j+'0');
        if(st.find(new_node)==st.end()){
            st.insert(new_node);
            dfs(new_node.substr(1),st,res);
            res+=(char)(j+'0');
        }
    }
}
int main() {
	ll n;
	cin>>n;
	string start(n-1,'0');
	set<string>st;
	string res="";
	dfs(start,st,res);
	res+=start;
	cout<<res<<"\n";
}
