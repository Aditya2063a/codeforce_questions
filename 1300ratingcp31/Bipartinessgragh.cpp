#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mod 1000000007
#define INF 1000000000

void dfs(vector<vector<ll>>& ad, vector<ll>& color, ll index, ll col){
    color[index]=col;
    for(auto& nbr:ad[index]){
        if(color[nbr]==0){
            if(col==1){
                dfs(ad, color, nbr, 2);
            }else{
                dfs(ad, color, nbr, 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin>>n;
    vector<vector<ll>> ad(n+1); vector<ll> in(n+1, 0);
    for(ll i=0; i<n-1; i++){
        ll a,b; cin>>a>>b;
        ad[a].pb(b);
        ad[b].pb(a);
        in[a]++;in[b]++;
    }

    vector<ll> coloring(n+1, 0); // 1-red and 2-blue
    dfs(ad, coloring, 1, 1);
    ll red=0,blue=0;
    for(ll i=1;i<n+1; i++){
        if(coloring[i]==1){
            red++;
        }else{
            blue++;
        }
    }

    ll ans=0;
    for(ll i=1; i<n+1; i++){
        if(coloring[i]==1){
            ans+=blue-in[i];
        }else{
            ans+=red-in[i];
        }
    }

    cout<< ans/2 << "\n";

}