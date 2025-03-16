#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solveMem(vector<int>& v1, vector<int>& v2, int n, int index, int position, vector<vector<ll>>& dp){
    if(index >= n) return 0;

    if(dp[index][position] != -1) return dp[index][position];

    ll result = 0;
    if(position == 0) {
        ll pick1 = (ll)v1[index] + solveMem(v1, v2, n, index + 1, 2, dp);
        ll pick2 = (ll)v2[index] + solveMem(v1, v2, n, index + 1, 1, dp);
        result = max(pick1, pick2);
    } else if(position == 1) {
        ll pick = (ll)v1[index] + solveMem(v1, v2, n, index + 1, 2, dp);
        ll skip = solveMem(v1, v2, n, index + 1, 1, dp);
        result = max(pick, skip);
    } else {
        ll pick = (ll)v2[index] + solveMem(v1, v2, n, index + 1, 1, dp);
        ll skip = solveMem(v1, v2, n, index + 1, 2, dp);
        result = max(pick, skip);
    }

    ll generalSkip = solveMem(v1, v2, n, index + 1, 0, dp);
    return dp[index][position] = max(result, generalSkip);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> row1(n), row2(n);
    for(int i = 0; i < n; i++) cin >> row1[i];
    for(int i = 0; i < n; i++) cin >> row2[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(3, -1));
    ll result = solveMem(row1, row2, n, 0, 0, dp);

    cout << result << "\n";
    return 0;
}
