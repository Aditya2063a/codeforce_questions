#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = (ll)1e15;

int n;
vector<int> a;
vector<array<ll,2>> dp;
vector<array<bool,2>> seen;

ll go(int i, int turn) {
    if (i >= n) return 0;          // no bosses left
    if (seen[i][turn]) 
        return dp[i][turn];
    seen[i][turn] = true;
    
    ll &res = dp[i][turn];
    res = INF;
    
    if (turn == 0) {
        res = min(res, (ll)a[i] + go(i+1, 1));
        if (i+1 < n) {
            res = min(res,
                      (ll)a[i] + a[i+1]
                      + go(i+2, 1));
        }
    } else {
        res = min(res, go(i+1, 0));
        if (i+1 < n) {
            res = min(res, go(i+2, 0));
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        dp.assign(n, {0,0});
        seen.assign(n, {false,false});

        // Start at boss 0, friend's turn (turn=0)
        cout << go(0, 0) << '\n';
    }
    return 0;
}
