#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

double dfs(int u, int parent, vector<vector<int>>& adjList) {
    int cnt = 0;
    double sum = 0.0;
    for (int v : adjList[u]) {
        if (v == parent) continue; 
        cnt++;
        sum += dfs(v, u, adjList) + 1; 
    }
    if (cnt == 0) return 0.0;
    return sum / cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    
    double ans = dfs(1, 0, adjList);
    
    cout << fixed << setprecision(15) << ans << "\n";
    return 0;
}
