#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int dp[105][3];  // dp[i][prev], prev: 0=rest, 1=contest, 2=sport

int solve(int i, int prev) {
    if (i == n) return 0;
    int &res = dp[i][prev];
    if (res != -1) return res;

    res = 1 + solve(i+1, 0); // option: rest today

    if ((a[i] == 1 || a[i] == 3) && prev != 1) {
        res = min(res, solve(i+1, 1)); // do contest
    }
    if ((a[i] == 2 || a[i] == 3) && prev != 2) {
        res = min(res, solve(i+1, 2)); // do sport
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << "\n";
    return 0;
}
