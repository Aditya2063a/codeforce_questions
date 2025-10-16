#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;

        if (c == 'g') {
            cout << 0 << "\n";
            continue;
        }

        s += s;  
        int m = s.size();
        int last_g = -1;
        int ans = 0;

        for (int i = m - 1; i >= 0; i--) {
            if (s[i] == 'g') {
                last_g = i;
            }
            if (s[i] == c && last_g != -1) {
                ans = max(ans, last_g - i);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
