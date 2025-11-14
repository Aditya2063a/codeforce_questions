#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];

        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (i == 1 || i == n || (p[i - 1] < p[i]) != (p[i] < p[i + 1]))
                ans.push_back(p[i]);
        }

        cout << ans.size() << "\n";
        for (int x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
