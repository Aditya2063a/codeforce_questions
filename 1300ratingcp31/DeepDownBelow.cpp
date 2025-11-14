#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pll> caves; 

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            vector<ll> a(k);
            for (int j = 0; j < k; j++) cin >> a[j];

            ll req = 0;
            for (int j = 0; j < k; j++) {
                req = max(req, a[j] - j + 1);
            }

            caves.push_back({req, k});
        }

        sort(caves.begin(), caves.end());

        ll curPower = 0, answer = 0;
        for (auto [req, cnt] : caves) {
            if (curPower < req)
                answer += req - curPower, curPower = req;
            curPower += cnt;
        }

        cout << answer << "\n";
    }
    return 0;
}
