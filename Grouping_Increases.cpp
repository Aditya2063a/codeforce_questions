#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin >> T)) return 0;
    const int INF = 1e9+5;
    while (T--) {
        int n; cin >> n;
        vector<int>a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        int t1 = INF, t2 = INF;
        int ans = 0;
        for (int x : a) {
            if (t1 > t2) swap(t1, t2);
            if (x <= t1) {
                t1 = x;
            } else if (x <= t2) {
                t2 = x;
            } else {
                t1 = x;
                ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
