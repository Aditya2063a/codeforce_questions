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
        string a, b;
        cin >> a >> b;

        vector<int> prefix_balance(n);
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '0') cnt0++;
            else cnt1++;
            if (cnt0 == cnt1) prefix_balance[i] = 1; 
        }

        bool flipped = false, ok = true;
        for (int i = n - 1; i >= 0; i--) {
            char ai = a[i];
            if (flipped) ai = (ai == '0' ? '1' : '0'); 

            if (ai != b[i]) {
                if (prefix_balance[i]) {
                    flipped = !flipped; 
                } else {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}
