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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') pos.push_back(i);
        }
        int m = pos.size();

        if (m <= k) {
            cout << "Alice\n";
            continue;
        }

        bool alice_wins = false;
        int rem = m - k;
        for (int i = 0; i + rem - 1 < m; i++) {
            int j = i + rem - 1;
            int span = pos[j] - pos[i] + 1;
            if (span <= k) {
                alice_wins = true;
                break;
            }
        }

        if (alice_wins) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    return 0;
}
