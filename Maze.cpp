#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<string> grid;
vector<vector<int>> vis;
vector<pair<int,int>> order;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    grid.resize(n);
    for (int i=0; i<n; i++) cin >> grid[i];

    vis.assign(n, vector<int>(m,0));

    // Find a starting empty cell
    int sr=-1, sc=-1, s=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j]=='.') {
                s++;
                if (sr==-1) { sr=i; sc=j; }
            }
        }
    }

    // iterative DFS stack
    stack<pair<int,int>> st;
    st.push({sr,sc});
    vis[sr][sc]=1;

    while(!st.empty()) {
        auto [r,c] = st.top(); st.pop();
        order.push_back({r,c});
        for(int d=0; d<4; d++) {
            int nr=r+dr[d], nc=c+dc[d];
            if(nr>=0 && nr<n && nc>=0 && nc<m &&
               !vis[nr][nc] && grid[nr][nc]=='.') {
                vis[nr][nc]=1;
                st.push({nr,nc});
            }
        }
    }

    // turn last k visited into X
    for(int i=0; i<k; i++) {
        auto [r,c] = order[(int)order.size()-1-i];
        grid[r][c] = 'X';
    }

    for (int i=0; i<n; i++) cout << grid[i] << "\n";
}
