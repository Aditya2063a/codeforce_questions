#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Road {
    int u, v, cost;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<vector<pair<int, pair<int,int>>>> adj(n + 1); 
    vector<Road> roads(n);
    
    for (int i = 0; i < n; i++){
        int u, v, c;
        cin >> u >> v >> c;
        roads[i] = {u, v, c};
        adj[u].push_back({v, {u, c}}); 
        adj[v].push_back({u, {u, c}}); 
    }
    
    vector<int> cycle;
    vector<bool> visited(n+1, false);
    int cur = 1, prev = -1;
    
    while (true) {
        cycle.push_back(cur);
        visited[cur] = true;
        int next = -1;
        for (auto &p : adj[cur]) {
            int nbr = p.first;
            if (nbr == prev) continue;
            next = nbr;
            break;
        }
        if (next == -1) break; 
        if (next == 1) break; 
        prev = cur;
        cur = next;
    }
    
    int totalCost1 = 0, totalCost2 = 0;
    
    vector<vector<int>> flipCost(n+1, vector<int>(n+1, -1));
    for (auto &rd : roads) {
        flipCost[rd.u][rd.v] = rd.cost;
    }
    
    int sz = cycle.size();
    for (int i = 0; i < sz; i++){
        int u = cycle[i];
        int v = cycle[(i+1) % sz];
        if (flipCost[u][v] == -1) {
            totalCost1 += flipCost[v][u];
        }
    }
    
    for (int i = 0; i < sz; i++){
        int u = cycle[i];
        int v = cycle[(i+1) % sz];
        if (flipCost[v][u] == -1) {
            totalCost2 += flipCost[u][v];
        }
    }
    
    cout << min(totalCost1, totalCost2) << "\n";
    return 0;
}
