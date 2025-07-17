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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;

        vector<ll> p(n), s(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        vector<ll> a(n);
        bool ok = true;
        for (int i = 0; i < n; i++){
            ll g = gcd(p[i], s[i]);
            a[i] = (p[i] / g) * s[i];
        }

        ll cur = 0;
        for (int i = 0; i < n; i++){
            cur = gcd(cur, a[i]);
            if (cur != p[i]){
                ok = false;
                break;
            }
        }

        cur = 0;
        for (int i = n - 1; i >= 0 && ok; i--){
            cur = gcd(cur, a[i]);
            if (cur != s[i]){
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }

    return 0;
}