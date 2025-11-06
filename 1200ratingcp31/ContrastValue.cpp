#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<long long> b;
        b.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i - 1]) b.push_back(a[i]);
        }

        n = (int)b.size();
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }

        int ans = 1; // start with first element
        int dir = 0; // 0 = none, 1 = inc, -1 = dec

        for (int i = 1; i < n; ++i) {
            if (b[i] > b[i - 1]) {
                if (dir == -1) ans++;
                dir = 1;
            } else if (b[i] < b[i - 1]) {
                if (dir == 1) ans++;
                dir = -1;
            }
        }

        ans++; 
        cout << ans << "\n";
    }

    return 0;
}
