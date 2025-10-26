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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        
        sort(a.begin(), a.end());
        
        vector<long long> pr(n + 1, 0);
        for (int i = 0; i < n; ++i)
            pr[i + 1] = pr[i] + a[i];
        
        long long ans = 0;
        for (int i = 0; i <= k; ++i) {
            long long cur = pr[n - (k - i)] - pr[2 * i];
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
    
    return 0;
}
