#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9;

int solve(const vector<pair<int,string>> &nums, int index, int a, int b, int c, int n,
          vector<vector<vector<vector<int>>>> &dp) {
    if(a && b && c) return 0;
    
    if(index == n) return INF;
    
    if(dp[index][a][b][c] != -1) return dp[index][a][b][c];
    
    // Process the current offer:
    int cost = nums[index].first;
    string vit = nums[index].second;
    
    int na = a, nb = b, nc = c;
    for(char ch : vit) {
        if(ch == 'A') na = 1;
        else if(ch == 'B') nb = 1;
        else if(ch == 'C') nc = 1;
    }
    
    int take = cost + solve(nums, index + 1, na, nb, nc, n, dp);
    int skip = solve(nums, index + 1, a, b, c, n, dp);
    
    dp[index][a][b][c] = min(take, skip);
    return dp[index][a][b][c];
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<pair<int, string>> nums(n);
    
    for(int i = 0; i < n; i++){
        int cost;
        string s;
        cin >> cost >> s;
        sort(s.begin(), s.end());
        nums[i] = {cost, s};
    }
    
    vector<vector<vector<vector<int>>>> dp(n+1, 
        vector<vector<vector<int>>>(2, 
            vector<vector<int>>(2, vector<int>(2, -1))));
    
    int ans = solve(nums, 0, 0, 0, 0, n, dp);
    if(ans >= INF) cout << -1 << "\n";
    else cout << ans << "\n";
    
    return 0;
}
