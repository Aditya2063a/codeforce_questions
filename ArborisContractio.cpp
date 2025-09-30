#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; if(!(cin>>t)) return 0;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> g(n+1);
        vector<int> deg(n+1,0);
        for(int i=0;i<n-1;i++){
            int u,v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        int L = 0;
        for(int i=1;i<=n;i++) if(deg[i]==1) L++;
        int best = 0;
        for(int v=1; v<=n; ++v){
            int leaf_neighbors = 0;
            for(int u: g[v]) if(deg[u]==1) leaf_neighbors++;
            int self_leaf = (deg[v]==1) ? 1 : 0;
            best = max(best, leaf_neighbors + self_leaf);
        }
        cout << (L - best) << '\n';
    }
    return 0;
}
