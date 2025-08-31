// #include <bits/stdc++.h>
// using namespace std;

// #define f first
// #define s second
// #define pb push_back

// typedef long long int ll;
// typedef unsigned long long int ull;
// typedef pair<int,int> pii;
// typedef pair<ll,ll> pll;

// #define mod 1000000007
// #define INF 1000000000


// void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node, int& count, queue<int>& q){
//     visited[node] = true;
//     count++;
//     q.push(node);
//     for(auto& neighbor : adj[node]){
//         if(!visited[neighbor]){
//             dfs(adj, visited, neighbor, count, q);
//         }
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n+1);
//     vector<vector<int>> a;
//     for(int i=0; i<m; i++){
//         int k;
//         cin >> k;
//         vector<int> temp(k);
//         for(int j=0; j<k; j++){
//             cin >> temp[j];
//         }
//         a.pb(temp);
//     }

//     for(int i=0; i<m; i++){
//         for(int j=0; j<a[i].size(); j++){
//             for(int k=j+1; k<a[i].size(); k++){
//                 adj[a[i][j]].pb(a[i][k]);
//                 adj[a[i][k]].pb(a[i][j]);
//             }
//         }
//     }

//     vector<int> result(n+1, 0);
//     vector<bool> visited(n+1, false);
//     for(int i=1; i<n+1; i++){
//         queue<int> q;
//         int count = 0;
//         if(!visited[i]){
//             dfs(adj, visited, i, count, q);
//         }

//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             result[node] = count;
//         }
//     }

//     for(int i=1; i<=n; i++){
//         cout << result[i] << ' ';
//     }cout << endl;

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n+1);
        sz.assign(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
    int size(int x) {
        return sz[find(x)];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for(int i=0; i<m; i++){
        int k; cin >> k;
        if(k == 0) continue;
        int first; cin >> first;
        for(int j=1; j<k; j++){
            int x; cin >> x;
            dsu.unite(first, x);
        }
    }

    for(int i=1; i<=n; i++){
        cout << dsu.size(i) << " ";
    }
    cout << "\n";
}
