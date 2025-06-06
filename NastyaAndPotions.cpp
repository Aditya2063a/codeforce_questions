#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
const ll INF = 1e18;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while(tt--){
        int n, k;
        cin >> n >> k;

        vector<ll> cost(n + 1);
        vector<bool> unlim(n + 1, false);

        for(int i = 1; i <= n; i++){
            cin >> cost[i];
        }

        for(int i = 0; i < k; i++){
            int a;
            cin >> a;
            unlim[a] = true;
            cost[a] = 0; 
        }

        vector<vector<int>> recipe(n + 1);
        vector<vector<int>> graph(n + 1);
        vector<int> indeg(n + 1, 0);

        for(int i = 1; i <= n; i++){
            int m;
            cin >> m;
            recipe[i].resize(m);
            for(int j = 0; j < m; j++){
                cin >> recipe[i][j];
                graph[recipe[i][j]].pb(i);
            }
            indeg[i] = m;
        }

        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front(); q.pop();

            if(!recipe[u].empty()){
                ll sum = 0;
                for(int v : recipe[u]){
                    sum += cost[v];
                }
                cost[u] = min(cost[u], sum);
            }

            for(int v : graph[u]){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }

        for(int i = 1; i <= n; i++){
            cout << cost[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
