#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<ll> s(n+1);
        for (int i = 1; i <= n; ++i) cin >> s[i];

        vector<int> p(n+1, 0);
        bool bad = false;

        int l = 1;
        while (l <= n) {
            int r = l;
            while (r + 1 <= n && s[r+1] == s[l]) ++r;
            int len = r - l + 1;
            if (len == 1) { bad = true; break; }

            for (int i = l; i < r; ++i) p[i] = i + 1;
            p[r] = l;

            l = r + 1;
        }

        if (bad) {
            cout << -1 << '\n';
        } else {
            for (int i = 1; i <= n; ++i) {
                cout << p[i] << (i==n?'\n':' ');
            }
        }
    }
    return 0;
}
