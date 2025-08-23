#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mod 1000000007
#define INF 1000000000

void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& preans){
    int n = grid.size();
    int m = grid[0].size();
    if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] == 0){
        return;
    }
    visited[i][j] = true;
    preans+=grid[i][j];

    dfs(i+1, j, grid, visited, preans);
    dfs(i-1, j, grid, visited, preans);
    dfs(i, j+1, grid, visited, preans);
    dfs(i, j-1, grid, visited, preans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while(tt--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> grid[i][j];
            }
        }

        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int preans = 0;
                if(!visited[i][j]){
                    dfs(i, j, grid, visited, preans);
                    ans = max(ans, preans);
                }
            }
        }

        cout << ans << "\n";
    }    

    return 0;
}