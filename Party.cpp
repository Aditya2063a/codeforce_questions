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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int k; cin >> k;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<k;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int m; cin >> m;
    vector<pair<int,int>> dislikes(m);
    for(int i=0;i<m;i++){
        cin >> dislikes[i].first >> dislikes[i].second;
    }

    // Step 1: find connected components
    vector<int> comp(n+1,-1);
    int compId=0;
    vector<int> compSize;
    for(int i=1;i<=n;i++){
        if(comp[i]==-1){
            int sz=0;
            queue<int> q; q.push(i);
            comp[i]=compId;
            while(!q.empty()){
                int u=q.front();q.pop();
                sz++;
                for(int v:adj[u]){
                    if(comp[v]==-1){
                        comp[v]=compId;
                        q.push(v);
                    }
                }
            }
            compSize.push_back(sz);
            compId++;
        }
    }

    // Step 2: check dislikes
    vector<bool> valid(compId,true);
    for(auto [u,v]:dislikes){
        if(comp[u]==comp[v]){ // same component -> invalid
            valid[comp[u]]=false;
        }
    }

    // Step 3: take max valid size
    int ans=0;
    for(int id=0;id<compId;id++){
        if(valid[id]) ans=max(ans,compSize[id]);
    }
    cout << ans << "\n";
}
