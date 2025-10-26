#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        vector<int> x(q);
        for (auto &v : a) cin >> v;
        for (auto &v : x) cin >> v;

        vector<bool> done(31, false);

        for (int i = 0; i < q; i++) {
            int k = x[i];
            if (done[k]) continue;
            done[k] = true;

            ll p = 1LL << k;       // 2^k
            ll add = 1LL << (k - 1); // 2^(k-1)
            for (int j = 0; j < n; j++) {
                if (a[j] % p == 0)
                    a[j] += add;
            }
        }

        for (auto v : a) cout << v << " ";
        cout << "\n";
    }
}
