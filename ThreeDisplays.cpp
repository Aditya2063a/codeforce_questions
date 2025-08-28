// #include <bits/stdc++.h>
// using namespace std;

// #define INF 1000000000

// int solve(vector<int>& s, vector<int>& c, int n, int index, int prev, int k, vector<vector<vector<int>>>& dp) {
//     if(k == 0) return 0;                 // already picked k elements
//     if(index >= n) return INF;           // no elements left but need more

//     if(dp[index][prev+1][k] != -1)
//         return dp[index][prev+1][k];

//     // Option 1: Skip current element
//     int skip = solve(s, c, n, index+1, prev, k, dp);

//     // Option 2: Take current element (if valid)
//     int take = INF;
//     if(prev == -1 || s[index] > s[prev]) {
//         take = c[index] + solve(s, c, n, index+1, index, k-1, dp);
//     }

//     return dp[index][prev+1][k] = min(skip, take);
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     vector<int> s(n), c(n);
//     for(int i = 0; i < n; i++) cin >> s[i];
//     for(int i = 0; i < n; i++) cin >> c[i];

//     if(n < 3) {
//         cout << -1 << endl;
//         return 0;
//     }

//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1, vector<int>(4, -1)));

//     int result = solve(s, c, n, 0, -1, 3, dp);
//     cout << (result == INF ? -1 : result) << "\n";
// }



#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> s(n), c(n);
    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<n; i++) cin >> c[i];

    if(n < 3) {
        cout << -1 << "\n";
        return 0;
    }

    const int INF = 1e9;
    int ans = INF;

    for(int j = 1; j < n-1; j++) {
        int left = INF, right = INF;

        // find cheapest i < j
        for(int i = 0; i < j; i++) {
            if(s[i] < s[j]) left = min(left, c[i]);
        }

        // find cheapest k > j
        for(int k = j+1; k < n; k++) {
            if(s[j] < s[k]) right = min(right, c[k]);
        }

        if(left != INF && right != INF) {
            ans = min(ans, left + c[j] + right);
        }
    }

    cout << (ans == INF ? -1 : ans) << "\n";
}
