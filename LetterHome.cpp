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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        int ans = min(abs(s - x[0]), abs(s - x.back())) + x.back() - x[0];
        cout << ans << '\n';
    }
    return 0;
}