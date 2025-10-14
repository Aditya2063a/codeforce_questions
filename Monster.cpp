#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        ll k;
        cin >> n >> k;

        vector<ll> v(n + 1);
        for (int i = 1; i <= n; i++) cin >> v[i];

        vector<pair<ll,int>> arr; // {rem, index}
        arr.reserve(n);

        for (int i = 1; i <= n; ++i) {
            ll rem = v[i] % k;
            if (rem == 0) rem = k; // treat exact multiples as k
            arr.push_back({rem, i});
        }

        // sort by rem descending, index ascending
        sort(arr.begin(), arr.end(), [](const pair<ll,int>& A, const pair<ll,int>& B) {
            if (A.first == B.first) return A.second < B.second;
            return A.first > B.first; // descending on rem
        });

        for (auto &p : arr) cout << p.second << " ";
        cout << "\n";
    }
    return 0;
}
