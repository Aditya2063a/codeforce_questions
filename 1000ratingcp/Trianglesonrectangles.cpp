#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll w, h;
        cin >> w >> h;

        ll ans = 0;
        for (int i = 0; i < 4; i++) {
            int k;
            cin >> k;
            vector<ll> a(k);
            for (int j = 0; j < k; j++) cin >> a[j];
            ans = max(ans, (a.back() - a.front()) * (i < 2 ? h : w));
        }
        cout << ans << "\n";
    }

    return 0;
}
