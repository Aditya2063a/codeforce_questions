#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int l, r; // Allowed range for the node
};

vector<vector<int>> tree;
vector<Node> nodes;
vector<int> dp_inc; // Stores the required increments in the subtree

void dfs(int u, int parent, int &total_cost) {
    int l = nodes[u].l, r = nodes[u].r;
    
    int min_val = 0, max_val = 0; // Track min/max values in the subtree

    for (int v : tree[u]) {
        if (v == parent) continue;
        
        dfs(v, u, total_cost);
        
        min_val += dp_inc[v]; // Sum of minimum increments needed from children
        max_val += nodes[v].r; // Maximum we can get from children
    }

    // If there are children, constrain the min/max values
    if (!tree[u].empty()) {
        l = max(l, min_val);
        r = min(r, max_val);
    }

    // If l is within the range, assign it
    if (l <= r) {
        dp_inc[u] = l;
    } else {
        // If l exceeds r, we must increment all values
        dp_inc[u] = r;
        total_cost += (l - r);
    }
}

void solve() {
    int n;
    cin >> n;
    
    tree.assign(n + 1, vector<int>());
    nodes.assign(n + 1, {0, 0});
    dp_inc.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].l >> nodes[i].r;
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int total_cost = 0;
    dfs(1, -1, total_cost);
    cout << total_cost << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
