#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool found = false;
        for (int j = 1; j < n-1; j++) { // check for peak at position j
            if (a[j] > a[j-1] && a[j] > a[j+1]) {
                cout << "YES\n";
                cout << j << " " << j+1 << " " << j+2 << "\n"; // 1-based indices
                found = true;
                break;
            }
        }
        if (!found) cout << "NO\n";
    }

    return 0;
}
