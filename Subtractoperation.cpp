#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        unordered_set<long long> s;
        s.reserve(n * 2);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s.insert(a[i]);
        }

        bool ok = false;
        for (int i = 0; i < n; ++i) {
            // we need some a[j] such that a[j] - a[i] = k
            if (s.count(a[i] + k)) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
