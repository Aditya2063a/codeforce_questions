#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> visited(n + 1, false);
    int cycleComponents = 0;
    
    for (int i = 1; i <= n; i++){
        if (!visited[i]) {
            bool isCycle = true;
            int countNodes = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            
            while (!q.empty()){
                int cur = q.front();
                q.pop();
                countNodes++;
                
                if (adj[cur].size() != 2){
                    isCycle = false;
                }
                
                for (int nb : adj[cur]){
                    if (!visited[nb]){
                        visited[nb] = true;
                        q.push(nb);
                    }
                }
            }
            
            if (isCycle && countNodes >= 3)
                cycleComponents++;
        }
    }
    
    cout << cycleComponents << "\n";
    return 0;
}
