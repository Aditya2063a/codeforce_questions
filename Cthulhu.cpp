#include <bits/stdc++.h>
using namespace std;

bool isCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int nbr : adj[node]) {
        if (!visited[nbr]) {
            if (isCycle(nbr, node, adj, visited)) return true;
        } else if (nbr != parent) {
            return true;
        }
    }
    return false;
}

bool isConnected(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    int visitedCount = 0;

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        visitedCount++;

        for (int nbr : adj[curr]) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }

    return visitedCount == n;
}

int main() {
    int n, m;
    cin >> n >> m;

    if (n < 3 || m != n) {
        cout << "NO\n";
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // check if the graph is connected
    if (!isConnected(n, adj)) {
        cout << "NO\n";
        return 0;
    }

    // check if it has exactly one cycle
    vector<bool> visited(n + 1, false);
    if (isCycle(1, -1, adj, visited)) {
        cout << "FHTAGN!\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
