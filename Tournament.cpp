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

bool dfs(vector<vector<int>>& adj, int node, int target, vector<bool>& visited){
    if(node == target){
        return true;
    }
    visited[node] = true;
    for(int neighbor : adj[node]){
        if(!visited[neighbor]){
            return dfs(adj, neighbor, target, visited);
        }
    }
    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;
    int m = (n*(n-1))/2 - 1;
    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1, 0);

    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        deg[x]++; deg[y]++;
    }

    // find the two vertices with degree n-2 (they missed one match between them)
    int a=-1, b=-1;
    for(int i=1;i<=n;i++){
        if(deg[i] == n-2){
            if(a == -1) a = i;
            else b = i;
        }
    }

    // topological sort (DFS finishing times)
    vector<char> vis(n+1, 0);
    vector<int> order;
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for(int v: adj[u]){
            if(!vis[v]) dfs(v);
        }
        order.push_back(u);
    };

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    reverse(order.begin(), order.end());
    vector<int> pos(n+1);
    for(int i=0;i<n;i++) pos[order[i]] = i;

    // the one earlier in topo order is the winner (smaller p_j)
    if(pos[a] < pos[b]) cout << a << ' ' << b << '\n';
    else cout << b << ' ' << a << '\n';

    return 0;
}