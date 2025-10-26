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

struct testcase{
    testcase(){
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> b(n);
        for (int i=0; i<n; i++) cin >> b[i];
        sort(b.begin(), b.end(), greater<>());
        ll result = 1;
        for (int i=0; i<n; i++){
            int geq_count = a.size() - (upper_bound(a.begin(), a.end(), b[i]) - a.begin());
            result = result * max(geq_count - i, 0) % mod;
        }
        cout << result << "\n";
    }
};

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) testcase();
}