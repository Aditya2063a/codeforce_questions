#include <bits/stdc++.h>
using namespace std;

pair<vector<int>, vector<int>> bfs_from(int start, const vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> depth(n, -1), parent(n, -1);
    queue<int> q;
    q.push(start);
    depth[start] = 0;
    parent[start] = start;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return {depth, parent};
}

int solve_case(int n, vector<pair<int,int>> &edges) {
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
        int u = e.first - 1, v = e.second - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // find one end of diameter
    auto dp0 = bfs_from(0, adj);
    int a = max_element(dp0.first.begin(), dp0.first.end()) - dp0.first.begin();

    // find other end and diameter path
    auto dpa = bfs_from(a, adj);
    int b = max_element(dpa.first.begin(), dpa.first.end()) - dpa.first.begin();

    // reconstruct diameter path a..b using parent from bfs(a)
    vector<int> path;
    for (int x = b; x != dpa.second[x]; x = dpa.second[x]) path.push_back(x);
    path.push_back(a);
    reverse(path.begin(), path.end());
    int diameter = (int)path.size() - 1;

    // one or two centers
    vector<int> centers;
    if (diameter % 2 == 0) {
        centers.push_back(path[diameter / 2]);
    } else {
        centers.push_back(path[diameter / 2]);
        centers.push_back(path[diameter / 2 + 1]);
    }

    int answer = INT_MAX;

    for (int c : centers) {
        // BFS rooted at center c; also compute which immediate child of c each node belongs to
        auto dp = bfs_from(c, adj);
        vector<int> &depth = dp.first;
        vector<int> top(n, -1);

        // top-child assignment:
        // for every neighbor nb of c, we set top[nb] = nb and BFS propagate that label
        queue<int> q;
        for (int nb : adj[c]) {
            top[nb] = nb;
            q.push(nb);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (v == c) continue;
                if (top[v] == -1 && depth[v] > depth[u]) { // deeper node in same direction
                    top[v] = top[u];
                    q.push(v);
                }
            }
        }

        // compute max depth per top-child
        unordered_map<int,int> maxDepth;
        for (int v = 0; v < n; ++v) {
            if (v == c) continue;
            int t = top[v];
            if (t == -1) continue; // shouldn't happen
            maxDepth[t] = max(maxDepth[t], depth[v]);
        }

        int ops = 0;
        for (auto &kv : maxDepth) {
            int d = kv.second; // distance from center to deepest node in that branch
            if (d > 1) ops += (d + 1) / 2; // ceil(d/2)
        }
        answer = min(answer, ops);
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> edges;
        edges.reserve(n-1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            edges.emplace_back(u, v);
        }
        cout << solve_case(n, edges) << '\n';
    }
    return 0;
}
