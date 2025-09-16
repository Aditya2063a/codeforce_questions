#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
int subtree_size[N];
int ans = 0;

int dfs(int u, int parent) {
    subtree_size[u] = 1; // count itself

    for (int v : g[u]) {
        if (v == parent) continue;
        subtree_size[u] += dfs(v, u);
    }

    // If this subtree has even size, and it's not the root,
    // we can cut the edge connecting it to the parent
    if (parent != -1 && subtree_size[u] % 2 == 0) {
        ans++;
        return 0; // don't add this to parent's size anymore
    }

    return subtree_size[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // If total vertices is odd → impossible
    if (n % 2 == 1) {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1); // root at 1

    cout << ans << "\n";
    return 0;
}
