#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int ans;

pair<int,int> dfs(int node, vector<vector<int>>& adj, const string& s) {
    int w = (s[node - 1] == 'W');
    int b = (s[node - 1] == 'B');

    for (int child : adj[node]) {
        auto [cw, cb] = dfs(child, adj, s);
        w += cw;
        b += cb;
    }

    if (w == b) ans++;
    return {w, b};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);

        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            adj[p].push_back(i);
        }

        string s;
        cin >> s;

        ans = 0;
        dfs(1, adj, s);

        cout << ans << "\n";
    }
}
