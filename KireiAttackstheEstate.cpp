#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];

        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<ll> maxS(n+1, 0), minS(n+1, 0);
        vector<int> parent(n+1, -1);
        queue<int> q;

        // root is 1
        parent[1] = 0;
        maxS[1] = minS[1] = a[1];
        q.push(1);

        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int u: adj[v]){
                if(parent[u] == -1){
                    parent[u] = v;
                    // compute using parent's minS and maxS
                    maxS[u] = max(a[u], a[u] - minS[v]);
                    minS[u] = min(a[u], a[u] - maxS[v]);
                    q.push(u);
                }
            }
        }

        for(int i=1;i<=n;i++){
            cout << maxS[i] << (i==n?'\n':' ');
        }
    }

    return 0;
}
