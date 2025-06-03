#include <iostream>
#include <vector>
#include <utility>
#include <cstring> // for memset

// Uncomment the line below to enable debug output
#define DEB

using namespace std;

#ifdef DEB
#define dump(x) cerr << #x << " = " << (x) << endl
#define prl cerr << "called: " << __LINE__ << endl
template <class T>
void debug(T a, T b) {
    for (; a != b; ++a) cerr << *a << ' ';
    cerr << endl;
}
#else
#define dump(x)
#define prl
template <class T>
void debug(T a, T b) {}
#endif

template <class T>
void chmin(T& a, const T& b) { if (a > b) a = b; }

template <class T>
void chmax(T& a, const T& b) { if (a < b) a = b; }

typedef long long lint;
typedef pair<int, int> pi;

ostream& operator<<(ostream& out, const pi& a) {
    out << '(' << a.first << ',' << a.second << ')';
    return out;
}

const int MAXN = 105;
vector<pi> g[MAXN];
int vis[MAXN];
int n, m;

bool dfs(int v, int col, int dst) {
    vis[v] = 1;
    if (v == dst) return true;
    for (const auto& e : g[v]) {
        if (e.second == col && !vis[e.first]) {
            if (dfs(e.first, col, dst)) return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b; --c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    int q;
    cin >> q;
    while (q--) {
        int res = 0;
        int u, v;
        cin >> u >> v;
        --u; --v;
        for (int i = 0; i < 100; ++i) {
            memset(vis, 0, sizeof(vis));
            if (dfs(u, i, v)) ++res;
        }
        cout << res << endl;
    }

    return 0;
}
