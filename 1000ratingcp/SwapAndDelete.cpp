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
        string s;
        cin >> s;
        int n = (int)s.size();
        int cnt0 = 0, cnt1 = 0;
        for (char c : s) if (c == '0') ++cnt0; else ++cnt1;

        int len = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (cnt1 > 0) {
                    --cnt1;
                    ++len;
                } else break;
            } else { // s[i] == '1'
                if (cnt0 > 0) {
                    --cnt0;
                    ++len;
                } else break;
            }
        }
        cout << (n - len) << '\n';
    }
}