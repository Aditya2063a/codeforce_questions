#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                for (char ch = 'a'; ch <= 'c'; ch++) {
                    if ((i > 0 && s[i - 1] == ch) || (i + 1 < n && s[i + 1] == ch))
                        continue;
                    s[i] = ch;
                    break;
                }
            }
        }

        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                ok = false;
                break;
            }
        }

        if (ok) cout << s << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
