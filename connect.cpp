#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> grid;
vector<vector<int>> comp;
map<int, vector<pair<int,int>>> islands;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int id) {
    stack<pair<int,int>> st;
    st.push({x,y});
    comp[x][y] = id;
    islands[id].push_back({x,y});
    
    while (!st.empty()) {
        auto [cx, cy] = st.top();
        st.pop();
        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (grid[nx][ny] == '0' && comp[nx][ny] == -1) {
                    comp[nx][ny] = id;
                    islands[id].push_back({nx, ny});
                    st.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r1, c1, r2, c2;
    cin >> n;
    cin >> r1 >> c1;
    cin >> r2 >> c2;

    grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    // convert to 0-based
    r1--; c1--;
    r2--; c2--;

    comp.assign(n, vector<int>(n, -1));
    int comp_id = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '0' && comp[i][j] == -1) {
                dfs(i, j, comp_id++);
            }
        }
    }

    int start_island = comp[r1][c1];
    int end_island   = comp[r2][c2];

    if (start_island == end_island) {
        cout << 0 << "\n";
        return 0;
    }

    int ans = INT_MAX;
    for (auto [x1, y1] : islands[start_island]) {
        for (auto [x2, y2] : islands[end_island]) {
            int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            ans = min(ans, d);
        }
    }

    cout << ans << "\n";
    return 0;
}
