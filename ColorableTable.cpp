#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        // store presence of each color
        vector<bool> exists(k+1, false);
        for (int i = 1; i <= n; i++) exists[a[i]] = true;

        // prefix: longest prefix with all numbers < x
        vector<int> pref(k+2, 0);
        int pos = 1;
        for (int x = 1; x <= k; x++) {
            while (pos <= n && a[pos] < x) pos++;
            pref[x] = pos - 1; // length of prefix
        }

        // suffix: longest suffix with all numbers < x
        vector<int> suff(k+2, 0);
        pos = n;
        for (int x = 1; x <= k; x++) {
            while (pos >= 1 && a[pos] < x) pos--;
            suff[x] = n - pos; // length of suffix
        }

        // answers
        for (int x = 1; x <= k; x++) {
            if (!exists[x]) {
                cout << 0 << " ";
            } else {
                cout << 2 * (n - pref[x] - suff[x]) << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
