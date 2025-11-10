#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mod 1000000007
#define INF 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int m = 2 * n;

        vector<int> top(n + 1), bottom(n + 1);
        for (int i = 1; i <= n; i++) cin >> top[i];
        for (int i = 1; i <= n; i++) cin >> bottom[i];

        vector<vector<pair<int,int>>> pos(m + 1);
        for (int i = 1; i <= n; i++) {
            pos[top[i]].pb({1, i});
            pos[bottom[i]].pb({2, i});
        }
        set<int> badTop, badBottom;
        for (int i = 1; i <= n; i++) {
            badTop.insert(i);
            badBottom.insert(i);
        }

        ll ans = 0;
        int r = 0;

        for (int l = 1; l <= m; l++) {
            r = max(r, l - 1);

            while (r < m) {
                int aa = badTop.empty() ? n + 1 : *badTop.begin();
                int bb = badBottom.empty() ? 0 : *badBottom.rbegin();

                if (bb < aa - 1) break; 
                r++;
                for (auto [row, col] : pos[r]) {
                    if (row == 1) badTop.erase(col);
                    else badBottom.erase(col);
                }
            }

            int aa = badTop.empty() ? n + 1 : *badTop.begin();
            int bb = badBottom.empty() ? 0 : *badBottom.rbegin();

            if (bb < aa - 1)
                ans += (m - r + 1); 

            if (l <= r) {
                for (auto [row, col] : pos[l]) {
                    if (row == 1) badTop.insert(col);
                    else badBottom.insert(col);
                }
            }
        }

        cout << ans << '\n';
    }
}
