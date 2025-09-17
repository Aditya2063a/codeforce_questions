#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin>>tt;

    while (tt--) {
        int n; cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<vector<int>> cur(n+1, vector<int>(n+1, 0));
        cur[0][0] = 1; 

        for (int pos = 1; pos <= n; ++pos) {
            int v = a[pos];
            vector<vector<int>> nxt(n+1, vector<int>(n+1, 0));
            for (int max_s = 0; max_s <= n; ++max_s) {
                for (int max_all = 0; max_all <= n; ++max_all) {
                    int ways = cur[max_s][max_all];
                    if (!ways) continue;

                    nxt[max_s][max_all] += ways;
                    
                    if (nxt[max_s][max_all] >= MOD) nxt[max_s][max_all] -= MOD;


                    if (max_s > v) continue;

                    int new_max_all = max(max_all, v);
                    int new_max_s = max_s;
                    if (max_all > v) new_max_s = max(new_max_s, v);

                    nxt[new_max_s][new_max_all] += ways;
                    if (nxt[new_max_s][new_max_all] >= MOD) nxt[new_max_s][new_max_all] -= MOD;
                }
            }
            cur.swap(nxt);
        }

        ll ans = 0;
        for (int s = 0; s <= n; ++s) for (int M = 0; M <= n; ++M) {
            ans += cur[s][M];
            if (ans >= MOD) ans -= MOD;
        }
        cout << ans % MOD << "\n";
    }
    return 0;
}
