#include <bits/stdc++.h>
using namespace std;

double solve(vector<double>& h, int indexH, int indexT, int n, vector<vector<double>>& dp) {
    if(indexH == n) {
        return (indexT > n / 2) ? 0.0 : 1.0;
    }

    if(dp[indexH][indexT] != -1.0) {
        return dp[indexH][indexT];
    }

    double take = h[indexH] * solve(h, indexH + 1, indexT, n, dp);
    double skip = (1.0 - h[indexH]) * solve(h, indexH + 1, indexT + 1, n, dp);

    return dp[indexH][indexT] = take+skip;
}

int main() {
    int n;
    cin >> n;

    vector<double> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1.0));

    double res = solve(h, 0, 0, n, dp);

    cout << fixed << setprecision(9) << res << "\n";

    return 0;
}
