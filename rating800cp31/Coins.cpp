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
        long long n, k;
        cin >> n >> k;

        bool ok = false;

        if (k % 2 == 0) {
            if (n % 2 == 0) ok = true;
        } else {
            for (long long y = 0; y <= n / k && y < 2; ++y) {
                long long rem = n - k * y;
                if (rem >= 0 && rem % 2 == 0) {
                    ok = true;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");


    }
}