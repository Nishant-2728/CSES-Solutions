#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	string S;
	cin>>S;
	ll n=S.size();
	vector<ll>freq(26,0);
	ll maxfreq=0;
	for(ll j=0;j<n;j++){
	    freq[S[j]-'A']++;
	    maxfreq=max(maxfreq,freq[S[j]-'A']);
	}
	vector<char>res(n);
	if(maxfreq>n/2+n%2){
	   cout<<-1<<"\n";
	}
	else{
	   ll prev=-1;
	   for(ll j=0;j<n;j++){
	       maxfreq=0;
	       int c,curr;
	       for(ll k=0;k<26;k++){
	           if(freq[k]>maxfreq){
	               maxfreq=freq[k];
	               c=k;
	           }
	       }
	       for(ll k=0;k<26;k++){
	           if(freq[k]>0 && k!=prev){
	               curr=k;
	               break;
	           }
	       }
	       ll cnt=(n-1-j)/2+(n-1-j)%2;
	       if(cnt<maxfreq){
	           res[j]=(char)(c+'A');
	           freq[c]--;
	           prev=c;
	       }
	       else{
	           res[j]=(char)(curr+'A');
	           freq[curr]--;
	           prev=curr;
	       }
	   }
	   for(ll j=0;j<n;j++){
	       cout<<res[j];
	   }
	   cout<<"\n";
	}
}
