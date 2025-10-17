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
 
int msb_index(long long x) {
    int idx = -1;
    while (x > 0) { ++idx; x >>= 1; }
    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;cin>>tt;
    while (tt--) {
        ll a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 0 << '\n';
            continue;
        }
        int ma = msb_index(a);
        int mb = msb_index(b);
        if (mb > ma) { 
            cout << -1 << '\n';
            continue;
        }
        ll d = a ^ b;
        if (d <= a) {
            cout << 1 << '\n' << d << '\n';
            continue;
        }
        ll c = ((1LL << (ma + 1)) - 1);
        ll x1 = a ^ c; 
        ll  x2 = c ^ b; 
        cout << 2 << '\n' << x1 << ' ' << x2 << '\n';
    }
    return 0;
}