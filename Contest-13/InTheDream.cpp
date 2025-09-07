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

bool valid(int x, int y) {
    return max(x, y) <= 2 * (min(x, y) + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x1 = a, y1 = b;
        int x2 = c - a, y2 = d - b;

        if (valid(x1, y1) && valid(x2, y2)) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}
