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
        long long x, total_xor = 0;

        for (int i = 0; i < n; ++i) {
            cin >> x;
            total_xor ^= x;
        }

        if (n % 2 == 1) {
            cout << total_xor << "\n";
        } else {
            if (total_xor == 0) {
                cout << 3 << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
}