// #include <bits/stdc++.h>
// using namespace std;

// void solve(vector<vector<char>>& grid, int i, int j, int x, int y, int& ans){
//     if(i == x - 1 && j == y - 1){
//         ans++;
//         return;
//     }

//     if(i + 1 < x && grid[i + 1][j] == '.'){
//         solve(grid, i + 1, j, x, y, ans);
//     }

//     if(j + 1 < y && grid[i][j + 1] == '.'){
//         solve(grid, i, j + 1, x, y, ans);
//     }
// }

// int main(){
//     int x, y;
//     cin >> x >> y;

//     vector<vector<char>> grid(x, vector<char>(y));
//     for(int i = 0; i < x; i++) {
//         for(int j = 0; j < y; j++) {
//             cin >> grid[i][j];
//         }
//     }

//     int res = 0;
//     if(grid[0][0] == '.' && grid[x-1][y-1] == '.') {
//         solve(grid, 0, 0, x, y, res);
//     }

//     cout << res << "\n";
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;


int solve(vector<vector<char>>& grid, int i, int j, int x, int y, vector<vector<int>>& dp){
    if(i >= x || j >= y || grid[i][j] != '.')
        return 0;

    if(i == x - 1 && j == y - 1)
        return 1;

    if(dp[i][j] != -1)
        return dp[i][j];

    int down = solve(grid, i + 1, j, x, y, dp);
    int right = solve(grid, i, j + 1, x, y, dp);

    return dp[i][j] = (down + right) % MOD;
}

int main(){
    int x, y;
    cin >> x >> y;

    vector<vector<char>> grid(x, vector<char>(y));
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(x, vector<int>(y, -1));
    int res = solve(grid, 0, 0, x, y, dp);

    cout << res << "\n";
    return 0;
}
