#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 998244353;


int n, m;
vector<vector<int>> adj;
vector<long long> a;
vector<char> vis;

ll dfs(int x, int y){
    ll cnt = 1; 
    ll need = a[x] + a[y];
    for(int w : adj[y]){
        if(!vis[w] && a[w] == need){
            vis[w] = 1;
            cnt += dfs(y, w);
            if(cnt >= MOD) {
                cnt -= MOD * (cnt / MOD); 
            }
            vis[w] = 0;
        }
    }
    return cnt % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt; 
    while(tt--){
        cin >> n >> m;
        a.assign(n+1, 0);
        for(int i=1;i<=n;i++) cin >> a[i];

        adj.assign(n+1, {});
        for(int i=0;i<m;i++){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
        }
        
        vis.assign(n+1, 0);
        ll ans = 0;
        for(int u=1; u<=n; ++u){
            for(int v : adj[u]){
                vis[u] = 1; vis[v] = 1;
                ll add = dfs(u, v); 
                ans += add;
                if(ans >= MOD) ans -= MOD * (ans / MOD);
                vis[u] = 0; vis[v] = 0;
            }
        }
        cout << (ans % MOD) << '\n';
    }
    return 0;
}
