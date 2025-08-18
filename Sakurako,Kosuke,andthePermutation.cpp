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
    cin.tie(nullptr);
    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n+1);
        for (int i = 1; i <= n; ++i) cin >> p[i];

        vector<char> vis(n+1, 0);
        long long ans = 0;

        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                int cur = i, L = 0;
                while (!vis[cur]) {
                    vis[cur] = 1;
                    cur = p[cur];
                    ++L;
                }
                ans += (L - 1) / 2; 
            }
        }
        cout << ans << '\n';
    }
    return 0;
}