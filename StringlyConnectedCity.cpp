#include <bits/stdc++.h>
using namespace std;

int n, m;
string hor, ver;

int id(int i, int j) {
    return i * m + j; // flatten 2D index
}

int main() {
    cin >> n >> m;
    cin >> hor >> ver;

    int total = n * m;
    vector<vector<int>> g(total), rg(total);

    // Build graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = id(i, j);

            // horizontal move
            if (hor[i] == '>') {
                if (j + 1 < m) {
                    int v = id(i, j + 1);
                    g[u].push_back(v);
                    rg[v].push_back(u);
                }
            } else { // '<'
                if (j - 1 >= 0) {
                    int v = id(i, j - 1);
                    g[u].push_back(v);
                    rg[v].push_back(u);
                }
            }

            // vertical move
            if (ver[j] == 'v') {
                if (i + 1 < n) {
                    int v = id(i + 1, j);
                    g[u].push_back(v);
                    rg[v].push_back(u);
                }
            } else { // '^'
                if (i - 1 >= 0) {
                    int v = id(i - 1, j);
                    g[u].push_back(v);
                    rg[v].push_back(u);
                }
            }
        }
    }

    // BFS/DFS helper
    auto reachable = [&](vector<vector<int>>& graph) {
        vector<int> vis(total, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return accumulate(vis.begin(), vis.end(), 0) == total;
    };

    if (reachable(g) && reachable(rg)) cout << "YES\n";
    else cout << "NO\n";
}
