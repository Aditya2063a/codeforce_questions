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

// void dfs(vector<vector<int>>& adjlist, vector<bool>& visited, int node){
//     visited[node]=true;

//     for(auto nbr:adjlist[node]){
//         if(!visited[nbr]){
//             dfs(adjlist, visited, nbr);
//         }
//     }
// }


// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     cin>>tt;
//     while(tt--){
//         int n;
//         cin>>n;
//         vector<int> a(n+1), b(n+1);
//         for(int i=1; i<n+1; i++){
//             cin>>a[i];
//         }

//         for(int i=1; i<n+1; i++){
//             cin>>b[i];
//         }

//         vector<vector<int>> adjlist(n+1);
//         for(int i=1; i<n+1; i++){
//             int m=a[i], n=b[i];
//             adjlist[m].pb(n);
//             adjlist[n].pb(m);
//         }

//         vector<int> d(n+1);
//         for(int i=1; i<n+1; i++){
//             cin>>d[i];
//         }

//         int result=1;

//         vector<bool> visited(n+1, false);
//         for(int i=1; i<n+1; i++){
//             if(d[i]!=0){
//                 dfs(adjlist, visited, d[i]);
//             }else{
//                 if((!visited[a[i]] && !visited[b[i]]) && a[i]!=b[i]){
//                     result*=2;
//                     dfs(adjlist, visited, a[i]);
//                 }
//             }
//         }

//         cout<< result << "\n";

//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1e9+7;

void dfs(int u, vector<bool>& seen, vector<vector<int>>& adj){
    seen[u] = true;
    for(int v : adj[u])
        if(!seen[v])
            dfs(v, seen, adj);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1), d(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        for(int i = 1; i <= n; i++) cin >> d[i];

        // build the “swap” graph on values 1..n
        vector<vector<int>> adj(n+1);
        for(int i = 1; i <= n; i++){
            int u = a[i], v = b[i];
            if(u != v){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        vector<bool> seen(n+1, false);
        // first, “fix” every component that has a forced value
        for(int i = 1; i <= n; i++){
            if(d[i] != 0 && !seen[d[i]]){
                dfs(d[i], seen, adj);
            }
        }

        // every *other* non-trivial component doubles your choices
        long long result = 1;
        for(int v = 1; v <= n; v++){
            if(!seen[v] && !adj[v].empty()){
                result = (result * 2) % MOD;
                dfs(v, seen, adj);
            }
        }

        cout << result << "\n";
    }
    return 0;
}
