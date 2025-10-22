#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
typedef long long ll;
typedef pair<ll,int> pli;

bool cmp(pli &a, pli &b) {
    return a.f > b.f;}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pli> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].f;
            v[i].s = i + 1;
        }

        sort(v.begin(), v.end(), cmp);

        vector<ll> res(n + 1, 0);
        ll ans = 0;
        ll left = -1, right = 1;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                res[v[i].s] = right;
                ans += 2LL * v[i].f * right;
                right++;
            } else {
                res[v[i].s] = left;
                ans += 2LL * v[i].f * (-left);
                left--;
            }
        }

        cout << ans << "\n";
        for (int i = 0; i <= n; i++)
            cout << res[i] << " ";
        cout << "\n";
    }
}
