#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll getR(ll a) {
    while (a % 2 == 0) a /= 2;
    return a;
}

void solve() {
    ll a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);

    ll r = getR(a);
    if (getR(b) != r) {
        cout << -1 << "\n";
        return;
    }

    ll ratio = b / a;
    int ans = 0;

    while (ratio >= 8 && ratio % 8 == 0) {
        ratio /= 8;
        ++ans;
    }
    if (ratio > 1) ++ans;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
