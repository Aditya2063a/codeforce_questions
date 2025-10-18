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
        for (int i = 0; i < n; ++i) cin >> a[i];

        bool ok = false;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (__gcd(a[i], a[j]) <= 2) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}