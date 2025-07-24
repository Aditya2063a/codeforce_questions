#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int index, int n, int k, vector<int>& dp) {
    if(index == n - 1) return 0;
    if(index >= n) return INT_MAX;

    if(dp[index] != -1) return dp[index];

    int result = INT_MAX;

    for(int i = 1; i <= k; i++) {
        if(index + i < n) {
            int res = abs(v[index] - v[index + i]) + solve(v, index + i, n, k, dp);
            result = min(result, res);
        }
    }

    return dp[index] = result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];

    vector<int> dp(n, -1);

    int res = solve(vec, 0, n, k, dp);

    cout << res << '\n';
}
