#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;

        vector<int> first(26, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) {
                first[c] = i;
                ans += (n - i);
            }
        }

        cout << ans << "\n";
    }
}
