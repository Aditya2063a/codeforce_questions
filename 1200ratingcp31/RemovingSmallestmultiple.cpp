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
        string s;
        cin >> s;
        s = " " + s; 

        vector<bool> deleted(n + 1, false);
        long long total_cost = 0;

        for (int k = 1; k <= n; ++k) {
            for (int j = k; j <= n; j += k) {
                if (s[j] == '1') break; 
                if (deleted[j]) continue;
                deleted[j] = true;
                total_cost += k;
            }
        }

        cout << total_cost << '\n';
    }
}
