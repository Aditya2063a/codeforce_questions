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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> a(n+1), pref(n+1, 0);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i-1] + a[i];
        }

        ll kk = pref[n];
        ll gg = 0,minC = 10e18;

        for (int r = 1; r <= n; r++) {
            ll Cr = 1LL*r*r - r - pref[r-1];
            minC = min(minC, Cr);

            ll Ar = 1LL*r*r + r - pref[r];
            ll gggg = Ar - minC;

            gg = max(gg, gggg);
        }

        cout << kk + gg << "\n";

    }
}