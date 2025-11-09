#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = i + 1; j < n && a[j] < 2 * a[i]; j++) {
                if ((a[j] % a[i]) % 2 == 0) {
                    cout << a[i] << " " << a[j] << "\n";
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            for (int i = 0; i < n && !found; i++) {
                for (int j = i + 1; j < n; j++) {
                    if ((a[j] % a[i]) % 2 == 0) {
                        cout << a[i] << " " << a[j] << "\n";
                        found = true;
                        break;
                    }
                }
            }
        }

        if (!found) cout << -1 << "\n";
    }
}
