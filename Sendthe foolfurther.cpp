#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int,int>>> adj;
int ans = 0;

void dfs(int u, int parent, int dist) {
    bool isLeaf = true;
    for (auto [v, cost] : adj[u]) {
        if (v == parent) continue;
        isLeaf = false;
        dfs(v, u, dist + cost);
    }
    if (isLeaf) ans = max(ans, dist); // end at leaf
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    adj.assign(n, {});
    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dfs(0, -1, 0);

    cout << ans << "\n";
    return 0;
}
