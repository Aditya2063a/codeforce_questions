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
        vector<long long> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        
        sort(b.begin(), b.end());
        bool ok = false;
        for (int i = 1; i < n; i++) {
            if (b[i] == b[i - 1]) {
                ok = true;
                break;
            }
        }
        
        cout << (ok ? "YES\n" : "NO\n");
    }
}
