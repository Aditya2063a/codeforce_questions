// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// ll dp[100005][2][2][2];
// vector<ll> a, b, c;
// int n;

// ll solve(int i, int ski, int mov, int brd) {
//     if (ski && mov && brd) return 0;
//     if (i >= n) return LLONG_MIN / 2;

//     ll &res = dp[i][ski][mov][brd];
//     if (res != -1) return res;

//     res = solve(i + 1, ski, mov, brd);  // skip
//     if (!ski) res = max(res, a[i] + solve(i + 1, 1, mov, brd));
//     if (!mov) res = max(res, b[i] + solve(i + 1, ski, 1, brd));
//     if (!brd) res = max(res, c[i] + solve(i + 1, ski, mov, 1));

//     return res;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t; cin >> t;
//     while (t--) {
//         cin >> n;
//         a.resize(n); b.resize(n); c.resize(n);
//         for (int i = 0; i < n; i++) cin >> a[i];
//         for (int i = 0; i < n; i++) cin >> b[i];
//         for (int i = 0; i < n; i++) cin >> c[i];

//         memset(dp, -1, sizeof(dp));
//         cout << solve(0, 0, 0, 0) << "\n";
//     }
// }


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<ll, int>> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) { cin >> a[i].first; a[i].second = i; }
        for (int i = 0; i < n; i++) { cin >> b[i].first; b[i].second = i; }
        for (int i = 0; i < n; i++) { cin >> c[i].first; c[i].second = i; }

        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        sort(c.rbegin(), c.rend());

        ll ans = 0;
        for (int i = 0; i < min(3, n); i++) {
            for (int j = 0; j < min(3, n); j++) {
                for (int k = 0; k < min(3, n); k++) {
                    int ia = a[i].second, ib = b[j].second, ic = c[k].second;
                    if (ia != ib && ib != ic && ia != ic) {
                        ans = max(ans, a[i].first + b[j].first + c[k].first);
                    }
                }
            }
        }

        cout << ans << "\n";
    }
}
