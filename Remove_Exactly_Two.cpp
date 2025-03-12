#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> deg(n, 0);
        vector<vector<int>> adj(n);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;  // Convert to 0-based index
            deg[u]++, deg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 1, mans = 0;
        vector<int> sdeg = deg;
        sort(sdeg.begin(), sdeg.end());

        for (int i = 0; i < n; i++) {
            ans = deg[i];
            vector<int> ideg;
            for (int v : adj[i]) {
                ideg.push_back(deg[v]);
            }
            ideg.push_back(deg[i]);

            sort(ideg.rbegin(), ideg.rend());

            vector<int> rem;
            int mx = -1;
            for (int d : ideg) {
                if (!sdeg.empty() && sdeg.back() == d) {
                    sdeg.pop_back();
                    rem.push_back(d);
                }
            }
            reverse(rem.begin(), rem.end());

            if (!sdeg.empty()) {
                mx = max(mx, sdeg.back());
            }
            for (int v : adj[i]) {
                mx = max(mx, deg[v] - 1);
            }

            for (int d : rem) {
                sdeg.push_back(d);
            }

            mans = max(ans + mx - 1, mans);
        }
        cout << mans << '\n';
    }

    return 0;
}
