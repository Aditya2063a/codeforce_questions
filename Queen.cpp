#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<int> c(n + 1);
    vector<vector<int>> children(n + 1);
    int root = -1;

    for (int i = 1; i <= n; i++) {
        cin >> parent[i] >> c[i];
        if (parent[i] != -1)
            children[parent[i]].push_back(i);
        else
            root = i;
    }

    vector<int> result;

    for (int i = 1; i <= n; i++) {
        if (parent[i] == -1) continue;
        if (c[i] != 1) continue;

        bool all_children_disrespect = true;
        for (int child : children[i]) {
            if (c[child] == 0) {
                all_children_disrespect = false;
                break;
            }
        }

        if (all_children_disrespect)
            result.push_back(i);
    }

    if (result.empty()) {
        cout << -1 << "\n";
    } else {
        sort(result.begin(), result.end());
        for (int x : result) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
