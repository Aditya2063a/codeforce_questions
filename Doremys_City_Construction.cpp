#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        // Build group sizes for each distinct altitude
        vector<ll> cnt;
        cnt.reserve(n);
        ll run = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                run++;
            } else {
                cnt.push_back(run);
                run = 1;
            }
        }
        cnt.push_back(run);

        int k = cnt.size();

        // 1) Compute best_cross = max over split i of (sum of first i groups) * (n - that sum)
        ll best_cross = 0;
        ll prefix = 0;
        for (int i = 0; i < k - 1; i++) {
            prefix += cnt[i];
            ll suffix = n - prefix;
            best_cross = max(best_cross, prefix * suffix);
        }

        // 2) Compute best_match = sum of floor(cnt[i] / 2) over all groups
        ll best_match = 0;
        for (int i = 0; i < k; i++) {
            best_match += cnt[i] / 2;
        }

        cout << max(best_cross, best_match) << "\n";
    }

    return 0;
}
