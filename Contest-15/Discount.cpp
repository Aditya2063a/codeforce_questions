#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        vector<int> b(k);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < k; ++i) cin >> b[i];

        sort(a.begin(), a.end(), greater<ll>()); 
        sort(b.begin(), b.end());                 

        ll ans = 0;
        int idx = 0; 
        for (int x : b) {
            if (idx >= n) break;
            if (x == 1) {
                idx += 1;
            } else {
                for (int t = 0; t < x - 1 && idx < n; ++t) {
                    ans += a[idx++];
                }
                if (idx < n) idx += 1;
            }
        }

        while (idx < n) ans += a[idx++];

        cout << ans << '\n';
    }
    return 0;
}
