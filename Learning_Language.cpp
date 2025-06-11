#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> parent, rankv;
    DSU(int _n): n(_n), parent(n+1), rankv(n+1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> lang_to_emps(m + 1);
    DSU dsu(n);
    bool any_known = false;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        if (k > 0) any_known = true;
        while (k--) {
            int lid;
            cin >> lid;
            lang_to_emps[lid].push_back(i);
        }
    }

    // Union employees sharing a language
    for (int lid = 1; lid <= m; lid++) {
        const auto &emps = lang_to_emps[lid];
        for (size_t i = 1; i < emps.size(); i++) {
            dsu.unite(emps[0], emps[i]);
        }
    }

    // Count distinct components
    unordered_set<int> roots;
    for (int i = 1; i <= n; i++) {
        roots.insert(dsu.find(i));
    }
    int comps = roots.size();

    int result;
    if (!any_known) {
        // If no one knows any language, each employee must learn one
        result = n;
    } else {
        // To connect comps components, need comps - 1 lessons
        result = comps - 1;
    }

    cout << result << "\n";
    return 0;
}
