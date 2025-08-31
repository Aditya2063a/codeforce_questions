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

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++deg[a]; ++deg[b];
    }

    vector<char> vis(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;

        stack<int> st;
        st.push(i);
        vis[i] = 1;

        long long cnt = 0;        // number of nodes in the component
        long long sumdeg = 0;     // sum of degrees in the component

        while (!st.empty()) {
            int u = st.top(); st.pop();
            ++cnt;
            sumdeg += deg[u];
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    st.push(v);
                }
            }
        }


        if (sumdeg != cnt * (cnt - 1)) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
