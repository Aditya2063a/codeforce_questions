#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Map from (i - b[i]) to total beauty sum
    map<ll, ll> sum_by_key;

    for (int i = 0; i < n; i++) {
        ll key = (i + 1) - b[i];
        sum_by_key[key] += b[i];
    }

    ll max_beauty = 0;
    for (auto &p : sum_by_key) {
        max_beauty = max(max_beauty, p.second);
    }

    cout << max_beauty << "\n";

    return 0;
}
