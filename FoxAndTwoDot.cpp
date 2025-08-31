#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

bool isCyclic(vector<vector<char>>& adj, vector<vector<bool>>& visited, int x, int y, int px, int py, char c){
    visited[x][y] = true;
    static const vector<pii> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for(auto& dir : directions){
        int nx = x + dir.first;
        int ny = y + dir.second;
        if(nx >= 0 && nx < adj.size() && ny >= 0 && ny < adj[0].size() && adj[nx][ny] == c){
            if(!visited[nx][ny]){
                if(isCyclic(adj, visited, nx, ny, x, y, c)) return true;
            }else if(!(nx == px && ny == py)){   // visited but not parent
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> adj[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bool result = false;
    for(int i=0; i<n && !result; i++){      // FIXED condition
        for(int j=0; j<m; j++){
            if(!visited[i][j] && isCyclic(adj, visited, i, j, -1, -1, adj[i][j])){
                result = true;
                break;
            }
        }
    }

    cout << (result ? "Yes" : "No") << "\n";
    return 0;
}
