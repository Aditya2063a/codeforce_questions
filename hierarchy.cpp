#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> q(n+1);
    for(int i=1; i<=n; i++) cin >> q[i];

    int m; cin >> m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++) {
        int a,b,c; cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }

    // Step 1: find root (unique max qualification)
    int root = 1;
    for(int i=2; i<=n; i++) {
        if(q[i] > q[root]) root = i;
    }
    int maxQ = q[root];
    int cntMax = 0;
    for(int i=1; i<=n; i++) if(q[i] == maxQ) cntMax++;
    if(cntMax > 1) {
        cout << -1 << "\n";
        return 0;
    }

    // Step 2: find minimum incoming edge for each node (except root)
    vector<int> minCost(n+1, INT_MAX);
    for(auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        // only consider incoming edges
        if(v != root) {
            minCost[v] = min(minCost[v], w);
        }
    }

    // Step 3: check if all nodes (except root) have an incoming edge
    long long ans = 0;
    for(int i=1; i<=n; i++) {
        if(i == root) continue;
        if(minCost[i] == INT_MAX) {
            cout << -1 << "\n";
            return 0;
        }
        ans += minCost[i];
    }

    cout << ans << "\n";
    return 0;
}
