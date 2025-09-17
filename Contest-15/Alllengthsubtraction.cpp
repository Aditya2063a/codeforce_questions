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
        vector<int> p(n);
        int index = -1;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (p[i] == n) index = i; 
        }

        int l = index, r = index;
        bool ok = true;

        for (int k = n - 1; k >= 1; k--) {
            if (l > 0 && p[l - 1] == k) {
                l--;
            } else if (r + 1 < n && p[r + 1] == k) {
                r++;
            } else {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
