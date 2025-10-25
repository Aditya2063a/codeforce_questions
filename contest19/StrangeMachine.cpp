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
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        vector<int> lenA(n, 0), nextIdx(n, 0);
        bool hasB = false;
        for (int i = 0; i < n; ++i) if (s[i] == 'B') { hasB = true; break; }

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A') {
                int cnt = 0, j = i;
                while (cnt < n && s[j] == 'A') {
                    ++cnt;
                    j = (j + 1) % n;
                }
                lenA[i] = cnt;
                nextIdx[i] = j; 
            } else {
                lenA[i] = 0;
                nextIdx[i] = (i + 1) % n;
            }
        }

        while (q--) {
            ll a; cin >> a;
            if (!hasB) {
                cout << a << '\n';
                continue;
            }

            ll steps = 0;
            int idx = 0;
            while (a > 0) {
                if (s[idx] == 'B') {
                    a /= 2;
                    ++steps;
                    idx = (idx + 1) % n;
                } else {
                    int L = lenA[idx];
                    if (L == 0) {
                        idx = (idx + 1) % n;
                        continue;
                    }
                    if (a <= L) {
                        steps += a;
                        a = 0;
                        break;
                    } else {
                        a -= L;
                        steps += L;
                        idx = nextIdx[idx]; 
                    }
                }
            }
            cout << steps << '\n';
        }
    }
    return 0;
}
