#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_set<string> poland, enemy;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        poland.insert(s);
    }

    int k = 0; // count common words
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        if (poland.count(s)) k++;
    }

    // PolandBall gets +1 if k is odd
    if (n - k + (k % 2) > m - k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
