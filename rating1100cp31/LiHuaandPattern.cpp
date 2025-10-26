#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> v[i][j];

        int diff = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] != v[n - 1 - i][n - 1 - j])
                    diff++;
            }
        }

        diff /= 2; // each mismatch counted twice

        if (diff > k) {
            cout << "NO\n";
        } else {
            int rem = k - diff;
            if (rem % 2 == 0 || n % 2 == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
