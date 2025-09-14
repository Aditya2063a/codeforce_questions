#include <bits/stdc++.h>
using namespace std;

int n;
string row1, row2;
bool visited[2][200005];

pair<int,int> forcedMove(int r, int c) {
    if ((r == 0 && row1[c] == '>') || (r == 1 && row2[c] == '>'))
        return {r, c+1};
    else
        return {r, c-1};
}

bool dfs(int r, int c) {
    if (r == 1 && c == n-1) return true; // target reached
    if (visited[r][c]) return false;
    visited[r][c] = true;

    // four possible manual moves
    vector<pair<int,int>> moves = {{r, c+1}, {r, c-1}, {r+1, c}, {r-1, c}};
    for (auto [nr, nc] : moves) {
        if (nr < 0 || nr >= 2 || nc < 0 || nc >= n) continue;
        auto [fr, fc] = forcedMove(nr, nc);
        if (fc < 0 || fc >= n) continue; // out of bounds
        if (dfs(fr, fc)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        cin >> n;
        cin >> row1 >> row2;
        memset(visited, 0, sizeof(visited));
        if (dfs(0,0)) cout << "YES\n";
        else cout << "NO\n";
    }
}
