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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int &x : v) cin >> x;

        vector<int> prefix(n), suffix(n);
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < n; i++) {
            sum1 += v[i];
            sum2 += v[n - 1 - i];
            prefix[i] = sum1;
            suffix[n - 1 - i] = sum2;
        }

        int l = 0, r = n - 1, ans = 0;
        while (l < r) {
            if (prefix[l] == suffix[r]) {
                ans = max(ans, l + 1 + (n - r));
                l++;
                r--;
            } else if (prefix[l] > suffix[r]) {
                r--;
            } else {
                l++;
            }
        }
        cout << ans << "\n";
    }
}