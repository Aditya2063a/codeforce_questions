#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    string s;
    cin >> s;

    vector<tuple<char, int, int>> l;
    for (int i = 0; i < n; i++) {
        l.emplace_back(s[i], p[i], i);
    }

    sort(l.begin(), l.end());

    vector<int> q(n, -1);
    for (int i = 0; i < n; i++) {
        q[get<2>(l[i])] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
