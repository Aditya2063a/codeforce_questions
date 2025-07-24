#include <bits/stdc++.h>
using namespace std;

long long solve(vector<vector<long long>>& v, int index, int w, int n, vector<vector<long long>>& dp) {
    if(index == n) return 0;

    if(dp[index][w] != -1) {
        return dp[index][w];
    }

    long long skip = solve(v, index + 1, w, n, dp);
    long long take = LLONG_MIN;

    if(v[index][0] <= w) {
        take = v[index][1] + solve(v, index + 1, w - v[index][0], n, dp);
    }

    return dp[index][w] = max(take, skip);
}

int main() {
    int n, w;
    cin >> n >> w;

    vector<vector<long long>> vec(n, vector<long long>(2));
    for(int i = 0; i < n; i++) {
        cin >> vec[i][0] >> vec[i][1];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(w + 1, -1));

    cout << solve(vec, 0, w, n, dp) << "\n";

    return 0;
}
