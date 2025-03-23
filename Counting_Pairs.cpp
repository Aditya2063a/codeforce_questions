#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;

        vector<ll> a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        sort(a.begin(), a.end());

        ll L = sum - y;
        ll R = sum - x;

        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            ll lo = L - a[i];
            ll hi = R - a[i];

            int left = lower_bound(a.begin() + i + 1, a.end(), lo) - a.begin();
            int right = upper_bound(a.begin() + i + 1, a.end(), hi) - a.begin();

            cnt += (right - left);
        }

        cout << cnt << "\n";
    }
    return 0;
}
