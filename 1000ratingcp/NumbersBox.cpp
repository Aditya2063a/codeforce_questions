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
        int n,m; cin>>n>>m;
        vector<vector<int>> a(n, vector<int>(m));
        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] < 0) negCount++;
                sum += abs(a[i][j]);
                minAbs = min(minAbs, abs(a[i][j]));
            }
        }

        if (negCount % 2 == 0)
            cout << sum << "\n";
        else
            cout << sum - 2 * minAbs << "\n";

    }
}