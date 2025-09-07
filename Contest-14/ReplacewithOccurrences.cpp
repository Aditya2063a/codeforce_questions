#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define mod 1000000007
#define INF 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[b[i]].push_back(i);
        }

        vector<int> a(n, -1);
        int nextLabel = 1;
        bool ok = true;

        for (auto &p : groups) {
            int val = p.first;
            auto &idx = p.second;

            if ((int)idx.size() % val != 0) {
                ok = false;
                break;
            }

            for (int i = 0; i < (int)idx.size(); i += val) {
                for (int j = 0; j < val; j++) {
                    a[idx[i + j]] = nextLabel;
                }
                nextLabel++;
            }
        }

        if (!ok) {
            cout << -1 << "\n";
        } else {
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}