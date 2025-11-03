#include <bits/stdc++.h>
using namespace std;

string encode(int n, const vector<int>& a) {
    string s;
    s.reserve(n);
    for (int x : a) {
        s.push_back('a' + x - 1);
    }
    return s;
}

pair<int, vector<int>> decode(const string& s) {
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - 'a' + 1;
    }
    return {n, a};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string mode;
    cin >> mode;

    if (mode == "first") {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        string s = encode(n, a);
        cout << s << "\n";
    } 
    else if (mode == "second") {
        string s;
        cin >> s;

        auto [n, a] = decode(s);
        cout << n << "\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i];
            if (i + 1 < n) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
