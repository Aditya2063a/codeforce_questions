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

ll solve(int i, int n, vector<ll>& a, vector<ll>& c, vector<ll>& dp) {
    if (dp[i] != -1) return dp[i];

    ll ans = 0;
    for (int j = i + 1; j < n; ++j) {
        if (a[j] >= a[i]) {
            ans = max(ans, solve(j, n, a, c, dp));
        }
    }
    dp[i] = c[i] + ans;
    return dp[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> a(n), c(n);
        
        ll total = 0;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) { 
            cin >> c[i]; total += c[i]; 
        }

        vector<ll> dp(n, -1);
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, solve(i, n, a, c, dp));
        }
        cout << (total - ans) << '\n';
    }
    return 0;
}
