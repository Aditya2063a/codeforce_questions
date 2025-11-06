#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mod 1000000007
#define INF 1000000000

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> c(n + 1);
        for (int i = 1; i <= n; i++) cin >> c[i];

        // store positions of each color
        vector<vector<int>> pos(k + 1);
        for (int i = 1; i <= n; i++)
            pos[c[i]].pb(i);

        int ans = INF;

        for (int color = 1; color <= k; color++) {
            if (pos[color].empty()) continue;

            vector<int> gaps;
            int prev = 0;  // before first plank (ground)
            for (int x : pos[color]) {
                gaps.pb(x - prev - 1);
                prev = x;
            }
            gaps.pb(n - prev); // after last plank

            sort(gaps.begin(), gaps.end());

            int g1 = gaps.back();              // largest gap
            gaps.pop_back();
            int g2 = gaps.empty() ? 0 : gaps.back(); // second largest gap

            int curr = max(g2, (g1 + 1) / 2);
            ans = min(ans, curr);
        }

        cout << ans << "\n";
    }
}
