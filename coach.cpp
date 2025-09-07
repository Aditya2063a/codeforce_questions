#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<int> &visited, vector<int> &comp) {
    visited[u] = 1;
    comp.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v, adj, visited, comp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> visited(n+1, 0);
    vector<vector<int>> comps;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> comp;
            dfs(i, adj, visited, comp);
            if (comp.size() > 3) {
                cout << -1 << "\n";
                return 0;
            }
            comps.push_back(comp);
        }
    }

    vector<vector<int>> ans;
    vector<int> ones; // singletons
    vector<vector<int>> twos; // pairs

    for (auto &c : comps) {
        if (c.size() == 3) ans.push_back(c);
        else if (c.size() == 2) twos.push_back(c);
        else ones.push_back(c[0]);
    }

    // Match pairs with singletons
    for (auto &p : twos) {
        if (ones.empty()) {
            cout << -1 << "\n";
            return 0;
        }
        p.push_back(ones.back());
        ones.pop_back();
        ans.push_back(p);
    }

    // Group remaining ones into triples
    if (ones.size() % 3 != 0) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < ones.size(); i += 3) {
        ans.push_back({ones[i], ones[i+1], ones[i+2]});
    }

    // Print teams
    for (auto &team : ans) {
        cout << team[0] << " " << team[1] << " " << team[2] << "\n";
    }
}
