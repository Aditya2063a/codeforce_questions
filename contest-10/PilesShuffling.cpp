#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        int64 ans = 0;
        for (int i = 0; i < n; i++) {
            int64 a, b, c, d;
            cin >> a >> b >> c >> d;

            if (b > d) {
                ans += a + (b - d);
            } else {
                if (a > c) 
                    ans += (a - c);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
