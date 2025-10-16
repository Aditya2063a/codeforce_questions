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
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a <= q)
                v[i] = 1;
            else
                v[i] = 0;
        }

        ll result = 0, ct = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 1)
                ct++;
            else {
                if (ct >= k)
                    result += 1LL * (ct - k + 1) * (ct - k + 2) / 2;
                ct = 0;
            }
        }

        if (ct >= k)
            result += 1LL * (ct - k + 1) * (ct - k + 2) / 2;

        cout << result << "\n";
    }
}
