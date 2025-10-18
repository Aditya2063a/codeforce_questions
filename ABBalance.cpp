#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;

        int ab = 0, ba = 0;
        for (int i = 0; i + 1 < (int)s.size(); i++) {
            if (s[i] == 'a' && s[i + 1] == 'b') ab++;
            if (s[i] == 'b' && s[i + 1] == 'a') ba++;
        }

        if (ab == ba) {
            cout << s << "\n";
            continue;
        }

        if (s.front() != s.back()) {
           s.back() = s.front();
        }

        cout << s << "\n";
    }

    return 0;
}
