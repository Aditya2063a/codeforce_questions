#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

vector<vector<int>> red_adj; // adjacency list using only red edges
vector<bool> visited;

// Fast modular exponentiation: computes (base^exp) % MOD
ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp) {
        if (exp % 2) result = result * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

// DFS to compute size of red-connected component
int dfs(int node) {
    visited[node] = true;
    int size = 1;
    for (int neighbor : red_adj[node]) {
        if (!visited[neighbor]) {
            size += dfs(neighbor);
        }
    }
    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    red_adj.resize(n + 1);
    visited.assign(n + 1, false);

    // Read edges and only connect red edges
    for (int i = 0; i < n - 1; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        if (x == 0) {
            red_adj[u].push_back(v);
            red_adj[v].push_back(u);
        }
    }

    ll total = mod_pow(n, k, MOD);
    ll bad = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int comp_size = dfs(i);
            bad = (bad + mod_pow(comp_size, k, MOD)) % MOD;
        }
    }

    ll good = (total - bad + MOD) % MOD;
    cout << good << "\n";

    return 0;
}
