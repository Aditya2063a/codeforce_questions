#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;

        int n = a.size();
        int m = b.size();

        // DP table with dimensions (n+1) x (m+1)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
        dp[0][0] = 0;

        // Fill DP table
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i > 0) { // Take a character from `a`
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + (a[i - 1] != c[i + j - 1]));
                }
                if (j > 0) { // Take a character from `b`
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + (b[j - 1] != c[i + j - 1]));
                }
            }
        }

        // Output the result for this test case
        cout << dp[n][m] << endl;
    }
    return 0;
}
