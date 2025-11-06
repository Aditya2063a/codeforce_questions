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
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        long long ans = -1;
        for (int j = 1; j <= 60; ++j) {
            long long k = 1LL << j; 
            set<long long> s;
            for (auto x : a)
                s.insert(x % k);
            if (s.size() == 2) {
                ans = k;
                break;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
