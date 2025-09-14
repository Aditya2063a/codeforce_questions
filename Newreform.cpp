#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<char> vis(n+1, 0);
    int answer = 0;

    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        // BFS/DFS to explore this component
        int verts = 0;
        long long edge_entries = 0; // sum of degrees in component (will divide by 2)
        stack<int> st;
        st.push(i);
        vis[i] = 1;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            verts++;
            edge_entries += (int)g[u].size();
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    st.push(v);
                }
            }
        }
        long long edges = edge_entries / 2; // undirected edges in component
        if (edges == verts - 1) {
            // tree -> forces 1 separate city
            answer++;
        }
        // else has cycle -> contributes 0
    }

    cout << answer << "\n";
    return 0;
}
