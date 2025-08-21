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
    int T; 
    if(!(cin >> T)) return 0;
    while (T--) {
        long long n; 
        cin >> n;
        vector<unsigned long long> ans;
        __int128 p = 10; 
        while (true) {
            __int128 d = p + 1;      
            if (d > n) break;
            if (n % (unsigned long long)d == 0) {
                ans.push_back(n / (unsigned long long)d);
            }
            if (p > (__int128)1e18 / 10) break;
            p *= 10;
        }
        if (ans.empty()) {
            cout << 0 << "\n";
        } else {
            sort(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (size_t i = 0; i < ans.size(); ++i) {
                if (i) cout << ' ';
                cout << ans[i];
            }
            cout << "\n";
        }
    }
}