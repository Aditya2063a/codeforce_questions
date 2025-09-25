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

ll helper(const string &s, char ch) {
    vector<int> pos;

    for (int i = 0; i < s.length(); ++i)
        if (s[i] == ch) pos.pb(i);

    int m = pos.size();
    if (m <= 1) return 0;

    vector<ll> c(m);

    for (int i = 0; i < m; ++i) c[i] = (ll)pos[i] - i;
    int mid = m/2;

    nth_element(c.begin(), c.begin()+mid, c.end());

    ll med = c[mid];
    ll ans = 0;
    for (int i = 0; i < m; ++i) ans += llabs(c[i] - med);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n; 
        cin >> n;
        
        string s; 
        cin >> s;

        cout << min(helper(s, 'a'), helper(s, 'b')) << "\n";
    }
    return 0;
}