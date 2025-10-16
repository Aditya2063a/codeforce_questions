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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (all_of(a.begin(), a.end(), [](int x){ return x == 0; })) {
            cout << 0 << "\n";
            continue;
        }

        int L = -1, R = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                if (L == -1) L = i;
                R = i;
            }
        }

        bool c = true;
        for (int i = L; i <= R; i++) {
            if (a[i] == 0) {
                c = false;
                break;
            }
        }

        cout << (c ? 1 : 2) << "\n";
    }

    return 0;
}
