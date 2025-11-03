#include <bits/stdc++.h>
using namespace std;

string base26_encode(long long x) {
    if (x == 0) return "a";
    string s;
    while (x > 0) {
        int r = x % 26;
        s.push_back('a' + r);
        x /= 26;
    }
    reverse(s.begin(), s.end());
    return s;
}

long long base26_decode(const string &s) {
    long long val = 0;
    for (char c : s) {
        val = val * 26 + (c - 'a');
    }
    return val;
}

string encode(int n, const vector<long long>& a) {
    string res;
    for (long long x : a) {
        string t = base26_encode(x);
        char len = 'a' + (int)t.size() - 1;  // length prefix (1→'a', 2→'b', etc.)
        res.push_back(len);
        res += t;
    }
    return res;
}

pair<int, vector<long long>> decode(const string& s) {
    vector<long long> a;
    int i = 0;
    while (i < (int)s.size()) {
        int len = s[i] - 'a' + 1;
        string num = s.substr(i + 1, len);
        a.push_back(base26_decode(num));
        i += 1 + len;
    }
    return {(int)a.size(), a};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string mode;
    cin >> mode;

    if (mode == "first") {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << encode(n, a) << "\n";
    } 
    else if (mode == "second") {
        string s;
        cin >> s;
        auto [n, a] = decode(s);
        cout << n << "\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i + 1 == n ? '\n' : ' ');
        }
    }

    return 0;
}
