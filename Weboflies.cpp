#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> cnt_higher(n + 1, 0);
    int good = n; // initially assume all have cnt_higher == 0

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        if (u < v) {
            if (cnt_higher[u] == 0) --good;
            ++cnt_higher[u];
        } else {
            if (cnt_higher[v] == 0) --good;
            ++cnt_higher[v];
        }
    }

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int u, v; cin >> u >> v;
            if (u < v) {
                if (cnt_higher[u] == 0) --good;
                ++cnt_higher[u];
            } else {
                if (cnt_higher[v] == 0) --good;
                ++cnt_higher[v];
            }
        } else if (type == 2) {
            int u, v; cin >> u >> v;
            if (u < v) {
                --cnt_higher[u];
                if (cnt_higher[u] == 0) ++good;
            } else {
                --cnt_higher[v];
                if (cnt_higher[v] == 0) ++good;
            }
        } else if (type == 3) {
            cout << good << '\n';
        }
    }

    return 0;
}
