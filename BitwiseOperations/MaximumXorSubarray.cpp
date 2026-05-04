#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct Node{
    Node* links[2];
    bool containsKey(ll bit){
        return (links[bit]!=NULL);
    }
    void put(ll bit,Node* node){
        links[bit]=node;
    }
    Node* get(ll bit){
        return links[bit];
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(ll x){
        Node* node=root;
        for(ll j=30;j>=0;j--){
            ll bit=(x>>j)&1LL;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    ll Maximumxor(ll x){
        Node* node=root;
        ll res=0;
        for(ll j=30;j>=0;j--){
            ll bit=(x>>j)&1LL;
            if(node->containsKey(1-bit)){
                res+=(1LL<<j);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return res;
    }
};
int main(){
   ll n;
   cin>>n;
   vector<ll>a(n);
   for(ll j=0;j<n;j++){
       cin>>a[j];
   }
   Trie trie;
   trie.insert(0);
   ll prefixxor=0,ans=0;
   for(ll j=0;j<n;j++){
       prefixxor^=a[j];
       ans=max(ans,trie.Maximumxor(prefixxor));
       trie.insert(prefixxor);
   }
   cout<<ans<<"\n";
}
