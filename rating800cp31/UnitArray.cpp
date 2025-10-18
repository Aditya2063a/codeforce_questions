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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int p = 0, m = 0;
        for (int x : a) cin >> x, (x == 1 ? p++ : m++);

        int ans = 0;
        if (p < m) {
            ans = (m - p + 1) / 2;
            m -= ans;
            p += ans;
        }
        if (m % 2 == 1) ans++;

        cout << ans << "\n";
    }
}