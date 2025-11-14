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
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<int> nextDiff(n + 1, -1);
        for (int i = n - 1; i >= 1; --i) {
            if (a[i] != a[i + 1]) nextDiff[i] = i + 1;
            else nextDiff[i] = nextDiff[i + 1];
        }

        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            if (nextDiff[l] != -1 && nextDiff[l] <= r)
                cout << l << " " << nextDiff[l] << "\n";
            else
                cout << "-1 -1\n";
        }
        cout << "\n";
    }
}