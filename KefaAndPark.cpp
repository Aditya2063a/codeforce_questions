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

void dfs(vector<vector<int>>& g, vector<int>& a, int& result, int v, int p, int consec, int m){
    if(a[v] == 1) consec++;
    else consec = 0;

    if(consec > m) return;

    bool isLeaf = true;
    for(int u: g[v]){
        if(u != p){
            isLeaf = false;
            dfs(g, a, result, u, v, consec, m);
        }
    }
    if(isLeaf) result++;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    vector<vector<int>> g(n+1);
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int result=0;
    dfs(g, a, result, 1, -1, 0, m);
    cout<<result<<endl;
}