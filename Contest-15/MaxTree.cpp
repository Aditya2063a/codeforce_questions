#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt; 
    while (tt--) {
        int n; 
        cin >> n;
        vector<vector<int>> adj(n+1);
        vector<int> indeg(n+1, 0);

        for (int i = 0; i < n-1; ++i) {
            int u, v; ll x, y;
            cin >> u >> v >> x >> y; 
            if (x >= y) {
                adj[u].push_back(v);
                indeg[v]++;
            } else {
                adj[v].push_back(u);
                indeg[u]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i) if (indeg[i] == 0) q.push(i);

        vector<int> topo;
        topo.reserve(n);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (int w : adj[u]) {
                if (--indeg[w] == 0) q.push(w);
            }
        }

        vector<int> p(n+1, 0);
        for (int i = 0; i < (int)topo.size(); ++i) {
            p[topo[i]] = n - i;
        }

        for (int i = 1; i <= n; ++i) {
            cout << p[i] << (i==n? '\n' : ' ');
        }
    }
    return 0;
}
