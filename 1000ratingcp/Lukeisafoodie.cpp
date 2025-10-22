#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int &num : a) cin >> num;

        int res = 0;
        int mn = a[0], mx = a[0];

        for (int i = 1; i < n; i++) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
            if (mx - mn > 2 * x) {
                res++;
                mn = mx = a[i];
            }
        }

        cout << res << '\n';
    }
}
