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

const int N = 100005;

int n;
vector<pair<int,int>> g[N]; 
vector<int> ans;

bool dfs(int u, int p) {
    bool hasSelected = false;
    for (auto [v, t] : g[u]) {
        if (v == p) continue;
        bool childHas = dfs(v, u);
        if (t == 2 && !childHas) {
            ans.push_back(v);
            childHas = true;
        }
        if (childHas) hasSelected = true;
    }
    return hasSelected;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        g[x].push_back({y,t});
        g[y].push_back({x,t});
    }

    dfs(1, -1);

    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}