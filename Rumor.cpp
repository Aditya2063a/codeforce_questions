#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(vector<vector<int>>& vec, vector<ll>& p, vector<bool>& vis, int node, ll& mn) {
    vis[node] = true;
    mn = min(mn, p[node]);
    for (int neighbor : vec[node]) {
        if (!vis[neighbor]) {
            dfs(vec, p, vis, neighbor, mn);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> p(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<vector<int>> vec(n+1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    vector<bool> vis(n+1, false);
    ll result = 0;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ll mn = LLONG_MAX;
            dfs(vec, p, vis, i, mn);
            result += mn;
        }
    }

    cout << result << "\n";
    return 0;
}
