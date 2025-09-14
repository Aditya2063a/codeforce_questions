#include <bits/stdc++.h>
using namespace std;

inline void Solve() {
    long long n, m, k;
    cin >> n >> m >> k;

    if ((n - 1LL) * n / 2 < m || m < n - 1) {
        cout << "NO\n";
        return;
    }
    if (n == 1) {
        if (k > 1) cout << "YES\n";
        else cout << "NO\n";
    } else if (m < (n - 1LL) * n / 2) {
        if (k > 3) cout << "YES\n";
        else cout << "NO\n";
    } else if (k > 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
