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

int dfs(int u, vector<int>& badge, vector<bool>& visited){
    if(visited[u]) return u;
    visited[u] = true;
    return dfs(badge[u], badge, visited);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> badge(n+1);
    for(int i=1; i<=n; i++){
        cin >> badge[i];
    }

    
    vector<int> res(n+1);
    for(int i=1; i<n+1; i++){
        vector<bool> visited(n+1, false);
        res[i] = dfs(i, badge, visited);
    }

    for(int i=1; i<=n; i++){
        cout << res[i] << ' ';
    }
}