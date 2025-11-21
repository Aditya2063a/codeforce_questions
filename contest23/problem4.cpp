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
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        int xa = 0, xb = 0;
        for (int i = 0; i < n; ++i) { xa ^= a[i]; xb ^= b[i]; }

        if (xa == xb) {
            cout << "Tie\n";
            continue;
        }

        int last = -1;
        for (int i = 0; i < n; ++i) if (a[i] != b[i]) last = i + 1;

        if(last==-1){
            cout<<"Tie\n";
        }

        if (last % 2 == 1) cout << "Ajisai\n";
        else cout << "Mai\n";

    }
}